/*
** EPITECH PROJECT, 2019
** class_sfml.cpp
** File description:
** class_sfml
*/

#include <iostream>
#include "class_sfml.hpp"

class_sfml::class_sfml()
{
    _window.create(sf::VideoMode(600, 600), "Game",
    sf::Style::Titlebar | sf::Style::Close);
}

class_sfml::~class_sfml()
{
    _window.close();
}

void class_sfml::clear_window()
{
    _window.clear();
}

void class_sfml::display_window()
{
    _window.display();
}

bool class_sfml::get_event()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            return (true);
    }
    return (false);
}

bool class_sfml::run()
{
    if (!(_window.isOpen()))
        return (false);
    clear_window();
    if (get_event())
        return (false);
    display_window();
    return (true);
}

extern "C"
{
    IDisplayModule *entryPoint(void)
    {
        class_sfml *instance = new class_sfml();
        return (instance);
    }
}