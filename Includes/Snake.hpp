/*
** Snake.hpp for nibbler in /home/bajeux_m/Documents/Teck2/cpp/nibbler/cpp_nibbler/Includes
**
** Made by Maxime Bajeux
** Login   <bajeux_m@epitech.net>
**
** Started on  sam. avril 05 03:10:39 2014 Maxime Bajeux
** Last update sam. avril 05 03:10:40 2014 Maxime Bajeux
*/


#ifndef				__SNAKE__
# define			__SNAKE__

# include			<list>
# include			"Item.hpp"

typedef enum			e_direction
{
  UP = 0,
  RIGHT,
  DOWN,
  LEFT,
}				direction;

class				Snake
{
public:				/* CORE */
  Snake();
  ~Snake();

public:				/* GETTERS */
  direction			getDirection() const;

public:				/* FUNCTIONS*/
  const std::list<Item *>	&getSnake() const;
  void				fillSnake(int x, int y);
  void				addQueue(int x, int y);
  void				move();
  void				move_right();
  void				move_left();

private:
  std::list<Item *>		_snake;
  direction			_direction;
    
};

#endif
