##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CPP				=	g++

CPPFLAGS		=	-std=c++11 -g3

LDFLAGS			=	-shared -fPIC

ifeq ($(shell cat /etc/*-release | grep "Fedora"), )
LIB				=	-lsfml-audio -lsfml-window -lsfml-system -lsfml-graphics
else
LIB				=	-lsfml-graphics -lsfml-window -lsfml-system
endif

SFML			=	lib_arcade_sfml.so

SFML_DIR		=	SFML/

SFML_FILES		=	class_sfml.cpp

SFML_SRCS		=	$(addprefix $(SFML_DIR), $(SFML_FILES))

SFML_OBJS		=	$(SFML_SRCS:.cpp=.o)

$(SFML):
				$(CPP) $(CPPFLAGS) $(LDFLAGS) $(SFML_SRCS) $(LIB) -o $(SFML)

all:			$(SFML)

clean:
				$(RM) $(SFML_OBJS)

fclean:			clean
				$(RM) $(SFML)

re:				fclean all

.PHONY:			all clean fclean re