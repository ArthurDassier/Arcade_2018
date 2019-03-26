/*
** EPITECH PROJECT, 2019
** ClassSDL.cpp
** File description:
** ClassSDL
*/

#include "ClassSDL.hpp"

ClassSDL::ClassSDL() :
    _wind(nullptr, SDL_DestroyWindow),
    _ren(nullptr, SDL_DestroyRenderer),
    _animation(0),
    _stade1(nullptr, SDL_FreeSurface),
    _stade2(nullptr, SDL_FreeSurface),
    _stade3(nullptr, SDL_FreeSurface),
    _wall(nullptr, SDL_FreeSurface),
    _point(nullptr, SDL_FreeSurface),
    _gros_point(nullptr, SDL_FreeSurface),
    _pacman(nullptr, SDL_FreeSurface),
    _sfml(nullptr, SDL_FreeSurface),
    _sdl(nullptr, SDL_FreeSurface),
    _ncurses(nullptr, SDL_FreeSurface)
{
    SDL_Init(SDL_INIT_VIDEO);
    _wind.reset(SDL_CreateWindow("Arcade",
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
    _wall.reset(SDL_LoadBMP("./textures/wall.bmp"));
    _point.reset(SDL_LoadBMP("./textures/point.bmp"));
    _gros_point.reset(SDL_LoadBMP("./textures/big_point.bmp"));
    _pacman.reset(SDL_LoadBMP("./textures/tile000.bmp"));
    _sfml.reset(SDL_LoadBMP("./textures/lib_sfml.bmp"));
    _sdl.reset(SDL_LoadBMP("./textures/lib_sdl.bmp"));
    _ncurses.reset(SDL_LoadBMP("./textures/lib_ncurses.bmp"));
    _stade1.reset(SDL_LoadBMP("./textures/tile000.bmp"));
    _stade2.reset(SDL_LoadBMP("./textures/tile001.bmp"));
    _stade3.reset(SDL_LoadBMP("./textures/tile002.bmp"));
}

ClassSDL::~ClassSDL()
{
    SDL_Quit();
}

void ClassSDL::displayGame()
{
}

void ClassSDL::print_textures()
{
    std::ifstream ncurses("./lib/lib_arcade_ncurses.so");
    std::ifstream sdl("./lib/lib_arcade_sdl.so");
    std::ifstream sfml("./lib/lib_arcade_sfml.so");
    SDL_Rect dstrect = {0, 0, 30, 30};
    SDL_Rect dstrect2 = {10, 5, 8, 8};
    SDL_Rect dstrect3 = {12, 8, 5, 5};
    SDL_Rect dstrect4 = {-110, 0, 270, 270};

    for (auto it = _map->begin(); it != _map->end(); ++it) {
        for(auto it_str = it->begin(); it_str != it->end(); ++it_str) {
            switch (it_str->first) {
                case WALL:
                    SDL_RenderCopy(_ren.get(), it_str->second.get(), NULL, &dstrect);
                    break;
                case POINT:
                    SDL_RenderCopy(_ren.get(), it_str->second.get(), NULL, &dstrect3);
                    break;
                case BONUS:
                    SDL_RenderCopy(_ren.get(), it_str->second.get(), NULL, &dstrect);
                    break;
                case SDL:
                    if (sdl.good())
                        SDL_RenderCopy(_ren.get(), it_str->second.get(), NULL, &dstrect4);
                    break;
                case SFML:
                    if (sfml.good())
                        SDL_RenderCopy(_ren.get(), it_str->second.get(), NULL, &dstrect4);
                    break;
                case NCURSES:
                    if (ncurses.good())
                        SDL_RenderCopy(_ren.get(), it_str->second.get(), NULL, &dstrect4);
                    break;
                case PLAYER:
                    if (_animation == 0)
                        it_str->second.reset(SDL_CreateTextureFromSurface(_ren.get(), _stade1.get()));
                    else if (_animation == 1)
                        it_str->second.reset(SDL_CreateTextureFromSurface(_ren.get(), _stade2.get()));
                    else if (_animation == 2)
                        it_str->second.reset(SDL_CreateTextureFromSurface(_ren.get(), _stade3.get()));
                    else {
                        it_str->second.reset(SDL_CreateTextureFromSurface(_ren.get(), _stade2.get()));
                        _animation = -1;
                    }
                    SDL_RenderCopy(_ren.get(), it_str->second.get(), NULL, &dstrect);
                    ++_animation;
                    break;
                default:
                    break;
            }
            dstrect.x += 30;
            dstrect2.x += 30;
            dstrect3.x += 30;
            dstrect4.x += 30;
        }
        dstrect.x = 0;
        dstrect2.x = 10;
        dstrect3.x = 12;
        dstrect4.x = -110;
        dstrect.y += 30;
        dstrect2.y += 30;
        dstrect3.y += 30;
        dstrect4.y += 10;
    }
    ncurses.close();
    sdl.close();
    sfml.close();
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
            if (getLastKey() == 38 || getLastKey() == 39 || getLastKey() == 40)
                return (false);
        }
        if (_e.type == SDL_KEYUP)
            setIsNewKey(false);
    }
    print_textures();
    SDL_Delay(4);
    return (true);
}

void ClassSDL::load_textures()
{
    for (auto it = _map->begin(); it != _map->end(); ++it) {
        for(auto it_str = it->begin(); it_str != it->end(); ++it_str) {
            switch (it_str->first) {
                case WALL:
                    it_str->second.reset(SDL_CreateTextureFromSurface(_ren.get(), _wall.get()));
                    break;
                case POINT:
                    it_str->second.reset(SDL_CreateTextureFromSurface(_ren.get(), _point.get()));
                    break;
                case BONUS:
                    it_str->second.reset(SDL_CreateTextureFromSurface(_ren.get(), _gros_point.get()));
                    break;
                case PLAYER:
                    it_str->second.reset(SDL_CreateTextureFromSurface(_ren.get(), _pacman.get()));
                    break;
                case SDL:
                    it_str->second.reset(SDL_CreateTextureFromSurface(_ren.get(), _sdl.get()));
                    break;
                case SFML:
                    it_str->second.reset(SDL_CreateTextureFromSurface(_ren.get(), _sfml.get()));
                    break;
                case NCURSES:
                    it_str->second.reset(SDL_CreateTextureFromSurface(_ren.get(), _ncurses.get()));
                    break;
                default:
                    break;
            }
        }
    }
}

void ClassSDL::setMap(std::shared_ptr<std::vector<std::string>> map)
{
    _map = std::make_unique<std::vector<std::vector<std::pair<char, std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>>>>>();
    for (auto it = map->begin(); it != map->end(); ++it) {
        std::vector<std::pair<char, std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>>> tmp;
        for (auto it_str = it->begin(); it_str != it->end(); ++it_str) {
            std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture = {nullptr, SDL_DestroyTexture};
            tmp.push_back(std::make_pair(*it_str, std::move(texture)));
        }
        _map->emplace_back(std::move(tmp));
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