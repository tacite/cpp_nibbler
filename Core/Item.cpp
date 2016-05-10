//
// Item.cpp for Item in /home/sturbo_o/depot_git/cpp_nibbler/Core
// 
// Made by Olivier STURBOIS
// Login   <sturbo_o@epitech.net>
// 
// Started on  Thu Apr  3 15:53:30 2014 Olivier STURBOIS
// Last update Thu Apr  3 17:53:39 2014 Olivier STURBOIS
//

#include	<iostream>
#include	<string>
#include	"Item.hpp"

Item::Item(int x, int y, item_type type)
: _type (type), _pos(x, y) {
}

Item::~Item()
{
}

int		Item::getX() const
{
  return(this->_pos.first);
}

int		Item::getY() const
{
  return(this->_pos.second);
}

item_type	Item::getType() const
{
  return(this->_type);
}

void		Item::setType(item_type type)
{
  this->_type = type;
}
