##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC				=	g++

CP				=	cp

CORE			=	arcade

GAMES			=	games

GRAPHICALS		=	graphicals

TEST_SFML		=	unit_tests_SFML

TEST_SDL		=	unit_tests_SDL

TEST_NCURSES	=	unit_tests_NCURSES

INCLUDE_DIR		=	./includes/

CORE_DIR		=	./srcs/

GAMES_DIR		=	games/

LIB_DIR			=	lib/

TESTS_DIR		=	tests/

SRCS			=	$(CORE_DIR)main.cpp				\
					$(CORE_DIR)Core.cpp

OBJ				=	$(SRCS:.cpp=.o)

CXXFLAGS		=	-Wall -Wextra -std=c++17 

CPPFLAGS		=	-I$(INCLUDE_DIR)

LDFLAGS			=	-ldl -lstdc++fs

all:			$(CORE) $(GAMES) $(GRAPHICALS)

core:			$(CORE)

games:			$(GAMES)

graphicals:		$(GRAPHICALS)

tests_run:		
				$(MAKE) -C $(TESTS_DIR)
				./$(TEST_SDL)
				./$(TEST_SFML)
				./$(TEST_NCURSES)

$(CORE):	$(OBJ)
				$(info ************  BUILDING CORE ************) 
				$(CC) -o $(CORE) $(OBJ) $(LDFLAGS)

$(GAMES):
				$(info ************  BUILDING GAMES ************)
				$(MAKE)	-C $(GAMES_DIR)

$(GRAPHICALS):	
				$(info ************  BUILDING GRAPHICALS ************)
				$(MAKE) -C $(LIB_DIR)

clean:
				$(RM) $(OBJ)
				$(MAKE) clean -C $(GAMES_DIR)
				$(MAKE) clean -C $(LIB_DIR)
				$(MAKE) clean -C $(TESTS_DIR)

fclean:			
				$(RM) $(OBJ)
				$(MAKE) fclean -C $(GAMES_DIR)
				$(MAKE) fclean -C $(LIB_DIR)
				$(MAKE) fclean -C $(TESTS_DIR)
				$(RM) $(CORE)
				$(RM) $(TEST_SFML) $(TEST_SDL) $(TEST_NCURSES)

re:			fclean all

.PHONY:		all clean fclean re core graphicals games
