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
	PREV_LIB = 39
};

class Core {
    public:
        Core(std::string libName);
        ~Core();

        //Members
        void loadNewGame(std::string name);
        void loadNewLibGraph(std::string name);

        void handleGame(void);
        void handleMenu(void);

        bool startCore(void);

        void setIsNewKey(bool isNewKey);
        bool getIsNewKey(void) const;

        void setHaveGameLoad(bool haveGameLoad);
        bool getHaveGameLoad(void) const;

        void setKey(int Key);
        int getKey(void) const;

        void setActualLib();
        int getActualLib(void) const;

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

        bool _isNewKey;
        int _key;
        int _actualLib;
        bool _haveGameLoad = false;
};

#endif /* !CORE_HPP_ */