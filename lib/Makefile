##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CXX				=	g++

CXXFLAGS		=	-std=c++17 -g3

LDFLAGS			=	-shared -fPIC

INCLUDE			=	-I.

ifeq ($(shell cat /etc/*-release | grep "Fedora"), )
LIB_SFML		=	-lsfml-audio -lsfml-window -lsfml-system -lsfml-graphics
else
LIB_SFML		=	-lsfml-graphics -lsfml-window -lsfml-system
endif

LIB_NCURSES		=	-lncurses

LIB_SDL			=	-lSDL2

SFML			=	lib_arcade_sfml.so

SFML_DIR		=	SFML/

SFML_FILES		=	AnimatedSprite.cpp	\
					Animation.cpp		\
					ClassSFML.cpp

SFML_SRCS		=	$(addprefix $(SFML_DIR), $(SFML_FILES))

SFML_OBJS		=	$(SFML_SRCS:.cpp=.o)

NCURSES			=	lib_arcade_ncurses.so

NCURSES_DIR		=	NCURSES/

NCURSES_FILES	=	ClassNcurses.cpp

NCURSES_SRCS	=	$(addprefix $(NCURSES_DIR), $(NCURSES_FILES))

#NCURSES_OBJS	=	$(NCURSES_SRCS:.cpp=.o)

SDL			=	lib_arcade_sdl2.so

SDL_DIR		=	SDL/

SDL_FILES	=	ClassSDL.cpp

SDL_SRCS	=	$(addprefix $(SDL_DIR), $(SDL_FILES))

#SDL_OBJS	=	$(SDL_SRCS:.cpp=.o)

all:			$(SFML) $(SDL) #$(NCURSES)

$(SFML):
				$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SFML_SRCS) $(LIB_SFML) -o $(SFML) $(INCLUDE)

$(NCURSES):
				$(CXX) $(CXXFLAGS) $(LDFLAGS) $(NCURSES_SRCS) $(LIB_NCURSES) -o $(NCURSES) $(INCLUDE)

$(SDL):
				$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SDL_SRCS) $(LIB_SDL) -o $(SDL) $(INCLUDE)

clean:
				# $(RM) $(SFML_OBJS)
				# $(RM) $(NCURSES_OBJS)
				# $(RM) $(SDL_OBJS)

fclean:			clean
				$(RM) $(SFML)
				$(RM) $(NCURSES)
				$(RM) $(SDL)

re:				fclean all

.PHONY:			all clean fclean re
