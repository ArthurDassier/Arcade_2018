/*
** EPITECH PROJECT, 2019
** Core.cpp
** File description:
** Core.cpp
*/

#include "Core.hpp"


/*!
 * \fn Core::Core(std::string libName)
 * \brief Construct the core, load the library given as argument
 *
 * \param std::string representing the libname
 */

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

/*!
 * \fn Core::~Core()
 * \brief Destroy the core by reseting the shared pointers
 *
 * \param void
 */

Core::~Core()
{
    _libModule.reset();
    _gameModule.reset();
}

/*!
 * \fn Core::mapMenu()
 * \brief Open the map file representing the menu
 *
 * \param void
 */

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

/*!
 * \fn Core::loadNewGame(std::string name)
 * \brief Load the game given in parameter
 *
 * \param std::string representing the game's name
 */

void Core::loadNewGame(std::string name)
{
    auto instance = std::make_shared<DLLoader<IGame *>>(name);

    _gameModule.reset();
    _instance_game = instance;
    std::shared_ptr<IGame> tmp(_instance_game->getInstance());
    _gameModule = tmp;
    _libModule->setPathConfig(_gameModule->getPathConfig());
    _libModule->setIsNewPathConfig(true);
    setHaveGameLoad(true);
}

/*!
 * \fn Core::loadMenu()
 * \brief Load the menu by reseting the map representing the menu in the graphical libraries
 *
 * \param void
 */

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

/*!
 * \fn void Core::loadNewLib(std::string lib)
 * \brief Load the lib by reseting _libmodule pointers to the new lib, acts like the class constructor
 *
 * \param std::string representing the lib's name
 */


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
    } else {
        _libModule->buildMap(_gameModule->getMap());
        _libModule->setMap(_gameModule->getMap());
        _libModule->setIsNewMap(true);
        _libModule->setPathConfig(_gameModule->getPathConfig());
    }
}


/*!
 * \fn void Core::handleGame(void)
 * \brief Actualize the map in the lib module in order to print it for the user
 *
 * \param void
 */

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

/*!
 * \fn void Core::startCore()
 * \brief Infinite loop that handle everything the program needs
 *
 * \param void
 */

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
