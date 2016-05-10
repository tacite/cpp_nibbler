##
## Makefile for make in /home/sturbo_o/depot_git/cpp_nibbler/OpenGL
## 
## Made by Olivier STURBOIS
## Login   <sturbo_o@epitech.net>
## 
## Started on  Fri Apr  4 22:24:03 2014 Olivier STURBOIS
## Last update dim. avril 06 00:18:08 2014 Maxime Bajeux
##

CXX	=	g++

RM	=	rm -f

NAME	=	../libopengl.so

CXXFLAGS=	-Wextra -Wall -Werror -rdynamic -fPIC

LDFLAGS	=	-lSDL -lm -lGL -lGLU -lSOIL -shared

SRCS	=	LibOpenGL.cpp \
	Pave.cpp \
	Texture.cpp \

OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $(NAME) $(CXXFLAGS) $(LDFLAGS)

clean:
		$(RM) $(OBJS)
		$(RM) *~

fclean:		clean
		$(RM) $(NAME)

re:		fclean all