/*
** Core.cpp for nibbler in /home/bajeux_m/Documents/Teck2/cpp/nibbler/cpp_nibbler/Core
**
** Made by Maxime Bajeux
** Login   <bajeux_m@epitech.net>
**
** Started on  ven. avril 04 14:02:54 2014 Maxime Bajeux
** Last update ven. avril 11 15:05:38 2014 Maxime Bajeux
*/

#include	<unistd.h>
#include	"Exceptions.hpp"
#include	"Core.hpp"
#include	<vector>

Core::Core(Game *game, IGraph *lib) : _game(game) , _lib(lib)
{
  _dir = 0;
}

Core::~Core() {}

void		Core::init()
{
  _lib->init(_game->getX(), _game->getY());
  this->initMap();
  this->clearMap();
  this->fillMap();
  _lib->draw(_map);
  if (pthread_create(&this->_loop, NULL, Core::loop, this) != 0)
   throw GameException("Failed to create thread");
}

void		Core::libEvent()
{
  _lib->event(this->_dir);
  pthread_join(_loop, NULL);
}

void		*Core::loop(void *attr)
{
  Core		*th = static_cast<Core*>(attr);

  while (th->_game->checkCollisions())
    {
      th->clearMap();
      th->fillMap();
      th->_lib->draw(th->_map);
      if (th->_dir == 1)
        th->_game->getSnake()->move_left();
      else if (th->_dir == 2)
        th->_game->getSnake()->move_right();
      th->_dir = 0;
      th->_game->move();
      usleep(200000);
    }
  th->_lib->finish("You failed, YOU LOSE !");
  return NULL;
}

void		Core::initMap()
{
  std::vector<item_type> toto(this->_game->getX(), NONE);
  
  this->_map = std::vector< std::vector<item_type> > (this->_game->getY(), toto);
}

void		Core::clearMap()
{
  int		a = 0, b = 0;
  
  while (a < this->_game->getY())
  {
    b = 0;
    while (b < this->_game->getX())
    {
      this->_map[a][b++] = NONE;
    }
    a++;
  }
}

void		Core::fillMap()
{
  std::list<Item *>::const_iterator	it;
  
  for(it = this->_game->getSnake()->getSnake().begin(); it != this->_game->getSnake()->getSnake().end(); ++it)
  {
      this->_map[(*it)->getY()][(*it)->getX()] = (*it)->getType();
  }
  this->_map[this->_game->getFood()->getFood()->getY()][this->_game->getFood()->getFood()->getX()] = this->_game->getFood()->getFood()->getType();
}
