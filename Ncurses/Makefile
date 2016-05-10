##
## Makefile for make in /home/sturbo_o/depot_git/cpp_nibbler/OpenGL
## 
## Made by Olivier STURBOIS
## Login   <sturbo_o@epitech.net>
## 
## Started on  Fri Apr  4 22:24:03 2014 Olivier STURBOIS
## Last update Sat Apr  5 17:06:29 2014 Olivier STURBOIS
##

CXX	=	g++

RM	=	rm -f

NAME	=	../libncurses.so

CXXFLAGS=	-Wextra -Wall -Werror -rdynamic -fPIC

SRCS	=	LibNcurses.cpp \

OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) -shared $(OBJS) -o $(NAME) $(LDFLAGS) -lncurses

clean:
		$(RM) $(OBJS)
		$(RM) *~

fclean:		clean
		$(RM) $(NAME)

re:		fclean all