# ##
# ## EPITECH PROJECT, 2019
# ## Makefile
# ## File description:
# ## Makefile
# ##

# CC				=	g++

# CXXFLAGS		=	-Wall -Wextra -std=c++17 

# LDFLAGS			=	-shared -fPIC

# CPPFLAGS		=	-I.

# ifeq ($(shell cat /etc/*-release | grep "Fedora"), )
# LIB_SFML		=	-lsfml-audio -lsfml-window -lsfml-system -lsfml-graphics
# else
# LIB_SFML		=	-lsfml-graphics -lsfml-window -lsfml-system
# endif

# LIB_NCURSES		=	-lncurses

# LIB_SDL			=	-lSDL2

# SFML			=	lib_arcade_sfml.so

# SFML_DIR		=	SFML/

# SFML_SRCS		=	$(SFML_DIR)ClassSFML.cpp

# # SFML_SRCS		=	$(addprefix $(SFML_DIR), $(SFML_FILES))

# SFML_OBJ		=	$(SFML_SRCS:.cpp=.o)

# NCURSES			=	lib_arcade_ncurses.so

# NCURSES_DIR		=	NCURSES/

# NCURSES_SRCS	=	$(NCURSES_DIR)ClassNcurses.cpp

# NCURSES_OBJ		=	$(NCURSES_SRCS:.cpp=.o)

# # NCURSES_SRCS	=	$(addprefix $(NCURSES_DIR), $(NCURSES_FILES))

# SDL			=	lib_arcade_sdl2.so

# SDL_DIR		=	SDL/

# SDL_SRCS	=	$(SDL_DIR)ClassSDL.cpp

# SDL_OBJ		=	$(SDL_SRCS:.cpp=.o)

# # SDL_SRCS	=	$(addprefix $(SDL_DIR), $(SDL_FILES))

# all:			$(SFML) $(SDL) $(NCURSES)

# $(SFML):	$(SFML_OBJ)
# 				$(CC) -o $(SFML) $(SFML_OBJ) $(LDFLAGS) $(LIB_SFML)
# 				# $(CXX) $(CXXFLAGS) $(LDFLAGS) $(SFML_SRCS) $(LIB_SFML) -o $(SFML) $(INCLUDE)

# $(NCURSES):	$(NCURSES_OBJ)
# 				$(CC) -o $(NCURSES) $(NCURSES_OBJ) $(LDFLAGS) $(LIB_NCURSES)
# 				# $(CXX) $(CXXFLAGS) $(LDFLAGS) $(NCURSES_SRCS) $(LIB_NCURSES) -o $(NCURSES) $(INCLUDE)

# $(SDL):		$(SDL_OBJ)
# 				$(CC) -o $(SDL) $(SDL_OBJ) $(LDFLAGS) $(LIB_SDL)
# 				# $(CXX) $(CXXFLAGS) $(LDFLAGS) $(SDL_SRCS) $(LIB_SDL) -o $(SDL) $(INCLUDE)

# clean:
# 				$(RM) $(SFML_OBJ)
# 				$(RM) $(NCURSES_OBJ)
# 				$(RM) $(SDL_OBJ)

# fclean:			clean
# 				$(RM) $(SFML)
# 				$(RM) $(NCURSES)
# 				$(RM) $(SDL)

# re:				fclean all

# .PHONY:			all clean fclean re

LIBS_DIRS = NCURSES SDL SFML

all:
	@for i in $(LIBS_DIRS); do $(MAKE) -C $$i all || exit 1; done

clean:
	@for i in $(LIBS_DIRS); do $(MAKE) -C $$i clean || exit 1; done

fclean:
	@for i in $(LIBS_DIRS); do $(MAKE) -C $$i fclean || exit 1; done

.PHONY:	all clean fclean