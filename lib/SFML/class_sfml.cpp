/*
** EPITECH PROJECT, 2019
** class_sfml.cpp
** File description:
** class_sfml
*/

#include "class_sfml.hpp"

class_sfml::class_sfml()
{
    _wind = std::make_shared<sf::RenderWindow>();
    _wind->create(sf::VideoMode(800, 600), "My window");
}

class_sfml::~class_sfml()
{
    _wind->close();
}

bool class_sfml::get_event()
{
    while (_wind->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            return (true);
        if (_event.type == sf::Event::KeyPressed) {
            std::cout << _event.key.code << std::endl;
            translateKey();
        }
    }
    return (false);
}

bool class_sfml::runGraph() 
{
    if (!(_wind->isOpen()))
        return (false);
    _wind->clear();
    if (get_event())
        return (false);
    _wind->display();
    return (true);
}

void class_sfml::setMap()
{

}

void class_sfml::translateKey()
{
    for (size_t i = 0; KeySFML[i].code_lib != 1000; i++)
        if (_event.key.code == KeySFML[i].code_lib) {
            setLastKey(KeySFML[i].code_core);
            break;
        }
}

void class_sfml::setIsNewMap(bool newMap)
{
    _isNewMap = newMap;
}

bool class_sfml::getIsNewMap(void) const
{
    return (_isNewMap);
}

void class_sfml::setIsNewKey(bool newKey)
{
    _isNewKey = newKey;
}

bool class_sfml::getIsNewKey(void) const
{
    return (_isNewKey);
}

void class_sfml::setLastKey(int key)
{
    _key = key;
}

int class_sfml::getLastKey(void) const
{
    return (_key);
}

extern "C"
{
    IGraphic *entryPoint(void)
    {
        class_sfml *instance = new class_sfml();
        return (instance);
    }
}