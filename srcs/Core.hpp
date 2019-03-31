/*
** EPITECH PROJECT, 2019
** Core.hpp
** File description:
** Core
*/

#pragma once

#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include "ParsingConfig.hpp"
#include "dlloader.hpp"
#include "IGraphic.hpp"
#include "IGame.hpp"

enum Commands {
    NCURSES = 9,
    SFML = 10,
    SDL = 11,
    ENTER = 40
};

/*! \class Core
* \brief Class representing the core
*
*  This class handle of the logic of the program, it loads the libraires and the games
*  it can switch from libraries and games at any moments
*/

class Core {
    public:
        Core(std::string);
        ~Core();

        //Members
        void loadNewGame(std::string);
        void loadNewLib(std::string);

        void handleGame(void);
        void handleMenu(void);

        void startCore(void);

        void setIsNewKey(bool);
        bool getIsNewKey(void) const;

        void setHaveGameLoad(bool);
        bool getHaveGameLoad(void) const;

        void setKey(int);
        int getKey(void) const;

        void mapMenu();

        void loadMenu();

        void setMap(std::shared_ptr<std::vector<std::string>>);
        std::shared_ptr<std::vector<std::string>> getMap(void) const;

        std::string getNextLib(enum Commands);

        inline void setNumPathLib(size_t num) noexcept;
        inline size_t getNumPathLib() const noexcept;

    private:
        std::string _libName;
        std::string _gameName;

        std::string _pathConfig;

        std::shared_ptr<std::vector<std::string>> _mapMenu;

        ParsingConfig _parsing;



        std::shared_ptr<DLLoader<IGraphic *>> _instance;
        std::shared_ptr<IGraphic> _libModule;
        std::shared_ptr<DLLoader<IGame *>> _instance_game;
        std::shared_ptr<IGame> _gameModule;

        std::shared_ptr<std::vector<std::string>> _map;

        std::vector<std::string> _graphLibs;
        std::unique_ptr<IGraphic> _wpGraph;

        bool _isMenu;
        bool _isNewKey;
        int _key;
        int _menuLib;
        bool _haveGameLoad;

        std::vector<std::string> _pathLib;
        std::vector<std::string> _pathGames;
        size_t _numPathLib = 0;
};
