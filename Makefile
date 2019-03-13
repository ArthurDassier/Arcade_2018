##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	=	arcade

CXX	=	g++ -std=c++11 -g3

SRC_DIR	=	./srcs

UT_DIR	=	./tests

EXE	=	$(SRC_DIR)/main.cpp		\

OBJS	=	$(EXE:.cpp=.o)

UT 	= 	$(UT_DIR)/tests_SFML.cpp	\

UT2	=	$(SRC_DIR)/libs/SFML/class_sfml.cpp	\

OBJS_UT	=	$(UT:.cpp=.o)

OBJS_UT2	=	$(UT2:.cpp=.o)

RM	=	rm -rf

CXXFLAGS	+=	-Wall -Wextra

CXXFLAGS	+= -I./srcs/libs/SFML

INCLUDE	=	-I./srcs/libs/SFML


LD_FLAGS	=	-lcriterion -coverage

ifeq ($(shell cat /etc/*-release | grep "Fedora"), )
LIB	=	-lsfml-audio -lsfml-window -lsfml-system -lsfml-graphics
else
LIB	=	-l_graph_prog
endif

all:		$(NAME)

$(NAME): $(OBJS) 
		$(CXX) $(INCLUDE) -o $(NAME) $(OBJS)


tests_run:	$(OBJS) 
			g++ -std=c++11 $(INCLUDE) -o UT $(UT) $(UT2) $(LD_FLAGS) $(LIB)
			./UT

clean:
		$(RM) $(OBJS)

ut_clean:
		$(RM) $(OBJS_UT) $(OBJS_UT2)
		find \( -name "*.gc*" -o -name "#*#" \) -delete
		$(RM) UT

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean
