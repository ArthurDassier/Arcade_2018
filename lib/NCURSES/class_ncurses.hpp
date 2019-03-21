/*
** EPITECH PROJECT, 2019
** class_sfml.hpp
** File description:
** class_sfml
*/

#ifndef CLASS_NCURSES_HPP_
    #define CLASS_NCURSES_HPP_

#include <ncurses.h>
#include <memory>
#include <vector>
#include <fstream>
#include "../IGraphic.hpp"

class class_ncurses : public IGraphic
{
    public:
        class_ncurses();
        ~class_ncurses();

        //Members
        bool get_event();
        bool runGraph();
        void setMap();
        void translateKey();

        void setIsNewMap(bool);
        bool getIsNewMap(void) const;

        void setIsNewKey(bool);
        bool getIsNewKey(void) const;

        void setLastKey(int);
        int getLastKey(void) const;

        bool check_first_wall(std::string, size_t);
        void set_map_texture();

    private:
        int _c;
        std::unique_ptr<std::vector<std::string>> _map;
        std::vector<std::string> _map_game;
        bool _isNewMap;
        bool _isNewKey;
        int _key;
};

struct KeyNcurses {
    int code_lib;
    int code_core;
};

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

#endif /* !CLASS_NCURSES_HPP_ */
