/*
** EPITECH PROJECT, 2019
** ClassSDL.hpp
** File description:
** ClassSDL
*/

#pragma once

#include <SDL2/SDL.h>
#include "IGraphic.hpp"
#include "../srcs/ParsingConfig.hpp"

enum Graphics {
    NOTHING = '0',
    WALL = '1',
    POINT = '2',
    PLAYER = '3',
    ENEMY = '4',
    BONUS = '5',
    SDL = '6',
    SFML = '7',
    NCURSES = '8'
};

class ClassSDL : public IGraphic
{
    public:
        ClassSDL();
        ~ClassSDL();

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

        void setMapTexture();
        void displayGame();

        void setPathConfig(std::string) noexcept;
        std::string getPathConfig() const noexcept;

        void setIsNewPathConfig(bool) noexcept;
        bool getIsNewPathConfig() const noexcept;

        void buildMap(std::shared_ptr<std::vector<std::string>>);

    private:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _wind;
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>_ren;
        std::unique_ptr<std::vector<std::vector<std::pair<char, std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>>>>> _map;
        std::vector<std::pair<SDL_Rect, std::shared_ptr<SDL_Surface>>> _textures;
        ParsingConfig _parsing;
        SDL_Event _e;

        std::string _pathConfig;
        bool _isNewPathConfig;
        bool _isNewMap;
        bool _isNewKey;
        size_t _score;
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
    {13, 40},  // Enter
    {32, 41},  // Space
    {8, 42}, // BackSpace
    {9, 43},   // Tab
    {-1, -1}
};

