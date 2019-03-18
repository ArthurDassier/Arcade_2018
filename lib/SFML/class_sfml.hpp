/*
** EPITECH PROJECT, 2019
** class_sfml.hpp
** File description:
** class_sfml
*/

#ifndef CLASS_SFML_HPP_
    #define CLASS_SFML_HPP_

#include <SFML/Graphics.hpp>
#include "IDisplayModule.hpp"

class class_sfml : public IDisplayModule
{
    public:
        class_sfml();
        ~class_sfml();

        void clear_window();
        void display_window();
        bool get_event();
        bool run();

    private:
        sf::Event _event;
        sf::RenderWindow _window;
};

#endif /* !CLASS_SFML_HPP_ */
