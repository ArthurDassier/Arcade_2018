/*
** EPITECH PROJECT, 2019
** IGame.hpp
** File description:
** IGame
*/

#ifndef IGAME_HPP_
    #define IGAME_HPP_

#include <algorithm>
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>

class IGame {
    public:
        virtual ~IGame() = default;

        virtual bool runGame() = 0;
        virtual std::shared_ptr<std::vector<std::string>> getMap(void) const = 0;
        virtual void setMap(std::shared_ptr<std::vector<std::string>> map) = 0;

        virtual bool getIsNewMap(void) const = 0;
        virtual void setIsNewMap(bool isNewMap) = 0;

        virtual void setIsNewKey(bool isNewKey) = 0;
        virtual bool getIsNewKey(void) const = 0;

        virtual void setLastKey(int key) = 0;
        virtual int getLastKey(void) const = 0;

        virtual void setScore(size_t score) = 0;
        virtual size_t getScore(void) const = 0;

        virtual void moveDown(void) = 0;
        virtual void moveLeft(void) = 0;
        virtual void moveRight(void) = 0;
        virtual void moveUp(void) = 0;

        enum Graphics {
            NOTHING = '0',
            WALL = '1',
            POINT = '2',
            PLAYER = '3',
            ENEMY = '4',
            BONUS = '5'
        };
};

#endif /* !IGAME_HPP_ */
