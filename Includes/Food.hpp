//
// Food.hpp for Food in /home/sturbo_o/depot_git/cpp_nibbler
// 
// Made by Olivier STURBOIS
// Login   <sturbo_o@epitech.net>
// 
// Started on  Fri Apr  4 15:08:31 2014 Olivier STURBOIS
// Last update Fri Apr  4 15:08:47 2014 Olivier STURBOIS
//

#ifndef			__FOOD__
# define		__FOOD__

# include		"Item.hpp"

class			Food
{
private:
  Item			*_food;
  int			_nbr;
  
public:
  Food(int Xmax, int Ymax);
  ~Food();
  void			changeFood(int Xmax, int Ymax);
  Item			*getFood() const;
};

#endif
