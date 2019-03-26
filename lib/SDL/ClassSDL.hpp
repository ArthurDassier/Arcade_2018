/*
** EPITECH PROJECT, 2019
** ClassSDL.hpp
** File description:
** ClassSDL
*/

#ifndef CLASS_SDL_HPP_
    #define CLASS_SDL_HPP_

#include <SDL2/SDL.h>
#include "IGraphic.hpp"

class ClassSDL : public IGraphic
{
    public:
        ClassSDL();
        virtual ~ClassSDL();

        //Members
        bool runGraph();
        void setMap(std::shared_ptr<std::vector<std::string>> map);
        void translateKey();

        void setIsNewMap(bool);
        bool getIsNewMap(void) const;

        void setIsNewKey(bool);
        bool getIsNewKey(void) const;

        void setLastKey(int);
        int getLastKey(void) const;

        void setScore(size_t);
        size_t getScore() const;

        void displayGame();

        void load_textures();
        //void print_textures();
    private:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _wind;
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>_ren;
        SDL_Event _e;
        std::unique_ptr<std::vector<std::vector<std::pair<char, std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>>>>> _map;
        bool _isNewMap;
        bool _isNewKey;
        size_t _score;
        int _key;
        int _animation;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> _stade1;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> _stade2;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> _stade3;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> _wall;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> _point;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> _gros_point;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> _pacman;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> _sfml;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> _sdl;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> _ncurses;
};

struct s_KeySdl {
    int code_lib;
    int code_core;
};

static struct s_KeySdl KeySdl[] = {
    {'a', 0},
    {'b', 1},
    {'c', 2},
    {'d', 3},
    {'e', 4},
    {'f', 5},
    {'g', 6},
    {'h', 7},
    {'i', 8},
    {'j', 9},
    {'k', 10},
    {'l', 11},
    {'m', 12},
    {'n', 13},
    {'o', 14},
    {'p', 15},
    {'q', 16},
    {'r', 17},
    {'s', 18},
    {'t', 19},
    {'u', 20},
    {'v', 21},
    {'w', 22},
    {'x', 23},
    {'y', 24},
    {'z', 25},
    {'0', 26},
    {'1', 27},
    {'2', 28},
    {'3', 29},
    {'4', 30},
    {'5', 31},
    {'6', 32},
    {'7', 33},
    {'8', 34},
    {'9', 35},
    {1073741906, 36}, // Up
    {1073741905, 37}, // Down
    {1073741903, 38}, // Right
    {1073741904, 39}, // Left
    {13, 40},  // Enter
    {32, 41},  // Space
    {8, 42}, // BackSpace
    {9, 43},   // Tab
    {1000, 1000}
};

#endif /* !CLASS_SDL_HPP_ */
