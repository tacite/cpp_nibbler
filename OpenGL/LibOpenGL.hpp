/*
** mOpenGL.hh for nibbler in /home/bajeux_m/Documents/Teck2/cpp/nibbler/opengl
**
** Made by Maxime Bajeux
** Login   <bajeux_m@epitech.net>
**
** Started on  mar. avril 01 14:47:49 2014 Maxime Bajeux
** Last update lun. avril 07 00:07:19 2014 Maxime Bajeux
*/

#ifndef LIBOPENGL_H_
# define LIBOPENGL_H_

# include	<SDL/SDL.h>
# include	<GL/gl.h>
# include	<GL/glu.h>
# include	"../Includes/IGraph.hpp"
# include	<iostream>
# include	<string>
# include	<vector>
# include	<map>
# include	"Pave.hpp"
# include	"Texture.hpp"

class LibOpenGL : public IGraph
{
public:
  LibOpenGL();
 ~LibOpenGL();

 void	draw(const std::vector< std::vector<item_type> >&);
 void	event(int&);
 void	init(int x, int y);
 void	finish(const std::string);
  
private:
  void	draw_background();
  void	draw1();
  void	draw_snake_and_food(const std::vector< std::vector<item_type> >&);

  std::map<std::string, std::map<std::string, Texture> >		_tex;
  int	_x;
  int	_y;
  std::vector< std::vector<item_type> > _map;
  GLuint	_bg;
};

#endif /* LIBOPENGL_H_ */
