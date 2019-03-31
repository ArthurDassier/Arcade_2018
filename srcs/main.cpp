/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

/*!
 * \file main.c
 * \brief Main fonction
 * \author Arthur.D
 * \version 0.1
 * \date 31 march 2019
 *
 * \mainpage Arcade Program
 * \content You can navigate throught this doc
 */

#include <thread>
#include <chrono>

#include "Core.hpp"
#include "IGame.hpp"
#include "IGraphic.hpp"
#include "dlloader.hpp"

/*!
 * \fn int main(int ac, char **av, char **env)
 * \brief Briefly checks for errors and launch the core
 *
 * \param int ac, char **av and the char **env variables
 * \return 0 if everything went ok or 84 is case of errors
 */

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