/*
** mOpenGL.cpp for nibbler in /home/bajeux_m/Documents/Teck2/cpp/nibbler/opengl
**
** Made by Maxime Bajeux
** Login   <bajeux_m@epitech.net>
**
** Started on  mar. avril 01 14:47:59 2014 Maxime Bajeux
** Last update ven. avril 11 15:04:20 2014 Maxime Bajeux
*/

#include	"LibOpenGL.hpp"

extern "C" IGraph		*loadLibrary()
{
  return new LibOpenGL();
}

extern "C" void		unloadLibrary(IGraph *lib)
{
  delete lib;
}

LibOpenGL::LibOpenGL()
{
}

LibOpenGL::~LibOpenGL()
{
  SDL_Quit();
}

void	LibOpenGL::init(int x, int y)
{
  this->_x = x;
  this->_y = y;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Nibbler", NULL);
  SDL_SetVideoMode(720, 520, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, 1.3, 1, 10000);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  Texture		stone("Textures/stonebrick.bmp", 64, 64);
  Texture		planks("Textures/planks_oak.bmp", 64, 64);
  Texture		cake_top("Textures/cake_top.bmp", 64, 64);
  Texture		cake_bottom("Textures/cake_bottom.bmp", 64, 64);
  Texture		cake_side("Textures/cake_side.bmp", 64, 32);
  Texture		body1("Textures/body1.bmp", 64, 64);
  Texture		body2("Textures/stonebrick.bmp", 32, 64);
  Texture		grass("Textures/grass.bmp", 64, 64);

  _tex["stone"]["top"].set(stone);
  _tex["stone"]["bottom"].set(stone);
  _tex["stone"]["front"].set(stone);
  _tex["stone"]["back"].set(stone);
  _tex["stone"]["left"].set(stone);
  _tex["stone"]["right"].set(stone);

  _tex["wood"]["top"].set(planks);
  _tex["wood"]["bottom"].set(planks);
  _tex["wood"]["front"].set(planks);
  _tex["wood"]["back"].set(planks);
  _tex["wood"]["left"].set(planks);
  _tex["wood"]["right"].set(planks);

  _tex["cake"]["top"].set(cake_top);
  _tex["cake"]["bottom"].set(cake_bottom);
  _tex["cake"]["front"].set(cake_side);
  _tex["cake"]["back"].set(cake_side);
  _tex["cake"]["left"].set(cake_side);
  _tex["cake"]["right"].set(cake_side);

  _tex["body1"]["top"].set(body1);
  _tex["body1"]["bottom"].set(body1);
  _tex["body1"]["front"].set(body1);
  _tex["body1"]["back"].set(body1);
  _tex["body1"]["left"].set(body1);
  _tex["body1"]["right"].set(body1);

  _tex["body2"]["top"].set(body2);
  _tex["body2"]["bottom"].set(body2);
  _tex["body2"]["front"].set(body2);
  _tex["body2"]["back"].set(body2);
  _tex["body2"]["left"].set(body2);
  _tex["body2"]["right"].set(body2);

  _tex["grass"]["top"].set(grass);

  _bg = glGenLists(1);

  glNewList(_bg, GL_COMPILE);
  this->draw_background();
  glEndList();
}

void	LibOpenGL::event(int &dir)
{
  SDL_Event	event;

  while (1)
  {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
      exit(0);
    if (event.type == SDL_KEYDOWN)
    {
      if (event.key.keysym.sym == SDLK_LEFT)
        dir = 1;
      if (event.key.keysym.sym == SDLK_RIGHT)
        dir = 2;
      if (event.key.keysym.sym == SDLK_ESCAPE)
        exit(0);
    }
    this->draw1();
  }
}

void	LibOpenGL::draw1()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  if (_x > _y)
    gluLookAt(_x*64, (_y+1)*128, _x*128, _x*64, _y*64, 0, 0, 0, 1);
  else
    gluLookAt(_x*64, (_y+1)*128, _y*128, _x*64, _y*64, 0, 0, 0, 1);
  glCallList(_bg);
  this->draw_snake_and_food(_map);
  glFlush();
  SDL_GL_SwapBuffers();
}

void  LibOpenGL::draw(const std::vector< std::vector<item_type> > &map)
{
  _map = map;
}

void	LibOpenGL::draw_background()
{
  Pave 	ground(0, 0, 0, 64, 64, 64, _tex["stone"]);
  Pave 	wall(0, 0, 0, 64, 64, 64, _tex["wood"]);
  Pave 	body2(0, 0, 0, 8, 32, 16, _tex["body2"]);

  glTranslated(-_x*320, -_y*320, 0);
  _tex["grass"]["top"].load();
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0);
  glVertex3d(0, 0, 0);
  glTexCoord2d(_x*5, 0);
  glVertex3d(_x*640, 0, 0);
  glTexCoord2d(_x*5, _y*5);
  glVertex3d(_x*640, _y*640,0);
  glTexCoord2d(0, _y*5);
  glVertex3d(0, _y*640,0);
  glEnd();
  glTranslated(_x*320, _y*320, 0);
  for(int i = 0; i < _y+2; ++i)
  {
    for(int j = 0; j < _x+2; ++j)
    {
     ground.setpos(j*64, i*64, 0);
     ground.draw();
      if (j == 0 || i == 0)
      {
        wall.setpos(j*64, i*64, 64);
        wall.draw();
      }
      else if (j == (_x + 1) || i == (_y + 1))
      {
        wall.setpos(j*64, i*64, 64);
        wall.draw();
      }
    }
  }
}

void	LibOpenGL::draw_snake_and_food(const std::vector< std::vector<item_type> > &map)
{
    Pave 	cake(0, 0, 0, 64, 64, 32, _tex["cake"]);
    Pave 	body1(0, 0, 0, 64, 64, 64, _tex["body1"]);

    for(int i = 0; i < _y; ++i)
    {
      for (int j = 0; j < _x; ++j)
      {
        if (map[i][j] == BODY || map[i][j] == HEAD)
        {
          body1.setpos(((_x-j)+1)*64, (i+1)*64, 64);
          body1.draw();
        }
        else if (map[i][j] == FOOD)
        {
          cake.setpos(((_x-j)+1)*64, (i+1)*64, 64);
          cake.draw();
        }
      }
    }
}

void  LibOpenGL::finish(const std::string str)
{
  std::cerr << str << std::endl;
  exit(EXIT_SUCCESS);
}