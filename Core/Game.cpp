/*
** Game.cpp for nibbler in /home/bajeux_m/Documents/Teck2/cpp/nibbler/cpp_nibbler/Core
**
** Made by Maxime Bajeux
** Login   <bajeux_m@epitech.net>
**
** Started on  sam. avril 05 00:50:56 2014 Maxime Bajeux
// Last update Sun Apr  6 22:10:50 2014 Olivier STURBOIS
*/

#include				<cstdlib>
#include				<string>
#include				<sstream>
#include				"Game.hpp"
#include				"Exceptions.hpp"
#include				"LibHandler.hpp"
#include				"IGraph.hpp"

Game::Game() {
  this->_snake = new Snake();
  this->_food = new Food(10, 10);
}

Game::~Game() { 
}


int					Game::getX(void) const {
  return this->_x;
}

int					Game::getY(void) const {
  return this->_y;
}

const std::string			&Game::getLibName(void) const {
  return this->_libName;
}

void					Game::setXY(int x, int y) {
  this->_x = x;
  this->_y = y;
}

void					Game::setLibName(const std::string &libName) {
  this->_libName = libName;
}

void					Game::parseArgs(const std::string &argX, const std::string &argY, const std::string &argLibName) {
  unsigned int				i;
  std::stringstream			ss;

  i = 0;
  while (i < argX.length())
    {
      if (argX[i] < '0' || argX[i] > '9')
	throw GameException("First argument must be a positive integer");
      i++;
    }
  i = 0;
  while (i < argY.length())
    {
      if (argY[i] < '0' || argY[i] > '9')
	throw GameException("Second argument must be a positive integer");
      i++;
    }
  if (atoi(argX.c_str()) < MIN_VALUES || atoi(argX.c_str()) > MAX_VALUES)
    {
      ss << "First argument must be >= " << MIN_VALUES << " and =< " << MAX_VALUES;
      throw GameException(ss.str());
    }
  if (atoi(argY.c_str()) < MIN_VALUES || atoi(argY.c_str()) > MAX_VALUES)
    {
      ss << "Second argument must be >= " << MIN_VALUES << " and =< " << MAX_VALUES;
      throw GameException(ss.str());
    }
  this->setXY(atoi(argX.c_str()), atoi(argY.c_str()));
  this->setLibName(argLibName);
  this->_food->changeFood(this->_x, this->_y);
  this->_snake->fillSnake(this->_x, this->_y);
}

bool					Game::checkWalls() const {
  std::list< Item * >::const_iterator	it = this->_snake->getSnake().begin();

  if ((*it)->getX() == -1 || (*it)->getX() == (this->_x))
    return false;
  else if ((*it)->getY() == -1 || (*it)->getY() == (this->_y))
    return false;
  return true;
}

bool					Game::checkSnake() const {
  std::list< Item * >::const_iterator	it = this->_snake->getSnake().begin();
  std::list< Item * >::const_iterator	tmp = this->_snake->getSnake().begin();
  
  tmp++;
  while (tmp != this->_snake->getSnake().end())
    {
      if ((*tmp)->getX() == (*it)->getX() && (*tmp)->getY() == (*it)->getY())
	return false;
      tmp++;
    }
  return true;
}

bool					Game::checkCollisions() const {
  if (!this->checkWalls())
    return false;
  if (!this->checkSnake())
    return false;
  return true;
}

Snake					*Game::getSnake() const
{
    return(this->_snake);
}

Food					*Game::getFood() const
{
    return(this->_food);
}

bool					Game::detectFood() const
{
    std::list<Item *>::const_iterator it = this->_snake->getSnake().begin();
    
    if ((*it)->getX() == this->_food->getFood()->getX() && (*it)->getY() == this->_food->getFood()->getY())
      return(true);
    return(false);
}

void					Game::snakeEat(int x, int y)
{
  this->_snake->addQueue(x, y);
}

void          Game::move()
{
  std::list<Item *>::const_iterator	it;
  _snake->move();
  this->checkCollisions();
  if (this->detectFood())
  {
    for(it  = this->_snake->getSnake().begin(); it != --this->_snake->getSnake().end(); ++it);
    this->snakeEat((*it)->getX(), (*it)->getY());
    this->getFood()->changeFood(this->_x, this->_y);
  }
}
