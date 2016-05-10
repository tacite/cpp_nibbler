/*
** Texture.cpp for nibbler in /home/bajeux_m/Documents/Teck2/cpp/nibbler/opengl
**
** Made by Maxime Bajeux
** Login   <bajeux_m@epitech.net>
**
** Started on  mar. avril 01 19:32:25 2014 Maxime Bajeux
** Last update sam. avril 05 20:03:06 2014 Maxime Bajeux
*/

#include	"Texture.hpp"

Texture::Texture() {}

Texture::Texture(const std::string &name, int width, int height)
{
  glGenTextures(1, &_tex);
  glBindTexture(GL_TEXTURE_2D, _tex);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  unsigned char *image = SOIL_load_image(name.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
	       GL_UNSIGNED_BYTE, image);
  SOIL_free_image_data(image);
}

Texture::~Texture() {}

void	Texture::set(const Texture texhandler)
{
  _tex = texhandler._tex;
}

void	Texture::load()
{
  glBindTexture( GL_TEXTURE_2D, _tex);
}
