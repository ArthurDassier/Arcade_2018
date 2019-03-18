/*
** EPITECH PROJECT, 2019
** IGraphic.hpp
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
    #define IGRAPHIC_HPP_

#include <memory>

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
