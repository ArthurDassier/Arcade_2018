/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "class_sfml.hpp"
#include "dlloader.hpp"

int main(int ac, char **av)
{
    DLLoader <IDisplayModule> instance("./lib.so");
    IDisplayModule *module = instance.getInstance();

    while (module->run());
    return (0);
}
