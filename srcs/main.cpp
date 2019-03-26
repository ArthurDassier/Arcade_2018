/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "IGame.hpp"
#include <thread>
#include <chrono>

#include "Core.hpp"
#include "IGraphic.hpp"
#include "dlloader.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    Core core(av[1]);
    std::vector<std::string> _libs;
    size_t i = 0;

    _libs.push_back("lib_arcade_ncurses.so");
    _libs.push_back("lib_arcade_sfml.so");
    _libs.push_back("lib_arcade_sdl.so");
    for (; i < _libs.size(); i++)
        if (_libs.at(i) == av[1])
            break;         
    core.setMap();
    while (core.startCore()) {
        i = i == 2 ? 0 : i + 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        core.loadNewLibGraph(_libs[i]);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    return (0);
}