##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CP				=	cp

CXX				=	g++

CXXFLAGS		=	-std=c++17

LDFLAGS			=	-coverage -lcriterion -lSDL2 -lGL -lGLU -lncurses

INCLUDE			=	-I../lib/

INCLUDE			+=	-I../lib/SDL

INCLUDE			+=	-I../lib/NCURSES

INCLUDE			+=	-I../lib/SFML

##### SFML #####
FILES_SFML			=	../lib/SFML/class_sfml.cpp

FILES_SFML_OBJS		=	$(FILES_SFML:.cpp=.o)

TEST_FILES_SFML		=	tests_SFML.cpp

TEST_OBJS_SFML		=	$(TEST_FILES_SFML:.cpp=.o)

TEST_SFML			=	unit_tests_SFML

##### SDL ######
FILES_SDL			=	../lib/SDL/class_sdl.cpp

FILES_SDL_OBJS		=	$(FILES_SDL:.cpp=.o)

TEST_FILES_SDL		=	tests_SDL.cpp

TEST_OBJS_SDL		=	$(TEST_FILES_SDL:.cpp=.o)

TEST_SDL			=	unit_tests_SDL

##### NCURSES ######
FILES_NCURSES		=	../lib/NCURSES/class_ncurses.cpp

FILES_NCURSES_OBJS	=	$(FILES_NCURSES:.cpp=.o)

TEST_FILES_NCURSES	=	tests_NCURSES.cpp

TEST_OBJS_NCURSES	=	$(TEST_FILES_NCURSES:.cpp=.o)

TEST_NCURSES		=	unit_tests_NCURSES

ifeq ($(shell cat /etc/*-release | grep "Fedora"), )
LIB				=	-lsfml-audio -lsfml-window -lsfml-system -lsfml-graphics
else
LIB				=	-lsfml-graphics -lsfml-window -lsfml-system
endif

all:
				$(CXX) $(INCLUDE) $(CXXFLAGS) $(TEST_FILES_SFML) $(FILES_SFML) $(LIB) -o $(TEST_SFML) $(LDFLAGS)
				$(CXX) $(INCLUDE) $(CXXFLAGS) $(TEST_FILES_SDL) $(FILES_SDL) $(LIB) -o $(TEST_SDL) $(LDFLAGS)
				$(CXX) $(INCLUDE) $(CXXFLAGS) $(TEST_FILES_NCURSES) $(FILES_NCURSES) $(LIB) -o $(TEST_NCURSES) $(LDFLAGS)
				$(CP) $(TEST_SFML) ..
				$(CP) $(TEST_SDL) ..
				$(CP) $(TEST_NCURSES) ..

clean:
				$(RM) *.gc*

fclean:			clean
				$(RM) $(TEST_SFML) $(TEST_SDL) $(TEST_NCURSES)				

re:				fclean all

.PHONY:			all clean fclean re