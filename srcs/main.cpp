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
 * \content Our architecture have been fully represented in a Draw.io : https://www.draw.io/?state=%7B%22ids%22:%5B%221Zq1VpeW_EqprgKpBIExYpuWdQAxUMRU4%22%5D,%22action%22:%22open%22,%22userId%22:%22107942588257674115967%22%7D#G1Zq1VpeW_EqprgKpBIExYpuWdQAxUMRU4
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
        std::cerr << "The program stopped for an unknow reason" << std::endl;
        return (84);
    }
}
