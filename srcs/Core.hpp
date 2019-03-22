/*
** EPITECH PROJECT, 2019
** Core.hpp
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

#include <iostream>
#include <memory>

#include "dlloader.hpp"
#include "IGraphic.hpp"

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

    private:
        std::string _libName;
        IGraphic *_libGraph;

        std::vector<std::string> _graphLibs;
        std::unique_ptr<IGraphic> _wpGraph;

        bool _isNewKey;
        int _key;
        int _actualLib;
        bool _haveGameLoad = false;
};

#endif /* !CORE_HPP_ */