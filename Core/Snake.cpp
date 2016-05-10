/*
** Snake.cpp for nibbler in /home/bajeux_m/Documents/Teck2/cpp/nibbler/cpp_nibbler/Core
**
** Made by Maxime Bajeux
** Login   <bajeux_m@epitech.net>
**
** Started on  sam. avril 05 03:10:56 2014 Maxime Bajeux
// Last update Sat Apr  5 22:08:45 2014 Olivier STURBOIS
*/

#include			<iostream>
#include			"Item.hpp"
#include			"Snake.hpp"

Snake::Snake()
: _direction(UP) {
}

Snake::~Snake()
{
}

void				Snake::fillSnake(int x, int y)
{
  int				newX = x / 2;
  int				newY = y / 2;
  
  this->_snake.push_front(new Item(newX, newY + 3, BACK));
  this->_snake.push_front(new Item(newX, newY + 2, BODY));
  this->_snake.push_front(new Item(newX, newY + 1, BODY));
  this->_snake.push_front(new Item(newX, newY, HEAD));
}

const std::list< Item* >&	Snake::getSnake() const
{
  return(this->_snake);
}

direction			Snake::getDirection() const
{
  return(this->_direction);
}

void				Snake::move()
{
  this->_snake.pop_back();

  std::list<Item *>::iterator it;
  
  it = this->_snake.begin();
  if (this->_direction == UP)
    this->_snake.push_front(new Item((*it)->getX(), (*it)->getY() - 1, HEAD));
  if (this->_direction == RIGHT)
    this->_snake.push_front(new Item((*it)->getX() + 1, (*it)->getY(), HEAD));
  if (this->_direction == DOWN)
    this->_snake.push_front(new Item((*it)->getX(), (*it)->getY() + 1, HEAD));
  if (this->_direction == LEFT)
    this->_snake.push_front(new Item((*it)->getX() - 1, (*it)->getY(), HEAD));
}

void				Snake::move_left()
{
  if (this->_direction == UP)
    this->_direction = LEFT;
  else if (this->_direction == LEFT)
    this->_direction = DOWN;
  else if (this->_direction == DOWN)
    this->_direction = RIGHT;
  else
    this->_direction = UP;
}

void				Snake::move_right()
{ 
  if (this->_direction == UP)
    this->_direction = RIGHT;
  else if (this->_direction == RIGHT)
    this->_direction = DOWN;
  else if (this->_direction == DOWN)
    this->_direction = LEFT;
  else
    this->_direction = UP;
}

void				Snake::addQueue(int x, int y)
{
  std::list<Item *>::iterator 		it;
  
  for(it = this->_snake.begin(); it != --this->_snake.end(); ++it);
  (*it)->setType(BODY);
  this->_snake.push_back(new Item(x, y, BACK));
}
