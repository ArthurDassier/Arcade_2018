##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CORE			=	arcade

GAMES			=	games

GRAPHICALS		=	graphicals

TEST_SFML		=	unit_tests_SFML

TEST_SDL		=	unit_tests_SDL

TEST_NCURSES	=	unit_tests_NCURSES

CORE_DIR		=	srcs/

GAMES_DIR		=	games/

LIB_DIR			=	lib/

TESTS_DIR		=	tests/

all:			$(CORE) $(GAMES) $(GRAPHICALS)

core:			$(CORE)

games:			$(GAMES)

graphicals:		$(GRAPHICALS)

tests_run:		
				$(MAKE) -C $(TESTS_DIR)
				./$(TEST_SDL)
				./$(TEST_SFML)
				./$(TEST_NCURSES)

$(CORE):
				$(info ************  BUILDING CORE ************)
				$(MAKE) -C $(CORE_DIR)

$(GAMES):
				$(info ************  BUILDING GAMES ************)
				$(MAKE)	-C $(GAMES_DIR)

$(GRAPHICALS):	
				$(info ************  BUILDING GRAPHICALS ************)
				$(MAKE) -C $(LIB_DIR)

clean:
				$(MAKE) clean -C $(CORE_DIR)
				$(MAKE) clean -C $(GAMES_DIR)
				$(MAKE) clean -C $(LIB_DIR)
				$(MAKE) clean -C $(TESTS_DIR)

fclean:			
				$(MAKE) fclean -C $(CORE_DIR)
				$(MAKE) fclean -C $(GAMES_DIR)
				$(MAKE) fclean -C $(LIB_DIR)
				$(MAKE) fclean -C $(TESTS_DIR)
				$(RM) $(CORE)
				$(RM) $(TEST_SFML) $(TEST_SDL) $(TEST_NCURSES)

re:			fclean all

.PHONY:		all clean fclean re core graphicals games
