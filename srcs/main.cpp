/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "IGraphic.hpp"
#include "dlloader.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    std::string lib (av[1]);
    std::string lib_path ("./lib/" + lib);
    DLLoader <IGraphic> instance(lib_path);
    IGraphic *module = instance.getInstance();

    module->setMap();
    while (module->runGraph());
    delete module;
    return (0);
}
