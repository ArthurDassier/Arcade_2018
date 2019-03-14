/*
** EPITECH PROJECT, 2019
** class_sdl.cpp
** File description:
** class_sdl
*/

#include <iostream>
#include "class_sdl.hpp"

class_sdl::class_sdl()
{
    SDL_Init(SDL_INIT_VIDEO);
    _window = SDL_CreateWindow("Tutoriel de merde",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    600, 600, SDL_WINDOW_OPENGL);
}

class_sdl::~class_sdl()
{
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void class_sdl::clear_window()
{

}

void class_sdl::display_window()
{

}

bool class_sdl::get_event()
{
    while (SDL_PollEvent(&_event)) {
        if (_event.type == SDL_WINDOWEVENT) {
            if (_event.window.event == SDL_WINDOWEVENT_CLOSE) {
                return (true);
            }
        }
    }
    return (false);
}

bool class_sdl::run()
{
    if (get_event())
        return (false);
    return (true);
}

extern "C"
{
    IDisplayModule *entryPoint(void)
    {
        class_sdl *instance = new class_sdl();
        return (instance);
    }
}