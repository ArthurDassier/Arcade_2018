/*
** EPITECH PROJECT, 2019
** ClassSDL.cpp
** File description:
** ClassSDL
*/

#include "ClassSDL.hpp"

ClassSDL::ClassSDL() :
    _wind(nullptr, SDL_DestroyWindow),
    _ren(nullptr, SDL_DestroyRenderer)
{
    SDL_Init(SDL_INIT_VIDEO);
    _wind.reset(SDL_CreateWindow("SDL 2 window",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL));
    if (_wind == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    _ren.reset(SDL_CreateRenderer(_wind.get(), -1, 0));
    if (_ren == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
}

ClassSDL::~ClassSDL()
{
    for (auto it = _map->begin(); it != _map->end(); ++it) {
        for(auto it_str = it->begin(); it_str != it->end(); ++it_str)
                SDL_DestroyTexture(it_str->second);
    }
    SDL_Quit();
}

void ClassSDL::displayGame()
{
}

void ClassSDL::print_textures()
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
                case WALL:
                    SDL_RenderCopy(_ren.get(), it_str->second, NULL, &dstrect);
                    break;
                case POINT:
                    SDL_RenderCopy(_ren.get(), it_str->second, NULL, &dstrect3);
                    break;
                case BONUS:
                    SDL_RenderCopy(_ren.get(), it_str->second, NULL, &dstrect2);
                    break;
                case PLAYER:
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

bool ClassSDL::runGraph()
{
    SDL_RenderClear(_ren.get());
    while (SDL_PollEvent(&_e)) {
        if (_e.type == SDL_WINDOWEVENT) {
            if (_e.window.event == SDL_WINDOWEVENT_CLOSE)
                return (false);
        }
        if (_e.type == SDL_KEYDOWN) {
            translateKey();
            setIsNewKey(true);
            if (getLastKey() == 38 || getLastKey() == 39)
                return (false);
        }
        if (_e.type == SDL_KEYUP)
            setIsNewKey(false);
    }
    print_textures();
    SDL_Delay(2);
    return (true);
}

void ClassSDL::load_textures()
{
    SDL_Surface *wall = SDL_LoadBMP("./textures/wall.bmp");
    SDL_Surface *point = SDL_LoadBMP("./textures/point.bmp");
    SDL_Surface *gros_point = SDL_LoadBMP("./textures/big_point.bmp");
    SDL_Surface *pacman = SDL_LoadBMP("./textures/pacman.bmp");

    if (!pacman || !wall || !gros_point || !point) {
        std::cout << "BMP_Load: " << SDL_GetError() << std::endl;
        return;
    }
    for (auto it = _map->begin(); it != _map->end(); ++it) {
        for(auto it_str = it->begin(); it_str != it->end(); ++it_str) {
            switch (it_str->first) {
                case WALL:
                    it_str->second = SDL_CreateTextureFromSurface(_ren.get(), wall);
                    break;
                case POINT:
                    it_str->second = SDL_CreateTextureFromSurface(_ren.get(), point);
                    break;
                case BONUS:
                    it_str->second = SDL_CreateTextureFromSurface(_ren.get(), gros_point);
                    break;
                case PLAYER:
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

void ClassSDL::setMap(std::shared_ptr<std::vector<std::string>> map)
{
    _map = std::make_unique<std::vector<std::vector<std::pair<char, SDL_Texture *>>>>();
    for (auto it = map->begin(); it != map->end(); ++it) {
        std::vector<std::pair<char, SDL_Texture *>> tmp;
        for (auto it_str = it->begin(); it_str != it->end(); ++it_str) {
            SDL_Texture *texture = nullptr;
            tmp.push_back(std::make_pair(*it_str, texture));
        }
        _map->push_back(tmp);
    }
    load_textures();
}

void ClassSDL::translateKey()
{
    for(size_t i = 0; KeySdl[i].code_lib != 1000; ++i) {
        if (_e.key.keysym.sym == KeySdl[i].code_lib) {
            setLastKey(KeySdl[i].code_core);
            return;
        }
    }
}

void ClassSDL::setIsNewMap(bool NewMap)
{
    _isNewMap = NewMap;
}

bool ClassSDL::getIsNewMap(void) const
{
    return (_isNewMap);
}

void ClassSDL::setIsNewKey(bool NewKey)
{
    _isNewKey = NewKey;
}

bool ClassSDL::getIsNewKey(void) const
{
    return (_isNewKey);
}

void ClassSDL::setLastKey(int key)
{
    _key = key;
}

int ClassSDL::getLastKey(void) const
{
    return (_key);
}

void ClassSDL::setScore(size_t score)
{
    _score = score;
}

size_t ClassSDL::getScore() const
{
    return (_score);
}

extern "C"
{
    IGraphic *entryPoint(void)
    {
        ClassSDL *instance = new ClassSDL();
        return (instance);
    }
}