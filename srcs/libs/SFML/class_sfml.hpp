/*
** EPITECH PROJECT, 2019
** class_sfml.hpp
** File description:
** class_sfml
*/

#ifndef CLASS_SFML_HPP_
    #define CLASS_SFML_HPP_

#include <SFML/Graphics.hpp>

class IDisplayModule {
        public:
            virtual ~IDisplayModule() = default;
            virtual void display_window() = 0;
            virtual void clear_window() = 0;
            virtual bool get_event() = 0;
            virtual bool run() = 0;
};

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
