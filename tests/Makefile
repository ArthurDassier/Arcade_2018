##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CP				=	cp

CPP				=	g++

CPPFLAGS		=	-std=c++11

LDFLAGS			=	-coverage -lcriterion

TEST			=	unit_tests

TEST_FILES		=	tests_SFML.cpp

TEST_OBJS		=	$(TEST_FILES:.cpp=.o)

ifeq ($(shell cat /etc/*-release | grep "Fedora"), )
LIB				=	-lsfml-audio -lsfml-window -lsfml-system -lsfml-graphics
else
LIB				=	-lsfml-graphics -lsfml-window -lsfml-system
endif

$(TEST):		$(TEST_OBJS)
				$(CPP) $(CPPFLAGS) $(LDFLAGS) $(TEST_OBJS) $(LIB) -o $(TEST)
				$(CP) $(TEST) ..
				# ./$(TEST)

all:			$(TEST)

clean:
				$(RM) $(TEST_OBJS)

fclean:			clean
				$(RM) $(TEST)

re:				fclean all

.PHONY:			all clean fclean re