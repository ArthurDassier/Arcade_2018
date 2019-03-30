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

int main(int ac, char **av, char **env)
{
    if (ac < 2)
        return (84);
    if (env[0] == NULL)
        return (84);

    try {
        Core core(av[1]);
        core.startCore();
        return (0);
    } catch (...) {
        std::cerr << "The program stopped for an unknowed reason" << std::endl;
        return (84);
    }
}
// std::this_thread::sleep_for(std::chrono::milliseconds(10));