##
## Makefile for make in /home/sturbo_o/depot_git/cpp_nibbler/OpenGL
## 
## Made by Olivier STURBOIS
## Login   <sturbo_o@epitech.net>
## 
## Started on  Fri Apr  4 22:24:03 2014 Olivier STURBOIS
## Last update Sun Apr  6 12:56:02 2014 tacite_d
##

CXX	=	g++

RM	=	rm -f

NAME	=	../libsdl.so

CXXFLAGS=	-Wextra -Wall -rdynamic -fPIC

LDFLAGS	=	-lSDL -lSDL_image -lm  -shared

SRCS	=	LibSdl.cpp \

OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)
		$(RM) *~

fclean:		clean
		$(RM) $(NAME)

re:		fclean all