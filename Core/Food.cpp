//
// Food.cpp for Food in /home/sturbo_o/depot_git/cpp_nibbler
// 
// Made by Olivier STURBOIS
// Login   <sturbo_o@epitech.net>
// 
// Started on  Fri Apr  4 15:07:08 2014 Olivier STURBOIS
// Last update Fri Apr  4 15:07:11 2014 Olivier STURBOIS
//

#include	<iostream>
#include	"Food.hpp"
#include	"time.h"
#include	"stdlib.h"

Food::Food(int Xmax, int Ymax)
{
  srand(time(NULL));
  
  this->_food = new Item(rand() % Xmax, rand() % Ymax, FOOD);
  this->_nbr = 0;
    
}

void		Food::changeFood(int Xmax, int Ymax)
{
  delete(this->_food);
  int		x, y;
  
  x = rand() % Xmax;
  y = rand() % Ymax;
  
  this->_food = new Item(x, y, FOOD);
  this->_nbr++;
}

Item		*Food::getFood() const
{
    return(this->_food);
}

Food::~Food()
{ 
}
