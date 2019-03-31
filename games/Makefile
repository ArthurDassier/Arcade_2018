##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

GAMES_DIRS = pacman

all:
	@for i in $(GAMES_DIRS); do $(MAKE) -C $$i all || exit 1; done

clean:
	@for i in $(GAMES_DIRS); do $(MAKE) -C $$i clean || exit 1; done

fclean:
	@for i in $(GAMES_DIRS); do $(MAKE) -C $$i fclean || exit 1; done

.PHONY:	all clean fclean