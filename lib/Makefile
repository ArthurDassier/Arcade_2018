##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

LIBS_DIRS = NCURSES SDL SFML

all:
	@for i in $(LIBS_DIRS); do $(MAKE) -C $$i all || exit 1; done

clean:
	@for i in $(LIBS_DIRS); do $(MAKE) -C $$i clean || exit 1; done

fclean:
	@for i in $(LIBS_DIRS); do $(MAKE) -C $$i fclean || exit 1; done

.PHONY:	all clean fclean