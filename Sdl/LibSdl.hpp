#ifndef			__LIBSDL__
# define		__LIBSDL__

# include	<SDL/SDL.h>
# include	<SDL/SDL_events.h>
# include	<SDL/SDL_image.h>
# include	"../Includes/IGraph.hpp"
# include	"../Includes/Item.hpp"
# include	<vector>
# include	<iostream>
# include	<string>
# include	<map>

# define	LENGTH	16

class		LibSdl : public IGraph
{
  private:
    std::pair<int, int>	_size;
    SDL_Rect		_pos;
    SDL_Surface		*_screen;
    SDL_Event		_event;
    std::map<item_type, SDL_Surface *>	_textures;
  public:
    LibSdl();
    ~LibSdl();
    void		draw(const std::vector< std::vector<item_type> > &map);
    void		event(int &ptr);
    void		init(int width, int height);
    void		finish(const std::string);
  private:
    void		myBlitSurface(SDL_Surface *surface, int x, int y);
};


#endif
