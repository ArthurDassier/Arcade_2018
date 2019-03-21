/*
** EPITECH PROJECT, 2019
** class_sdl.cpp
** File description:
** class_sdl
*/

#include "class_sdl.hpp"

class_sdl::class_sdl() :
    _wind(nullptr, SDL_DestroyWindow),
    _ren(nullptr, SDL_DestroyRenderer)
{
    SDL_Init(SDL_INIT_VIDEO);
    _wind.reset(SDL_CreateWindow("SDL 2 window",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL));
    if (_wind == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
    }
    _ren.reset(SDL_CreateRenderer(_wind.get(), -1, 0));
    if (_ren == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
    }
}

class_sdl::~class_sdl()
{
    for (auto it = _map->begin(); it != _map->end(); ++it) {
        for(auto it_str = it->begin(); it_str != it->end(); ++it_str)
                SDL_DestroyTexture(it_str->second);
    }
    IMG_Quit();
    SDL_Quit();
}

void class_sdl::print_textures()
{
    SDL_Rect dstrect;
    SDL_Rect dstrect2;
    SDL_Rect dstrect3;

    dstrect.x = 0;
    dstrect.y = 0;
    dstrect.w = 30;
    dstrect.h = 30;

    dstrect2.x = 10;
    dstrect2.y = 5;
    dstrect2.w = 8;
    dstrect2.h = 8;

    dstrect3.x = 12;
    dstrect3.y = 8;
    dstrect3.w = 5;
    dstrect3.h = 5;
    for (auto it = _map->begin(); it != _map->end(); ++it) {
        for(auto it_str = it->begin(); it_str != it->end(); ++it_str) {
            switch (it_str->first) {
                case '1':
                    SDL_RenderCopy(_ren.get(), it_str->second, NULL, &dstrect);
                    break;
                case '2':
                    SDL_RenderCopy(_ren.get(), it_str->second, NULL, &dstrect3);
                    break;
                case '3':
                    SDL_RenderCopy(_ren.get(), it_str->second, NULL, &dstrect2);
                    break;
                case '4':
                    SDL_RenderCopy(_ren.get(), it_str->second, NULL, &dstrect);
                    break;
                default:
                    break;
            }
            dstrect.x += 30;
            dstrect2.x += 30;
            dstrect3.x += 30;
        }
        dstrect.x = 0;
        dstrect2.x = 10;
        dstrect3.x = 12;
        dstrect.y += 30;
        dstrect2.y += 30;
        dstrect3.y += 30;
    }
    SDL_RenderPresent(_ren.get());
}

bool class_sdl::runGraph()
{
    SDL_RenderClear(_ren.get());
    while (SDL_PollEvent(&_e)) {
        if (_e.type == SDL_WINDOWEVENT) {
            if (_e.window.event == SDL_WINDOWEVENT_CLOSE)
                return (false);
        }
        if (_e.type == SDL_KEYDOWN)
            translateKey();
    }
    print_textures();
    SDL_Delay(2);
    return (true);
}

void class_sdl::load_textures()
{
    SDL_Surface *wall = IMG_Load("./textures/wall.png");
    SDL_Surface *point = IMG_Load("./textures/point.png");
    SDL_Surface *gros_point = IMG_Load("./textures/big_point.png");
    SDL_Surface *pacman = IMG_Load("./textures/pacman.png");

    if (!pacman || !wall || !gros_point || !point) {
        std::cout << "IMG_Load: " << IMG_GetError() << std::endl;
        return;
    }
    for (auto it = _map->begin(); it != _map->end(); ++it) {
        for(auto it_str = it->begin(); it_str != it->end(); ++it_str) {
            switch (it_str->first) {
                case '1':
                    it_str->second = SDL_CreateTextureFromSurface(_ren.get(), wall);
                    break;
                case '2':
                    it_str->second = SDL_CreateTextureFromSurface(_ren.get(), point);
                    break;
                case '3':
                    it_str->second = SDL_CreateTextureFromSurface(_ren.get(), gros_point);
                    break;
                case '4':
                    it_str->second = SDL_CreateTextureFromSurface(_ren.get(), pacman);
                    break;
                default:
                    break;
            }
        }
    }
    SDL_FreeSurface(pacman);
    SDL_FreeSurface(wall);
    SDL_FreeSurface(point);
    SDL_FreeSurface(gros_point);
}

void class_sdl::setMap()
{
    std::string line;
    std::ifstream file;

    _map = std::make_unique<std::vector<std::vector<std::pair<char, SDL_Texture *>>>>();
    file.open("./map.txt");
    if (!file.is_open())
        std::cout << "FAIL" << std::endl;
    while (!file.eof()) {
        getline(file, line);
        std::vector<std::pair<char, SDL_Texture *>> tmp;
        for (auto it = line.begin(); it != line.end(); ++it) {
            SDL_Texture *texture = nullptr;
            tmp.push_back(std::make_pair(*it, texture));
        }
        _map->push_back(tmp);
    }
    file.close();
    load_textures();
}

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