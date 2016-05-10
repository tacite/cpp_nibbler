//
// LibNcurses.cpp for LibNcurses in /home/sturbo_o/depot_git/cpp_nibbler/Ncurses
// 
// Made by Olivier STURBOIS
// Login   <sturbo_o@epitech.net>
// 
// Started on  Sat Apr  5 15:44:48 2014 Olivier STURBOIS
// Last update Sat Apr  5 17:33:23 2014 Olivier STURBOIS
//

#include		<unistd.h>
#include		<cstdlib>
#include		"LibNcurses.hpp"

extern "C" IGraph	*loadLibrary() {
  return new LibNcurses();
}

extern "C" void		unloadLibrary(IGraph *lib) {
  delete lib;
}

LibNcurses::LibNcurses() {
}

LibNcurses::~LibNcurses() {
  delwin(this->_win);
  endwin();
}


void			LibNcurses::createNewWin(int height, int width) {
 this->_win = newwin(height + 2, width + 2, 0, 0);
 box(this->_win, 0, 0);
 wrefresh(this->_win);
}

void			LibNcurses::init(int width, int height)
{
  this->x_max = width;
  this->y_max = height;
  this->_textures[HEAD] = "X";
  this->_textures[BACK] = "x";
  this->_textures[BODY] = "x";
  this->_textures[FOOD] = "O";
  initscr();
  cbreak();
  keypad(stdscr, true);
  noecho();
  curs_set(0);
  refresh();
}

void			LibNcurses::displayElements(const char* tex, int x, int y) {
  mvwprintw(this->_win, y + 1, x + 1, tex);
}

void			LibNcurses::draw(const std::vector< std::vector< item_type > > &map) {
  int			x;
  int			y;

  y = 0;
  createNewWin(this->y_max, this->x_max);
  wrefresh(this->_win);
  while (y < this->y_max)
  {
    x = 0;
    while (x < this->x_max)
      {
	if (map[y][x] != NONE)
	  this->displayElements(this->_textures[map[y][x]], x, y);
	x++;
      }
    y++;
  }
  wrefresh(this->_win);
}

void LibNcurses::finish(const std::string msg) {
  keypad(stdscr, false);
  delwin(this->_win);
  endwin();
  std::cerr << msg << std::endl;
  exit(EXIT_SUCCESS);
}


void			LibNcurses::event(int& ptr) {
  int			tmp;
  while (42)
  {
    tmp = getch();
    if (tmp == KEY_LEFT)
      ptr = 1;
    else if (tmp == 27)
      {
	keypad(stdscr, false);
	delwin(this->_win);
	endwin();
	std::cerr << "You left the game !" << std::endl;
	exit(EXIT_SUCCESS);
      }
     else if (tmp == KEY_RIGHT)
      ptr = 2;
    wrefresh(this->_win);
    usleep(90000);
  }
}