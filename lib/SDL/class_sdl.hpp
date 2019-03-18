/*
** EPITECH PROJECT, 2019
** class_sdl.hpp
** File description:
** class_sdl
*/

#ifndef CLASS_SDL_HPP_
    #define CLASS_SDL_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GLES3/gl3.h>
#include "IDisplayModule.hpp"

class class_sdl : public IDisplayModule
{
    public:
        class_sdl();
        ~class_sdl();

        void clear_window();
        void display_window();
        bool get_event();
        bool run();

    private:
        SDL_Window *_window;
        SDL_Event _event;
};

#endif /* !CLASS_SDL_HPP_ */
