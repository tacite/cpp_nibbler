/*
** Igraph.hpp for nibbler in /home/sturbo_o/depot_git/cpp_nibbler/Includes
**
** Made by Olivier STURBOIS
** Login   <bajeux_m@epitech.net>
**
** Started on  Thu Apr  3 15:46:58 2014 Olivier STURBOIS
** Last update dim. avril 06 01:26:59 2014 Maxime Bajeux
*/

#ifndef		__IGRAPH__
# define	__IGRAPH__

# include	"Item.hpp"
# include	<vector>

class		IGraph
{
public:
  virtual ~IGraph() {};

public:
  virtual void	draw(const std::vector< std::vector<item_type> >& map) = 0;
  virtual void	event(int &nbr) = 0;
  virtual void	init(int width, int height) = 0;
  virtual void	finish(const std::string) = 0;

};

#endif		/* __IGRAPH__ */
