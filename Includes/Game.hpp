/*
** Game.hpp for nibbler in /home/bajeux_m/Documents/Teck2/cpp/nibbler/cpp_nibbler/Includes
**
** Made by Maxime Bajeux
** Login   <bajeux_m@epitech.net>
**
** Started on  sam. avril 05 03:09:44 2014 Maxime Bajeux
// Last update Sat Apr  5 17:35:04 2014 Olivier STURBOIS
*/

#ifndef			__GAME_HPP__
# define		__GAME_HPP__

# define		MAX_VALUES (50)
# define		MIN_VALUES (8)

# include		<string>
# include		"Snake.hpp"
# include		"Food.hpp"
# include		"IGraph.hpp"

class			Game {
public:			/*CORE */
  Game();
  ~Game();

public:			/* GETTERS */
  int			getX(void) const;
  int			getY(void) const;
  const std::string	&getLibName(void) const;
  Snake			*getSnake() const;
  Food			*getFood() const;
  
public:			/* SETTERS */
  void			setXY(int x, int y);
  void			setLibName(const std::string &libName);

public:			/* FUNCTIONS*/
  void			parseArgs(const std::string &argX, const std::string &argY, const std::string &libName);
  bool			detectFood() const;
  void			snakeEat(int x, int y);
  void			move();
  bool			checkCollisions() const;
  bool			checkWalls() const;
  bool			checkSnake() const;
  
private:		/* MEMBERS */
  Snake			*_snake;
  Food			*_food;
  IGraph		*_graph;
  int			_x;
  int			_y;
  std::string		_libName;
};

#endif			/* __GAME_HPP__ */
