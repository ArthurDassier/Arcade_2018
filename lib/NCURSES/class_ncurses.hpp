/*
** EPITECH PROJECT, 2019
** class_sfml.hpp
** File description:
** class_sfml
*/

#ifndef CLASS_SFML_HPP_
    #define CLASS_SFML_HPP_

#include <ncurses.h>

class IDisplayModule {
        public:
            virtual ~IDisplayModule() = default;
            virtual void display_window() = 0;
            virtual void clear_window() = 0;
            virtual bool get_event() = 0;
            virtual bool run() = 0;
};

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

#endif /* !CLASS_SFML_HPP_ */
