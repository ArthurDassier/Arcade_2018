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
}

class_ncurses::~class_ncurses()
{
    endwin();
}

void class_ncurses::clear_window()
{
    clear();
    timeout(100);
    refresh();

}

void class_ncurses::display_window()
{
    printw("%s", "COUCOU\n");
}

bool class_ncurses::get_event()
{
    switch (getch()) {
        case 'q': return (true);
                break;
        default:
                break;
    }
    return (false);
}

bool class_ncurses::run()
{
    clear_window();
    display_window();
    if (get_event()) {
        clear_window();
        return (false);
    }
    return (true);
}

extern "C"
{
    IDisplayModule *entryPoint(void)
    {
        class_ncurses *instance = new class_ncurses();
        return (instance);
    }
}
