/*
** EPITECH PROJECT, 2019
** IGame.hpp
** File description:
** IGame
*/

#ifndef IGAME_HPP_
    #define IGAME_HPP_

#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>

class IGame {
    public:
        virtual ~IGame() = default;

        virtual bool runGame() = 0;
        // virtual std::shared_ptr<ICore::map_t> getMap(void) const = 0;
        // virtual void setMap(std::shared_ptr<ICore::map_t> map) = 0;

        virtual bool getIsNewMap(void) const = 0;
        virtual void setIsNewMap(bool isNewMap) = 0;

        virtual void setIsNewKey(bool isNewKey) = 0;
        virtual bool getIsNewKey(void) const = 0;

        virtual void setLastKey(int key) = 0;
        virtual int getLastKey(void) const = 0;
};

#endif /* !IGAME_HPP_ */
