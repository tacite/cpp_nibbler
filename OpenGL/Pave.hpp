/*
** Pave.hh for nibbler in /home/bajeux_m/Documents/Teck2/cpp/nibbler/opengl
**
** Made by Maxime Bajeux
** Login   <bajeux_m@epitech.net>
**
** Started on  mar. avril 01 16:53:57 2014 Maxime Bajeux
** Last update sam. avril 05 23:10:47 2014 Maxime Bajeux
*/

#ifndef Pave_H_
# define Pave_H_

# include	"LibOpenGL.hpp"
# include	"Texture.hpp"

class Pave
{
public:
	Pave(int, int, int, int, int, int, std::map<std::string, Texture>);
	~Pave();

	void	setpos(int, int, int);

	void	draw();

private:
	int		_posx;
	int		_posy;
	int		_posz;
	int		_sizex;
	int		_sizey;
	int		_sizez;
	Pave(const Pave&); 
	std::map<std::string, Texture>	_tex;
};

#endif /* Pave_H_ */
