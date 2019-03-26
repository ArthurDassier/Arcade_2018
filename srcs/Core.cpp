/*
** EPITECH PROJECT, 2019
** Core.cpp
** File description:
** Core
*/

#include "Core.hpp"
#include "ClassSFML.hpp"

Core::Core(std::string libName)
{
    std::string libPath("./lib/" + libName);
    std::string gamePath("./games/lib_arcade_pacman.so");
    _libName = libPath;
    _gameName = gamePath;
    _isMenu = true;
    _actualLib = 0;
}

Core::~Core()
{
}

void Core::loadNewGame(std::string name)
{
    std::string gamePath("./games/" + name);
    _gameName = gamePath;
}

void Core::loadNewLibGraph(std::string name)
{
    std::string libPath("./lib/" + name);
    _libName = libPath;
}

void Core::handleGame(void)
{
    // std::this_thread::sleep_for(std::chrono::milliseconds(160));
    // _gameModule->setIsNewKey(_libModule->getIsNewKey());
    _gameModule->runGame();
    _libModule->setMap(_gameModule->getMap());
    _libModule->setScore(_gameModule->getScore());
    _gameModule->setLastKey(_libModule->getLastKey());
    // _libModule->setIsNewKey(_gameModule->getIsNewKey());
}

void Core::handleMenu(void)
{
    std::string line;
    std::ifstream map_file("./srcs/core/menu.txt");

    _map = std::make_shared<std::vector<std::string>>();
    if (map_file) {
        while (getline(map_file, line))
            _map->push_back(line);
        map_file.close();
    }
    _libModule->setMap(_map);
}

bool Core::startCore(void)
{
    DLLoader<IGraphic> instance(_libName);
    _libModule = instance.getInstance();
    DLLoader<IGame> game_instance(_gameName);
    _gameModule = game_instance.getInstance();
    _gameModule->setMap(_map);

    while (true) {
        if (_isMenu)
            handleMenu();
        else
            handleGame();
        if (!_libModule->runGraph()) {
            if (_libModule->getIsNewKey() && (_libModule->getLastKey() == PREV_LIB || _libModule->getLastKey() == NEXT_LIB)) {
                _libModule->setIsNewKey(false);
                delete _libModule;
                delete _gameModule;
                return (true);
            } else if (_libModule->getIsNewKey() && _libModule->getLastKey() == ENTER) {
                _libModule->setIsNewKey(false);
                if (_isMenu) {
                    setMap();
                    delete _libModule;
                    _libModule = instance.getInstance();
                    _libModule->setMap(_gameModule->getMap());
                    _gameModule->setMap(_map);
                    _isMenu = false;
                } else
                    _isMenu = true;
            } else
                break;
        }
    }
    std::cout << "Score: " << _gameModule->getScore() << std::endl;
    delete _libModule;
    delete _gameModule;
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

void Core::setMenuLib(int menuLib)
{
    std::cout << "Menu : " << menuLib << std::endl;
    _menuLib = menuLib;
}

int Core::getMenuLib(void) const
{
    return (_menuLib);
}

void Core::setMap(void)
{
    std::string line;
    std::ifstream map_file("map.txt");

    _map = std::make_shared<std::vector<std::string>>();
    if (map_file) {
        while (getline(map_file, line))
            _map->push_back(line);
        map_file.close();
    }
}