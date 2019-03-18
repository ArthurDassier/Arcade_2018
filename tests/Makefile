##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CP				=	cp

CPP				=	g++

CPPFLAGS		=	-std=c++11

LDFLAGS			=	-coverage -lcriterion -lSDL2 -lGL -lGLU -lncurses

INCLUDE			=	-I../lib/

INCLUDE			+=	-I../lib/SDL

INCLUDE			+=	-I../lib/NCURSES

INCLUDE			+=	-I../lib/SFML

TEST			=	unit_tests

FILES			=	../lib/SDL/class_sdl.cpp			\
					../lib/NCURSES/class_ncurses.cpp	\
					../lib/SFML/class_sfml.cpp	\

FILES_OBJS		= $(FILES:.cpp=.o)

TEST_FILES		=	tests_SDL.cpp		\
					tests_NCURSES.cpp	\
					tests_SFML.cpp		\

TEST_OBJS		=	$(TEST_FILES:.cpp=.o)

ifeq ($(shell cat /etc/*-release | grep "Fedora"), )
LIB				=	-lsfml-audio -lsfml-window -lsfml-system -lsfml-graphics
else
LIB				=	-lsfml-graphics -lsfml-window -lsfml-system
endif

$(TEST):
				$(CPP) $(INCLUDE) $(CPPFLAGS) $(TEST_FILES) $(FILES) $(LIB) -o $(TEST) $(LDFLAGS)
				$(CP) $(TEST) ..

all:			$(TEST)

clean:
				$(RM) $(TEST_OBJS)

fclean:			clean
				$(RM) $(TEST)
				$(RM) *.gc*

re:				fclean all

.PHONY:			all clean fclean re