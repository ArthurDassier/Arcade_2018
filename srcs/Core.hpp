/*
** EPITECH PROJECT, 2019
** Core.hpp
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

#include "dlloader.hpp"
#include "IGraphic.hpp"
#include "IGame.hpp"

enum Commands {
    NEXT_GAME = 36,
    PREV_GAME = 37,
    NEXT_LIB = 38,
    PREV_LIB = 39,
    ENTER = 40
};

class Core {
    public:
        Core(std::string);
        ~Core();

        //Members
        void loadNewGame(std::string);
        void loadNewLibGraph(std::string);

        void handleGame(void);
        void handleMenu(void);

        bool startCore(void);

        void setIsNewKey(bool);
        bool getIsNewKey(void) const;

        void setHaveGameLoad(bool);
        bool getHaveGameLoad(void) const;

        void setKey(int);
        int getKey(void) const;

        void setActualLib(void);
        int getActualLib(void) const;

        void setMenuLib(int);
        int getMenuLib(void) const;

        void setMap(void);
        // std::shared_ptr<std::vector<std::string>> getMap(void) const;

    private:
        std::string _libName;
        std::string _gameName;
        
        IGraphic *_libModule;
        IGame *_gameModule;
        std::shared_ptr<std::vector<std::string>> _map;

        void *_frameTime;
        void *_frameClock;

        std::vector<std::string> _graphLibs;
        std::unique_ptr<IGraphic> _wpGraph;

        bool _isMenu;
        bool _isNewKey;
        int _key;
        int _actualLib;
        int _menuLib;
        bool _haveGameLoad = false;
};

#endif /* !CORE_HPP_ */