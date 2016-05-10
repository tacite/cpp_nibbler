##
## Makefile for abstracite in /home/tacite_d/Projet/C++/cpp_nibbler
## 
## Made by tacite_d
## Login   <tacite_d@epitech.net>
## 
## Started on  Tue Feb 25 13:22:19 2014 tacite_d
## Last update Sun Apr  6 23:36:08 2014 Olivier STURBOIS
##

CXX		=	g++

RM		=	rm -f

NAME		=	nibbler

CXXFLAGS	=	-Wextra -Wall -Werror -ldl -IIncludes -lpthread

SRCS		=	Main.cpp	\
			Core/Food.cpp	\
			Core/Item.cpp	\
			Core/Snake.cpp	\
			Core/Exceptions.cpp \
			Core/LibHandler.cpp \
			Core/Game.cpp \
			Core/Core.cpp \

OBJS		=	$(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS)

clean:
			$(RM) $(OBJS)
			$(RM) *~ */*~

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
