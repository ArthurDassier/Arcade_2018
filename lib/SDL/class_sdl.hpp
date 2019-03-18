/*
** EPITECH PROJECT, 2019
** class_sdl.hpp
** File description:
** class_sdl
*/

#ifndef CLASS_SDL_HPP_
    #define CLASS_SDL_HPP_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GLES3/gl3.h>
#include "IGraphic.hpp"

class class_sdl : public IGraphic
{
    public:
        class_sdl();
        ~class_sdl();

        //Members
        bool runGraph();
        void setMap();
        void translateKey();

        void setIsNewMap(bool);
        bool getIsNewMap(void) const;

        void setIsNewKey(bool);
        bool getIsNewKey(void) const;

        void setLastKey(int);
        int getLastKey(void) const;

    private:
        SDL_Window *_win;
        SDL_Renderer *_ren;
        SDL_Event _e;
        std::shared_ptr<void> _map;
        bool _isNewMap;
        bool _isNewKey;
        int _key;
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
    {271, 40},  // Enter
    {32, 41},  // Space
    {8, 42}, // BackSpace
    {9, 43},   // Tab
    {1000, 1000}
};

#endif /* !CLASS_SDL_HPP_ */
