/*
** EPITECH PROJECT, 2019
** IDisplayGame.hpp
** File description:
** IDisplayGame
*/

#ifndef IDISPLAYGAME_HPP_
    #define IDISPLAYGAME_HPP_

#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>

class IDisplayGame {
    public:
        virtual ~IDisplayGame() = default;
        virtual std::vector<std::string> &get_map() = 0;
        virtual int set_event() = 0;
};

#endif /* !IDISPLAYGAME_HPP_ */
