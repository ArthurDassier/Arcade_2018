##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC			=	g++

INCLUDE		=	../../includes/

SRCS		=	ClassSFML.cpp

OBJ			=	$(SRCS:.cpp=.o)

CXXFLAGS	=	-shared -fPIC -Wall -Wextra -std=c++17

LDFLAGS		=	-lsfml-graphics -lsfml-window -lsfml-system

CPPFLAGS	=	-I$(INCLUDE)

LDFLAGS		=	 -lsfml-graphics -lsfml-window -lsfml-system

NAME		=	lib_arcade_sfml.so

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
