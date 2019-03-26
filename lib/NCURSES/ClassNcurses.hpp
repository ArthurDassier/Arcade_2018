/*
** EPITECH PROJECT, 2019
** ClassNcurses.hpp
** File description:
** ClassNcurses
*/

#ifndef CLASS_NCURSES_HPP_
    #define CLASS_NCURSES_HPP_

#include <ncurses.h>
#include "IGraphic.hpp"

class ClassNcurses : public IGraphic
{
    public:
        ClassNcurses();
        ~ClassNcurses();

        //Members
        bool getEvent();
        bool runGraph();
        void setMap(std::shared_ptr<std::vector<std::string>>);
        void translateKey();
        void setMapTexture();

        void setIsNewMap(bool);
        bool getIsNewMap(void) const;

        void setIsNewKey(bool);
        bool getIsNewKey(void) const;

        void setLastKey(int);
        int getLastKey(void) const;

        void setScore(size_t);
        size_t getScore() const;

        void displayGame();

        //pour le menu
        int get_input();
        std::string get_string();
        char translate_for_menu(int);

    private:
        std::unique_ptr<std::vector<std::string>> _map;
        WINDOW *_window;
        int _c;
        bool _isNewMap;
        bool _isNewKey;
        size_t _score;
        int _key;
        std::string _str;
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
