/*
** Core.hh for nibbler in /home/bajeux_m/Documents/Teck2/cpp/nibbler/cpp_nibbler/Core
**
** Made by Maxime Bajeux
** Login   <bajeux_m@epitech.net>
**
** Started on  ven. avril 04 14:02:43 2014 Maxime Bajeux
** Last update dim. avril 06 01:21:45 2014 Maxime Bajeux
*/

#ifndef		CORE_H_
# define	CORE_H_

# include	<string>
# include	<iostream>
# include	<pthread.h>

# include	"Game.hpp"
# include	"IGraph.hpp"

class Core
{
public:
  Core(Game*, IGraph*);
  ~Core();

  void		init();
  void		libEvent();
  static void		*loop(void *);
  int		_dir;

private:
  Game		*_game;
  IGraph	*_lib;
  std::vector< std::vector<item_type> >	_map;
  pthread_t	_loop;
private:
  void		initMap();
  void		clearMap();
  void		fillMap();
};

#endif /* CORE_H_ */
