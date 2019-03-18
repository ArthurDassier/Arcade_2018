/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../NCURSES/class_ncurses.hpp"
#include "class_sfml.hpp"
#include "dlloader.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    DLLoader <IGraphic> instance(av[1]);
    IGraphic *module = instance.getInstance();

    while (module->runGraph());
    delete module;
    return (0);
}
