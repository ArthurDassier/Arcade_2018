/*
** EPITECH PROJECT, 2019
** class_ncurses.cpp
** File description:
** class_ncurses
*/

#include <iostream>
#include "class_ncurses.hpp"

class_ncurses::class_ncurses()
{
    initscr();
    curs_set(FALSE);
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    _key = 999;
}

class_ncurses::~class_ncurses()
{
    endwin();
}

bool class_ncurses::get_event()
{
    _c = getch();
    switch (_c) {
        case 'Q': return (true);
            break;
        default:
            translateKey();
            break;
    }
    return (false);
}

bool class_ncurses::runGraph()
{
    clear();
    //printw("%s", "COUCOU\n");
    printw("%d\n", this->getLastKey());
    if (get_event())
        return (false);
    timeout(100);
    refresh();
    return (true);
}

void class_ncurses::setMap()
{

}

void class_ncurses::translateKey()
{
    if (_c != ERR) {
        for (size_t i = 0; KeyNcurses[i].code_lib != 1000; ++i) {
            if (_c == KeyNcurses[i].code_lib) {
                this->setLastKey(KeyNcurses[i].code_core);
                break;
            }
        }
    }
}

void class_ncurses::setIsNewMap(bool NewMap)
{
    _isNewMap = NewMap;
}

bool class_ncurses::getIsNewMap(void) const
{
    return (_isNewMap);
}

void class_ncurses::setIsNewKey(bool NewKey)
{
    _isNewKey = NewKey;
}

bool class_ncurses::getIsNewKey(void) const
{
    return (_isNewKey);
}

void class_ncurses::setLastKey(int key)
{
    _key = key;
}

int class_ncurses::getLastKey(void) const
{
    return (_key);
}

extern "C"
{
    IGraphic *entryPoint(void)
    {
        class_ncurses *instance = new class_ncurses();
        return (instance);
    }
}
