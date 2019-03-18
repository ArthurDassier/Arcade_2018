##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CORE			=	arcade

GAMES			=	games

GRAPHICALS		=	graphicals

TEST			=	unit_tests

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
				./$(TEST)

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
				$(MAKE) -C $(CORE_DIR) clean
				$(MAKE) -C $(GAMES_DIR) clean
				$(MAKE) -C $(LIB_DIR) clean
				$(MAKE) -C $(TESTS_DIR) clean

fclean:			
				$(MAKE) -C $(CORE_DIR) fclean
				$(MAKE) -C $(GAMES_DIR) fclean
				$(MAKE) -C $(LIB_DIR) fclean
				$(MAKE) -C $(TESTS_DIR) fclean
				$(RM) $(CORE)
				$(RM) $(TEST)

re:			fclean all

.PHONY:		all clean fclean re
