##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CPP				=	g++

CPPFLAGS		=	-std=c++11 -g3

LDFLAGS			=	-shared -fPIC

ifeq ($(shell cat /etc/*-release | grep "Fedora"), )
LIB_SFML		=	-lsfml-audio -lsfml-window -lsfml-system -lsfml-graphics
else
LIB_SFML		=	-lsfml-graphics -lsfml-window -lsfml-system
endif

LIB_NCURSES		=	-lncurses

SFML			=	lib_arcade_sfml.so

SFML_DIR		=	SFML/

SFML_FILES		=	class_sfml.cpp

SFML_SRCS		=	$(addprefix $(SFML_DIR), $(SFML_FILES))

SFML_OBJS		=	$(SFML_SRCS:.cpp=.o)

NCURSES			=	lib_arcade_ncurses.so

NCURSES_DIR		=	NCURSES/

NCURSES_FILES	=	class_ncurses.cpp

NCURSES_SRCS	=	$(addprefix $(NCURSES_DIR), $(NCURSES_FILES))

NCURSES_OBJS	=	$(NCURSES_SRCS:.cpp=.o)

all:			$(SFML) $(NCURSES)

$(SFML):
				$(CPP) $(CPPFLAGS) $(LDFLAGS) $(SFML_SRCS) $(LIB_SFML) -o $(SFML)

$(NCURSES):
				$(CPP) $(CPPFLAGS) $(LDFLAGS) $(NCURSES_SRCS) $(LIB_NCURSES) -o $(NCURSES)

clean:
				$(RM) $(SFML_OBJS)
				$(RM) $(NCURSES_OBJS)

fclean:			clean
				$(RM) $(SFML)
				$(RM) $(NCURSES)

re:				fclean all

.PHONY:			all clean fclean re