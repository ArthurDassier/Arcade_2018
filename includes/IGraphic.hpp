/*
** EPITECH PROJECT, 2019
** IGraphic.hpp
** File description:
** IGraphic
*/

#pragma once

#include <memory>
#include <vector>
#include <fstream>
#include <functional>
#include <iostream>

#define SCREEN_HEIGHT 1000
#define SCREEN_WIDTH 1000

class IGraphic {
    public:
        virtual ~IGraphic() = default;

        //Members
        virtual bool runGraph() = 0;
        virtual void setMap(std::shared_ptr<std::vector<std::string>>) = 0;
        virtual void translateKey() = 0;

        virtual void setIsNewMap(bool) = 0;
        virtual bool getIsNewMap(void) const = 0;

        virtual void setIsNewKey(bool) = 0;
        virtual bool getIsNewKey(void) const = 0;

        virtual void setLastKey(int) = 0;
        virtual int getLastKey(void) const = 0;

        virtual void setScore(size_t) = 0;
        virtual size_t getScore() const = 0;

        virtual void setPathConfig(std::string) noexcept = 0;
        virtual std::string getPathConfig() const noexcept = 0;

        virtual void setIsNewPathConfig(bool) noexcept = 0;
        virtual bool getIsNewPathConfig() const noexcept = 0;

        virtual void buildMap(std::shared_ptr<std::vector<std::string>> = nullptr) = 0;
};

