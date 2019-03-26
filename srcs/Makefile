##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CP				=	cp

CXX				=	g++

CXXFLAGS		=	-std=c++17 -g3

INCLUDE			=	-I../lib

INCLUDE			+=	-I../lib/SFML

INCLUDE			+=	-I../lib/NCURSES

INCLUDE			+= 	-I../games

LDFLAGS			=	-shared -fPIC

CORE			=	arcade

CORE_FILES		=	main.cpp	\
					Core.cpp

CORE_OBJS		=	$(CORE_FILES:.cpp=.o)

$(CORE):
				$(CXX) $(INCLUDE) $(CXXFLAGS) $(CORE_FILES) -o $(CORE) -ldl
				$(CP) $(CORE) ..

all:			$(CORE)

clean:
				$(RM) $(CORE_OBJS)

fclean:			clean
				$(RM) $(CORE)

re:				fclean all

.PHONY:			all clean fclean re