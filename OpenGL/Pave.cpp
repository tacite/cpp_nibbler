/*
** Pave.cpp for nibbler in /home/bajeux_m/Documents/Teck2/cpp/nibbler/opengl
**
** Made by Maxime Bajeux
** Login   <bajeux_m@epitech.net>
**
** Started on  mar. avril 01 16:54:02 2014 Maxime Bajeux
** Last update sam. avril 05 23:00:33 2014 Maxime Bajeux
*/

#include	"Pave.hpp"

Pave::Pave(int posx, int posy, int posz, int sizex, int sizey, int sizez, std::map<std::string, Texture> tex) :
  _posx(posx), _posy(posy), _posz(posz), _sizex(sizex), _sizey(sizey), _sizez(sizez), _tex(tex)
{

}

Pave::~Pave() {}

void    Pave::setpos(int x, int y, int z)
{
  _posx = x;
  _posy = y;
  _posz = z;
}

void	Pave::draw()
{
  glTranslated(_posx*2, _posy*2, _posz*2);

  _tex["top"].load();
  glBegin(GL_QUADS);
  glTexCoord2d(1,0); glVertex3d(-_sizex, -_sizey, _sizez); //face top
  glTexCoord2d(0,0); glVertex3d(_sizex, -_sizey , _sizez);
  glTexCoord2d(0,1); glVertex3d(_sizex, _sizey, _sizez);
  glTexCoord2d(1,1); glVertex3d(-_sizex, _sizey, _sizez);
  glEnd();

  _tex["bottom"].load();
  glBegin(GL_QUADS);
  glTexCoord2d(1,0); glVertex3d(-_sizex, -_sizey, -_sizez); //face bottom
  glTexCoord2d(0,0); glVertex3d(_sizex, -_sizey, -_sizez);
  glTexCoord2d(0,1); glVertex3d(_sizex, _sizey, -_sizez);
  glTexCoord2d(1,1); glVertex3d(-_sizex, _sizey, -_sizez);
  glEnd();

  _tex["front"].load();
  glBegin(GL_QUADS);
  glTexCoord2d(1,0); glVertex3d(-_sizex, _sizey, _sizez); //face front
  glTexCoord2d(0,0); glVertex3d(_sizex, _sizey, _sizez);
  glTexCoord2d(0,1); glVertex3d(_sizex, _sizey, -_sizez);
  glTexCoord2d(1,1); glVertex3d(-_sizex, _sizey, -_sizez);
  glEnd();

  _tex["back"].load();
  glBegin(GL_QUADS);
  glTexCoord2d(1,0); glVertex3d(-_sizex, -_sizey, _sizez); //face back
  glTexCoord2d(0,0); glVertex3d(_sizex, -_sizey, _sizez);
  glTexCoord2d(0,1); glVertex3d(_sizex, -_sizey, -_sizez);
  glTexCoord2d(1,1); glVertex3d(-_sizex, -_sizey, -_sizez);
  glEnd();

  _tex["left"].load();
  glBegin(GL_QUADS);
  glTexCoord2d(1,0); glVertex3d(-_sizex, -_sizey, _sizez); //face left
  glTexCoord2d(0,0); glVertex3d(-_sizex, _sizey, _sizez);
  glTexCoord2d(0,1); glVertex3d(-_sizex, _sizey, -_sizez);
  glTexCoord2d(1,1); glVertex3d(-_sizex, -_sizey, -_sizez);
  glEnd();

  _tex["right"].load();
  glBegin(GL_QUADS);
  glTexCoord2d(1,0); glVertex3d(_sizex, _sizey, _sizez); //face right
  glTexCoord2d(0,0); glVertex3d(_sizex, -_sizey, _sizez);
  glTexCoord2d(0,1); glVertex3d(_sizex, -_sizey, -_sizez);
  glTexCoord2d(1,1); glVertex3d(_sizex, _sizey, -_sizez);
  glEnd();

  glTranslated(-_posx*2, -_posy*2, -_posz*2);
}
