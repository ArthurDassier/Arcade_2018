/*
** EPITECH PROJECT, 2019
** ClassNcurses.hpp
** File description:
** ClassNcurses
*/

#pragma once

#include <ncurses.h>
#include "IGraphic.hpp"
#include "ParsingConfig.hpp"

enum Graphics {
    NOTHING = '0',
    WALL = '1',
    POINT = '2',
    PLAYER = '3',
    GHOST = '4',
    BONUS = '5',
    SDL = '6',
    SFML = '7',
    NCURSES = '8'
};

/*! \class ClassNcurses
* \brief Class representing ClassNcurses logic
*
*  This class contains the fonctions that handle the NCURSES
*/

class ClassNcurses : public IGraphic
{
    public:
        ClassNcurses();
        ~ClassNcurses();

        //Members
        bool runGraph();
        void setMap(std::shared_ptr<std::vector<std::string>>);
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
        bool getEvent();

        void displayMenu();
        void displayLetters();

        //pour le menu
        int get_input();
        std::string get_string();
        char translate_for_menu(int);

    private:
        std::unique_ptr<std::vector<std::string>> _map;
        WINDOW *_window;
        WINDOW *_window_menu_sdl;
        WINDOW *_window_menu_sfml;
        WINDOW *_window_menu_ncurses;
        size_t _posi_menu;
        int _c;
        bool _isNewMap;
        bool _isNewKey;
        size_t _score;
        int _key;
        std::string _str;
        std::string _pathConfig;
        bool _isNewPathConfig;
        ParsingConfig _parsing;
};

/*!
 * \struct KeyNcurses
 * \brief This Structure contains Keys input translation
 */

struct KeyNcurses {
    int code_lib;
    int code_core;
};

/*!
 * \struct KeyNcurses
 * \brief This Structure contains Keys input translation
 */

static struct KeyNcurses KeyNcurses[] = {
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
    {259, 36}, // Up
    {258, 37}, // Down
    {261, 38}, // Right
    {260, 39}, // Left
    {10, 40},  // Enter
    {32, 41},  // Space
    {263, 42}, // BackSpace
    {9, 43},   // Tab
    {1000, 1000}
};

