/*
** EPITECH PROJECT, 2019
** class_sdl.cpp
** File description:
** class_sdl
*/

#include "class_sdl.hpp"

class_sdl::class_sdl()
{
    SDL_Init(SDL_INIT_VIDEO);
    _win = SDL_CreateWindow("Tutoriel de merde",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    600, 600, SDL_WINDOW_OPENGL);
}

class_sdl::~class_sdl()
{
    SDL_DestroyWindow(_win);
    SDL_Quit();
}

bool class_sdl::runGraph()
{
    while (SDL_PollEvent(&_e)) {
        if (_e.type == SDL_WINDOWEVENT) {
            if (_e.window.event == SDL_WINDOWEVENT_CLOSE) {
                return (false);
            }
        }
        if (_e.type == SDL_KEYDOWN)
            translateKey();
    }
    return (true);
}

void class_sdl::setMap()
{}

void class_sdl::translateKey()
{
    for(size_t i = 0; KeySdl[i].code_lib != 1000; ++i) {
        if (_e.key.keysym.sym == KeySdl[i].code_lib) {
            setLastKey(KeySdl[i].code_core);
            return;
        }
    }
}

void class_sdl::setIsNewMap(bool NewMap)
{
    _isNewMap = NewMap;
}

bool class_sdl::getIsNewMap(void) const
{
    return (_isNewMap);
}

void class_sdl::setIsNewKey(bool NewKey)
{
    _isNewKey = NewKey;
}

bool class_sdl::getIsNewKey(void) const
{
    return (_isNewKey);
}

void class_sdl::setLastKey(int key)
{
    _key = key;
}

int class_sdl::getLastKey(void) const
{
    return (_key);
}

extern "C"
{
    IGraphic *entryPoint(void)
    {
        class_sdl *instance = new class_sdl();
        return (instance);
    }
}