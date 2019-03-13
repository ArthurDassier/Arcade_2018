##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CP				=	cp

CPP				=	g++

CPPFLAGS		=	-std=c++11 -g3

INCLUDE			=	-I../lib/SFML

INCLUDE			+=	-I../lib/NCURSES

LDFLAGS			=	-shared -fPIC

CORE			=	arcade

CORE_FILES		=	main.cpp

CORE_OBJS		=	$(CORE_FILES:.cpp=.o)

$(CORE):
				$(CPP) $(INCLUDE) $(CPPFLAGS) $(CORE_FILES) -o $(CORE) -ldl
				$(CP) $(CORE) ..

all:			$(CORE)

clean:
				$(RM) $(CORE_OBJS)

fclean:			clean
				$(RM) $(CORE)

re:				fclean all

.PHONY:			all clean fclean re