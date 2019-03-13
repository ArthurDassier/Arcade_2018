/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "class_ncurses.hpp"
#include "class_sfml.hpp"
#include "dlloader.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    DLLoader <IDisplayModule> instance(av[1]);
    IDisplayModule *module = instance.getInstance();

    while (module->run());
    return (0);
}
