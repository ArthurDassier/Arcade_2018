/*
** EPITECH PROJECT, 2019
** Core.cpp
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(std::string libName)
{
    _libName = libName;
}

Core::~Core()
{
}

void Core::loadNewGame(std::string name)
{
}

void Core::loadNewLibGraph(std::string name)
{
    _libName = name;
}

void Core::handleGame(void)
{
}

void Core::handleMenu(void)
{
}

bool Core::startCore(void)
{
    DLLoader<IGraphic> instance(_libName);
    IGraphic *module = instance.getInstance();

    module->setMap();
    while (module->runGraph());
    if (module->getLastKey() == 39 || module->getLastKey() == 38) {
        delete module;
        return (true);
    }
    delete module;
    return (false);
}

void Core::setIsNewKey(bool isNewKey)
{
    _isNewKey = isNewKey;
}

bool Core::getIsNewKey(void) const
{
    return (_isNewKey);
}

void Core::setHaveGameLoad(bool haveGameLoad)
{
    _haveGameLoad = haveGameLoad;
}

bool Core::getHaveGameLoad(void) const
{
    return (_haveGameLoad);
}

void Core::setKey(int key)
{
    _key = key;
}

int Core::getKey(void) const
{
    return (_key);
}

void Core::setActualLib()
{
    _actualLib = _actualLib == 2 ? 0 : _actualLib + 1;
}

int Core::getActualLib(void) const
{
    return (_actualLib);
}