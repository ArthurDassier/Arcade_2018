/*
** EPITECH PROJECT, 2019
** class_sfml.hpp
** File description:
** class_sfml
*/

#ifndef CLASS_NCURSES_HPP_
    #define CLASS_NCURSES_HPP_

#include <ncurses.h>
#include "IDisplayModule.hpp"

class class_ncurses : public IDisplayModule
{
    public:
        class_ncurses();
        ~class_ncurses();

        void clear_window();
        void display_window();
        bool get_event();
        bool run();

    private:
};

#endif /* !CLASS_NCURSES_HPP_ */
