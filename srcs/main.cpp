/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include <thread>
#include <chrono>

#include "Core.hpp"
#include "IGraphic.hpp"
#include "dlloader.hpp"

int main(int ac, char **av)
{
    Core core(av[1]);
    int i = 1;
    while (core.startCore()) {
        if (i > 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            core.loadNewLibGraph("./lib/lib_arcade_sdl.so");
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            core.loadNewLibGraph("./lib/lib_arcade_ncurses.so");
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        i *= -1;
    }
}

// int main(int ac, char **av)
// {
//     if (ac < 2)
//         return (84);
//     std::string lib (av[1]);
//     std::string lib_path ("./lib/" + lib);
//     DLLoader <IGraphic> instance(lib_path);
//     IGraphic *module = instance.getInstance();

//     module->setMap();
//     while (module->runGraph());
//     delete module;
//     return (0);
// }

// int main(int ac, char **av)
// {
//     if (ac < 2)
//         return (84);
//     Core *core = new Core(av[1]);
//     // Core core(av[1]);
//     std::cout << "handle game" << std::endl;
//     core->handleGame();
//     std::cout << "start core" << std::endl;
//     core->startCore();
//     // std::string lib (av[1]);
//     // std::string lib_path ("./lib/" + lib);
//     // DLLoader <IGraphic> instance(lib_path);
//     // // IGraphic *module = instance.getInstance();
//     // t_tmp tmp;
//     // tmp._libGraph = instance.getInstance();
    
//     // tmp._libGraph->setMap();
//     // while (tmp._libGraph->runGraph());
//     // delete tmp._libGraph;
//     // module->setMap();
//     // while (module->runGraph());
//     // delete module;
//     std::cout << "delete core" << std::endl;
//     delete core;
//     return (0);
// }
