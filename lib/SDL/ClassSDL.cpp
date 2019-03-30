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
    _isNewPathConfig(false),
    _isNewMap(false),
    _isNewKey(false)
{
    SDL_Init(SDL_INIT_VIDEO);
    _wind.reset(SDL_CreateWindow("Arcade SDL2",
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
    SDL_Quit();
}

void ClassSDL::displayGame()
{
    std::ifstream ncurses("./lib/lib_arcade_ncurses.so");
    std::ifstream sdl("./lib/lib_arcade_sdl2.so");
    std::ifstream sfml("./lib/lib_arcade_sfml.so");
    SDL_Rect dstrect = {0, 0, 0, 0};
    int x, y = 0;

    for (auto it_y = _map->begin(); it_y != _map->end(); ++it_y) {
        for(auto it_x = it_y->begin(); it_x != it_y->end(); ++it_x) {
            dstrect = {x, y, _parsing._sprite.at(it_x->first - 48).sizeX, _parsing._sprite.at(it_x->first - 48).sizeY};
            if (it_x->first != NOTHING)
                SDL_RenderCopy(_ren.get(), it_x->second.get(), NULL, &dstrect);
            x += _parsing._sprite.at(it_x->first - 48).sizeX;
        }
        x = 0;
        y += _parsing._sprite.at(it_y->begin()->first - 48).sizeY;
    }
    ncurses.close();
    sdl.close();
    sfml.close();
    SDL_RenderPresent(_ren.get());
}

bool ClassSDL::runGraph()
{
    if (getIsNewPathConfig() == true) {
        _parsing.clearData();
        setIsNewPathConfig(false);
        _parsing.setFilename(getPathConfig());
        _parsing.readFile();
        setMapTexture();
    }
    while (SDL_PollEvent(&_e)) {
        if (_e.type == SDL_WINDOWEVENT) {
            if (_e.window.event == SDL_WINDOWEVENT_CLOSE)
                return (true);
        }
        if (_e.type == SDL_KEYDOWN) {
            translateKey();
            setIsNewKey(true);
        }
    }
    if (_isNewMap) {
        setMapTexture();
        SDL_RenderClear(_ren.get());
        displayGame();
        _isNewMap = false;
    }
    return (false);
}

void ClassSDL::setMapTexture()
{
    auto parsingResult = _parsing.getResult();
    float x = 0;
    float y = 0;

    _textures.clear();
    for (auto it = parsingResult.begin(); it != parsingResult.end(); ++it) {
        SDL_Rect size = {it->sizeX, it->sizeY, 0, 0};
        std::shared_ptr<SDL_Surface> tmp = nullptr;
        tmp.reset(SDL_LoadBMP(it->path.c_str()), SDL_FreeSurface);
        _textures.push_back(std::make_pair(size, tmp));
    }
    for (auto it_y = _map->begin(); it_y != _map->end(); ++it_y) {
        for(auto it_x = it_y->begin(); it_x != it_y->end(); ++it_x) {
            if (it_x->first == 'a')
                continue;
            it_x->second.reset(SDL_CreateTextureFromSurface(_ren.get(),
            _textures.at(it_x->first - 48).second.get()));
        }
    }
}

void ClassSDL::buildMap(std::shared_ptr<std::vector<std::string>> map = nullptr)
{
    _map = std::make_unique<std::vector<std::vector<std::pair<char, std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>>>>>();

    for (auto it_y = map->begin(); it_y != map->end(); ++it_y) {
        std::vector<std::pair<char, std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>>> tmp;
        for (auto it_x = it_y->begin(); it_x != it_y->end(); ++it_x) {
            std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture = {nullptr, SDL_DestroyTexture};
            tmp.push_back(std::make_pair(*it_x, std::move(texture)));
        }
        _map->emplace_back(std::move(tmp));
    }
}

void ClassSDL::setMap(std::shared_ptr<std::vector<std::string>> map)
{
    if (!map || !_map)
        return;
    auto it_my_map_y = _map->begin();

    for (auto it_y = map->begin(); it_y != map->end(); ++it_y, ++it_my_map_y) {
        auto it_my_map_x = it_my_map_y->begin();
        for (auto it_x = it_y->begin(); it_x != it_y->end(); ++it_x, ++it_my_map_x)
            it_my_map_x->first = *it_x;
    }
}

void ClassSDL::translateKey()
{
    for(size_t i = 0; KeySdl[i].code_lib != -1; ++i) {
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

void ClassSDL::setPathConfig(std::string path) noexcept
{
    _pathConfig = path;
}

std::string ClassSDL::getPathConfig() const noexcept
{
    return (_pathConfig);
}

void ClassSDL::setIsNewPathConfig(bool isNewPath) noexcept
{
    _isNewPathConfig = isNewPath;
}

bool ClassSDL::getIsNewPathConfig() const noexcept
{
    return (_isNewPathConfig);
}

extern "C"
{
    IGraphic *entryPoint(void)
    {
        ClassSDL *instance = new ClassSDL();
        return (instance);
    }
}