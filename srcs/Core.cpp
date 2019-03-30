/*
** EPITECH PROJECT, 2019
** Core.cpp
** File description:
** Core.cpp
*/

#include "Core.hpp"

Core::Core(std::string libName) :
    _libName("./lib/" + libName),
    _pathConfig("./srcs/core/path_menu.config"),
    _isMenu(true),
    _haveGameLoad(false)
{
    auto instance = std::make_shared<DLLoader<IGraphic *>>(_libName);
    _instance = instance;
    std::shared_ptr<IGraphic> tmp(_instance->getInstance());
    _libModule = tmp;
    _libModule->setPathConfig(_pathConfig);
    _libModule->setIsNewPathConfig(true);
    mapMenu();
    _libModule->buildMap(_mapMenu);
    _libModule->setMap(_mapMenu);
    _libModule->setIsNewMap(true);
    _parsing.setFilename(_pathConfig);
    _parsing.readFile();
}

Core::~Core()
{
    _libModule.reset();
}

void Core::mapMenu()
{
    std::fstream filename;
    std::string line;

    filename.open("./srcs/core/map_menu.config");
    _mapMenu = std::make_shared<std::vector<std::string>>();
    while(getline(filename, line))
        _mapMenu->push_back(line);
    filename.close();
}

void Core::loadNewGame(std::string name)
{
    auto instance = std::make_shared<DLLoader<IGame *>>(name);
    _instance_game = instance;
    std::shared_ptr<IGame> tmp(_instance_game->getInstance());
    _gameModule = tmp;
    _libModule->setPathConfig(_gameModule->getPathConfig());
    _libModule->setIsNewPathConfig(true);
    setHaveGameLoad(true);
}

void Core::loadMenu()
{
    _libModule->setPathConfig(_pathConfig);
    _libModule->setIsNewPathConfig(true);
    mapMenu();
    _libModule->setMap(_mapMenu);
    _libModule->setIsNewMap(true);
    _parsing.setFilename(_pathConfig);
    _parsing.readFile();
}

void Core::loadNewLib(std::string lib)
{
    auto instance = std::make_shared<DLLoader<IGraphic *>>(lib);

    _libModule.reset();
    _instance = instance;
    std::shared_ptr<IGraphic> tmp(_instance->getInstance());
    _libModule = tmp;
    _libModule->setPathConfig(_pathConfig);
    _libModule->setIsNewPathConfig(true);
    if (!_haveGameLoad) {
        _libModule->buildMap(_mapMenu);
        _libModule->setMap(_mapMenu);
        _libModule->setIsNewMap(true);
    } else
        _libModule->setPathConfig(_gameModule->getPathConfig());
}

void Core::handleGame(void)
{
    _gameModule->runGame();
    if (_gameModule->getIsNewMap()) {
        _gameModule->setIsNewMap(false);
        _libModule->setMap(_gameModule->getMap());
        _libModule->setIsNewMap(true);
    }
    //_libModule->setScore(_gameModule->getScore());
    _gameModule->setLastKey(_libModule->getLastKey());
}

void Core::startCore()
{
    std::ifstream ncurses("./lib/lib_arcade_ncurses.so");
    std::ifstream sdl("./lib/lib_arcade_sdl2.so");
    std::ifstream sfml("./lib/lib_arcade_sfml.so");

    while (42) {
        if (_libModule->getIsNewKey()) {
            _libModule->setIsNewKey(false);
            if (_libModule->getLastKey() == ENTER) {
                if (_isMenu) {
                    loadNewGame(_parsing.getResult()[3].name);
                    _isMenu = false;
                } else {
                    _haveGameLoad = false;
                    loadMenu();
                    _isMenu = true;
                }
            } else if (_libModule->getLastKey() == NCURSES) {
                if (ncurses.good())
                    loadNewLib("./lib/lib_arcade_ncurses.so");
            } else if (_libModule->getLastKey() == SFML) {
                if (sfml.good())
                    loadNewLib("./lib/lib_arcade_sfml.so");
            } else if (_libModule->getLastKey() == SDL) {
                if (sdl.good())
                    loadNewLib("./lib/lib_arcade_sdl2.so");
            }
        }
        if (getHaveGameLoad())
            handleGame();
        if (_libModule->runGraph())
            break;
    }
    ncurses.close();
    sdl.close();
    sfml.close();
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
