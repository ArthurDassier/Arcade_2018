/*
** EPITECH PROJECT, 2019
** IGraphic.hpp
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
    #define IGRAPHIC_HPP_

#include <memory>
#include <vector>
#include <fstream>
#include <functional>
#include <iostream>

#define SCREEN_HEIGHT 630
#define SCREEN_WIDTH 570

enum Graphics {
    NOTHING = '0',
    WALL = '1',
    POINT = '2',
    PLAYER = '3',
    GHOST = '4',
    BONUS = '5'
};

class IGraphic {
    public:
        virtual ~IGraphic() = default;

        //Members
        virtual bool runGraph() = 0;
        virtual void setMap() = 0;
        virtual void translateKey() = 0;

        virtual void setIsNewMap(bool) = 0;
        virtual bool getIsNewMap(void) const = 0;

        virtual void setIsNewKey(bool) = 0;
        virtual bool getIsNewKey(void) const = 0;

        virtual void setLastKey(int) = 0;
        virtual int getLastKey(void) const = 0;
};

#endif /* !IGRAPHIC_HPP_ */
