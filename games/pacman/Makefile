##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC			=	g++

RM			=	rm -f

INCLUDE		=	../../includes/

CXXFLAGS	=	-shared -fPIC -Wall -std=c++17 

CPPFLAGS	=	-I$(INCLUDE)

NAME		=	lib_arcade_pacman.so

SRCS		=	Pacman.cpp	\
				Entity.cpp

OBJ			=	$(SRCS:.cpp=.o)

all: 		$(NAME)

$(NAME): 	$(OBJ)
			$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ)
			mv $(NAME) ..

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) ../$(NAME)

re: 		fclean all

.PHONY: 	fclean clean all re
