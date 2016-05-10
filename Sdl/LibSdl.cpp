#include	"LibSdl.hpp"
# include	<SDL/SDL_image.h>
#include	"stdlib.h"

extern "C" IGraph		*loadLibrary()
{
  return new LibSdl();
}

extern "C" void		unloadLibrary(IGraph *lib)
{
  delete lib;
}

LibSdl::LibSdl()
{
}

LibSdl::~LibSdl()
{
  SDL_Quit();
}

void		LibSdl::myBlitSurface(SDL_Surface* surface, int x, int y)
{
  this->_pos.x = x * LENGTH;
  this->_pos.y = y * LENGTH;
  
  SDL_BlitSurface(surface, NULL, this->_screen, &(this->_pos));
  SDL_Flip(this->_screen);
}


void		LibSdl::init(int width, int height)
{ 
  SDL_Init(SDL_INIT_VIDEO);
  this->_screen = SDL_SetVideoMode(width * LENGTH, height * LENGTH, 16, SDL_HWSURFACE);
  this->_size.first = width;
  this->_size.second = height;
  SDL_WM_SetCaption("Niggler By Sturbo_o Bajeux_m Tacite_d", NULL);
  SDL_Surface	*head = SDL_LoadBMP("Textures/head.bmp");
  SDL_Surface	*back = SDL_LoadBMP("Textures/body.bmp");
  SDL_Surface	*body = SDL_LoadBMP("Textures/body.bmp");
  SDL_Surface	*food = SDL_LoadBMP("Textures/munchie.bmp");
  
  this->_textures[HEAD] = head;
  this->_textures[BACK] = back;
  this->_textures[BODY] = body;
  this->_textures[FOOD] = food;
}

void		LibSdl::draw(const std::vector< std::vector<item_type> > &map)
{
  int		a = 0, b = 0;
  
  SDL_FillRect(this->_screen, NULL, SDL_MapRGB(this->_screen->format, 255, 255, 255));
  while (a < this->_size.second)
  {
    b = 0;
    while (b < this->_size.first)
    {
      if (map[a][b] != NONE)
      {
	this->myBlitSurface(this->_textures[map[a][b]], b, a);
      }
     b++; 
    }
    a++;
  }
}

void LibSdl::event(int &ptr)
{
  while (1)
  {
    SDL_WaitEvent(&this->_event);
    if(_event.type == SDL_QUIT)
      exit(0);
    if (_event.key.keysym.sym == SDLK_ESCAPE)
      exit(0);
    if (_event.type == SDL_KEYUP)
    {
      if (_event.key.keysym.sym == SDLK_LEFT)
	{
	  ptr = 1;
	 }
      if (_event.key.keysym.sym == SDLK_RIGHT)
	{
	  ptr = 2;
	}
    }
  }
}

void LibSdl::finish(const std::string msg)
{
    std::cerr << msg << std::endl;
    exit(EXIT_SUCCESS);
}
