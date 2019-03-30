/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include <thread>
#include <chrono>

#include "Core.hpp"
#include "IGame.hpp"
#include "IGraphic.hpp"
#include "dlloader.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    Core core(av[1]);

    core.startCore();
    return (0);
}
// std::this_thread::sleep_for(std::chrono::milliseconds(10));