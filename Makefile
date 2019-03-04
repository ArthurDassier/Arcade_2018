##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	=	nanotekspice

CXX	=	g++ -std=c++11 -g3

SRC_DIR	=	./srcs

UT_DIR	=	./tests

EXE	=	$(SRC_DIR)/Components/Component.cpp			\
		$(SRC_DIR)/Components/Component_4001.cpp	\
		$(SRC_DIR)/Components/Component_4008.cpp	\
		$(SRC_DIR)/Components/Component_4011.cpp	\
		$(SRC_DIR)/Components/Component_4013.cpp	\
		$(SRC_DIR)/Components/Component_4017.cpp	\
		$(SRC_DIR)/Components/Component_4030.cpp	\
		$(SRC_DIR)/Components/Component_4040.cpp	\
		$(SRC_DIR)/Components/Component_4069.cpp	\
		$(SRC_DIR)/Components/Component_4071.cpp	\
		$(SRC_DIR)/Components/Component_4081.cpp	\
		$(SRC_DIR)/Components/Component_4801.cpp	\
		$(SRC_DIR)/Components/Component_2716.cpp	\
		$(SRC_DIR)/Components/Component_4094.cpp	\
		$(SRC_DIR)/Components/Component_4503.cpp	\
		$(SRC_DIR)/Components/Component_4512.cpp	\
		$(SRC_DIR)/Components/Component_4514.cpp	\
		$(SRC_DIR)/Circus/Circus.cpp				\
		$(SRC_DIR)/SpecialComponents/True.cpp		\
		$(SRC_DIR)/SpecialComponents/False.cpp		\
		$(SRC_DIR)/SpecialComponents/Input.cpp		\
		$(SRC_DIR)/SpecialComponents/Output.cpp		\
		$(SRC_DIR)/SpecialComponents/Clock.cpp		\
		$(SRC_DIR)/CLI/CLI.cpp						\
		$(SRC_DIR)/Parser/Parser.cpp				\
		$(SRC_DIR)/main.cpp							\

OBJS	=	$(EXE:.cpp=.o)

UT 	= 	$(UT_DIR)/Components/tests_Component_4001.cpp		\
		$(UT_DIR)/Components/tests_Component_4008.cpp		\
		$(UT_DIR)/Components/tests_Component_4011.cpp		\
		$(UT_DIR)/Components/tests_Component_4030.cpp		\
		$(UT_DIR)/Components/tests_Component_4069.cpp		\
		$(UT_DIR)/Components/tests_Component_4071.cpp		\
		$(UT_DIR)/Components/tests_Component_4081.cpp		\
		$(UT_DIR)/Components/tests_Component_4503.cpp		\
		$(UT_DIR)/Components/tests_Component_4514.cpp		\
		$(UT_DIR)/Components/tests_SpecialComponents.cpp	\
		$(UT_DIR)/Circus/tests_Circus.cpp					\
		$(UT_DIR)/Factory/tests_Factory.cpp					\
		$(UT_DIR)/Parser/tests_Parser.cpp					\

UT2	=	$(SRC_DIR)/Components/Component.cpp			\
		$(SRC_DIR)/Components/Component_4001.cpp	\
		$(SRC_DIR)/Components/Component_4008.cpp	\
		$(SRC_DIR)/Components/Component_4801.cpp	\
		$(SRC_DIR)/Components/Component_2716.cpp	\
		$(SRC_DIR)/Components/Component_4011.cpp	\
		$(SRC_DIR)/Components/Component_4013.cpp	\
		$(SRC_DIR)/Components/Component_4017.cpp	\
		$(SRC_DIR)/Components/Component_4030.cpp	\
		$(SRC_DIR)/Components/Component_4040.cpp	\
		$(SRC_DIR)/Components/Component_4069.cpp	\
		$(SRC_DIR)/Components/Component_4071.cpp	\
		$(SRC_DIR)/Components/Component_4081.cpp	\
		$(SRC_DIR)/Components/Component_4094.cpp	\
		$(SRC_DIR)/Components/Component_4503.cpp	\
		$(SRC_DIR)/Components/Component_4512.cpp	\
		$(SRC_DIR)/Components/Component_4514.cpp	\
		$(SRC_DIR)/SpecialComponents/True.cpp		\
		$(SRC_DIR)/SpecialComponents/False.cpp		\
		$(SRC_DIR)/SpecialComponents/Input.cpp		\
		$(SRC_DIR)/SpecialComponents/Output.cpp		\
		$(SRC_DIR)/SpecialComponents/Clock.cpp		\
		$(SRC_DIR)/CLI/CLI.cpp						\
		$(SRC_DIR)/Parser/Parser.cpp				\
		$(SRC_DIR)/Circus/Circus.cpp				\

OBJS_UT	=	$(UT:.cpp=.o)

OBJS_UT2	=	$(UT2:.cpp=.o)

RM	=	rm -rf

CXXFLAGS	+=	-Wall -Wextra

CXXFLAGS	+=	-I./srcs/Components -I./srcs/SpecialComponents

CXXFLAGS	+=	-I./srcs/Parser -I./srcs/Circus -I./srcs/ -I./srcs/CLI

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
