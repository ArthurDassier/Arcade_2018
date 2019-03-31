##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CXX				=	g++

CXXFLAGS		=	-std=c++17 -g3

LDFLAGS			=	-shared -fPIC

CFLAGS			=	-I.

PACMAN			=	lib_arcade_pacman.so

PACMAN_DIR		=	pacman/

PACMAN_FILES	=	Entity.cpp	\
					Pacman.cpp

# PACMAN_SRCS		=	$(PACMAN_FILES:.cpp=.o)
PACMAN_SRCS		=	$(addprefix $(PACMAN_DIR), $(PACMAN_FILES))

NIBBLER			=	lib_arcade_nibbler.so

NIBBLER_DIR		=	Nibbler/

NIBBLER_FILES	=

NIBBLER_SRCS	=	$(addprefix $(NIBBLER_DIR), $(NIBBLER_FILES))

all:			$(PACMAN)

$(PACMAN):		#$(PACMAN_SRCS)
				$(CXX) $(CXXFLAGS) $(LDFLAGS) $(CFLAGS) $(PACMAN_SRCS) -o $(PACMAN)

clean:
				# $(RM) $(_OBJS)

fclean:			clean
				$(RM) $(PACMAN)

re:				fclean all

.PHONY:			all clean fclean re