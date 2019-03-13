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

UT 	= 	$(UT_DIR)/?				\

UT2	=	$(SRC_DIR)/?			\

OBJS_UT	=	$(UT:.cpp=.o)

OBJS_UT2	=	$(UT2:.cpp=.o)

RM	=	rm -rf

CXXFLAGS	+=	-Wall -Wextra

CXXFLAGS	+=	-I./srcs/Components -I./srcs/SpecialComponents

INCLUDE	=	-I./srcs/Components -I./srcs/SpecialComponents

INCLUDE	+=	-I./srcs/Parser -I./srcs/Circus -I./srcs/ -I./srcs/CLI

LD_FLAGS	=	-lcriterion -coverage

all:		$(NAME)

$(NAME): $(OBJS) 
		$(CXX) $(INCLUDE) -o $(NAME) $(OBJS)


tests_run:	$(OBJS) 
			g++ -std=c++11 $(INCLUDE) -o UT $(UT) $(UT2) $(LD_FLAGS)
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
