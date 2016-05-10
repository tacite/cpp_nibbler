//
// LibNcurses.hpp for LibNcurses in /home/sturbo_o/depot_git/cpp_nibbler/Ncurses
// 
// Made by Olivier STURBOIS
// Login   <sturbo_o@epitech.net>
// 
// Started on  Sat Apr  5 15:44:38 2014 Olivier STURBOIS
// Last update Sat Apr  5 17:32:33 2014 Olivier STURBOIS
//

#ifndef			__LIBNCURSES_HPP__
# define		__LIBNCURSES_HPP__

# include		<map>
# include		<iostream>
# include		<ncurses.h>
# include		"../Includes/IGraph.hpp"

class			LibNcurses : public IGraph {
public:			/* CORE */
  LibNcurses();
  virtual ~LibNcurses();
  
public:			/* FUNCTIONS */
  void			draw(const std::vector< std::vector<item_type> >&);
  void			event(int &ptr);
  void			init(int width, int height);
  void			createNewWin(int, int);
  void			displayElements(const char *, int ,int);
  void			finish(const std::string);
  
private:
  WINDOW		*_win;
  int			x_max;
  int			y_max;
  std::map<item_type, const char *>	_textures;  
};

#endif			/* __LIBNCURSES_HPP__ */
