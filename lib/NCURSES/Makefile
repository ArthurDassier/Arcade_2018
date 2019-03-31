##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC			=	g++

INCLUDE		=	../../includes/

SRCS		=	ClassNcurses.cpp

OBJ			=	$(SRCS:.cpp=.o)

CXXFLAGS	=	-shared -fPIC -Wall -Wextra -std=c++17

LDFLAGS		=	-lncurses

CPPFLAGS	=	-I$(INCLUDE)

NAME		=	lib_arcade_ncurses.so

all: 		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)
			mv $(NAME) ..

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) ../$(NAME)

re: 		fclean all

.PHONY: 	fclean clean all re
