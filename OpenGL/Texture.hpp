/*
** Texture.hh for nibbler in /home/bajeux_m/Documents/Teck2/cpp/nibbler/opengl
**
** Made by Maxime Bajeux
** Login   <bajeux_m@epitech.net>
**
** Started on  mar. avril 01 19:32:19 2014 Maxime Bajeux
** Last update sam. avril 05 23:16:19 2014 Maxime Bajeux
*/

#ifndef TEXTURE_H_
# define TEXTURE_H_


extern "C"

{

# include	<GL/gl.h>
# include	<GL/glu.h>
# include	<SOIL/SOIL.h>

}

# include	<iostream>
# include	<string>


class Texture
{
public:
  Texture();
  Texture(const std::string&, int, int);
  ~Texture();

  void	set(const Texture);
  void	load();

private:  
  GLuint _tex;
};

#endif /* TEXTURE_H_ */
