/*
** main.cpp for main in /home/tacite_d/Projet/C++/cpp_nibbler
** 
** Made by tacite_d
** Login   <tacite_d@Akagouan>
** 
** Started on  Mon Mar 31 14:16:23 2014 tacite_d
// Last update Sat Apr  5 22:11:28 2014 Olivier STURBOIS
*/


#include	<iostream>
#include	"Item.hpp"
#include	"Snake.hpp"
#include	"LibHandler.hpp"
#include	"Exceptions.hpp"
#include	"Game.hpp"
#include	"IGraph.hpp"
#include	"Core.hpp"

int		main(int ac, char **av)
{
  try {
    if (ac == 4)
      {
       Game	*game = new Game();
       game->parseArgs(av[1], av[2], av[3]);
       LibHandler *lhd = new LibHandler(game->getLibName());
       IGraph	*(*ptr)(void);
       ptr = lhd->getFunction<IGraph*(void)>("loadLibrary");
       IGraph *lib = ptr();
       Core  *core = new Core(game, lib);
       core->init();
       core->libEvent();
      }
    else
      throw GameException("Usage : ./nibbler [x] [y] [lib]");
  }
  catch (const std::exception &exception) {
    std::cerr << "Error : " << exception.what() << std::endl;
  }
  return (0);
}
