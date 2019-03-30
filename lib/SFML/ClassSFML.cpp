/*
** EPITECH PROJECT, 2019
** ClassSFML.cpp
** File description:
** ClassSFML
*/

#include "ClassSFML.hpp"

ClassSFML::ClassSFML():
    _key(0),
    _isNewPathConfig(false),
    _isNewMap(false),
    _isNewKey(false)
{
    _wind = std::make_unique<sf::RenderWindow>();
    _wind->create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Arcade");
    _wind->setPosition(SCREEN_POS);
    _wind->setFramerateLimit(FRAMERATE);
}

ClassSFML::~ClassSFML()
{
    _wind->close();
}

void ClassSFML::setMapTexture()
{
    auto parsingResult = _parsing.getResult();
    size_t i = 0;
    float x = 0;
    float y = 0;

    _textures.clear();
    for (auto it = parsingResult.begin(); it != parsingResult.end(); ++it) {
        sf::Vector2i size = {it->sizeX, it->sizeY};
        _textures.push_back(std::make_pair(size, std::shared_ptr<sf::Texture> (new sf::Texture)));
        _textures[i].second->loadFromFile(it->path, sf::IntRect(0, 0, size.x, size.y));
        _textures[i].second->setSmooth(true);
        ++i;
    }
    for (auto it_y = _map->begin(); it_y != _map->end(); ++it_y) {
        x = 0;
        for (auto it_x = it_y->begin(); it_x != it_y->end(); ++it_x) {
            switch (it_x->first) {
                case WALL:
                    it_x->second.setTexture(*_textures.begin()->second);
                    it_x->second.setPosition({x, y});
                    break;
                case POINT:
                    it_x->second.setTexture(*_textures.at(1).second);
                    it_x->second.setPosition({x, y});
                    break;
                case PLAYER:
                    it_x->second.setTexture(*_textures.at(2).second);
                    it_x->second.setPosition({x, y});
                    break;
                case ENEMY:
                    it_x->second.setTexture(*_textures.at(3).second);
                    it_x->second.setPosition({x, y});
                    break;
                case BONUS:
                    it_x->second.setTexture(*_textures.at(4).second);
                    it_x->second.setPosition({x, y});
                    break;
                default:
                    break;
            }
            x += _textures.begin()->first.x;
        }
        y += _textures.begin()->first.y;
    }
}

void ClassSFML::displayGame()
{
    for (auto it = _map->begin(); it != _map->end(); ++it)
        for (auto it_sprite = it->begin(); it_sprite != it->end(); ++it_sprite)
            if (it_sprite->first != NOTHING)
                _wind->draw(it_sprite->second);
}

bool ClassSFML::getEvent()
{
    while (_wind->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _wind->close();
            return (true);
        }
        if (_event.type == sf::Event::KeyPressed) {
            translateKey();
            setIsNewKey(true);
            if (getLastKey() == 38 || getLastKey() == 39)
                return (true);
        }
    }
    return (false);
}

bool ClassSFML::runGraph()
{
    if (getIsNewPathConfig() == true) {
        _parsing.clearData();
        setIsNewPathConfig(false);
        _parsing.setFilename(getPathConfig());
        _parsing.readFile();
        setMapTexture();
    }
    if (!_wind->isOpen())
        return (false);
    _wind->clear();
    if (getEvent())
        return (false);
    displayGame();
    _wind->display();
    return (true);
}

void ClassSFML::setMap(std::shared_ptr<std::vector<std::string>> map)
{
    _map = std::make_unique<std::vector<std::vector<std::pair<char, sf::Sprite>>>>();
    for (auto it = map->begin(); it != map->end(); ++it) {
        std::vector<std::pair<char, sf::Sprite>> tmp;
        for (auto it_str = it->begin(); it_str != it->end(); ++it_str) {
            sf::Sprite sprite;
            tmp.push_back(std::make_pair(*it_str, sprite));
        }
        _map->push_back(tmp);
    }
}

void ClassSFML::translateKey()
{
    for (size_t i = 0; KeySFML[i].code_lib != 1000; i++)
        if (_event.key.code == KeySFML[i].code_lib) {
            setLastKey(KeySFML[i].code_core);
            setIsNewKey(true);
            break;
        }
}

void ClassSFML::setIsNewMap(bool newMap)
{
    _isNewMap = newMap;
}

bool ClassSFML::getIsNewMap(void) const
{
    return (_isNewMap);
}

void ClassSFML::setIsNewKey(bool newKey)
{
    _isNewKey = newKey;
}

bool ClassSFML::getIsNewKey(void) const
{
    return (_isNewKey);
}

void ClassSFML::setLastKey(int key)
{
    _key = key;
}

int ClassSFML::getLastKey(void) const
{
    return (_key);
}

void ClassSFML::setScore(size_t score)
{
    _score = score;
}

size_t ClassSFML::getScore() const
{
    return (_score);
}

void ClassSFML::setPathConfig(std::string path) noexcept
{
    _pathConfig = path;
}

std::string ClassSFML::getPathConfig() const noexcept
{
    return (_pathConfig);
}

void ClassSFML::setIsNewPathConfig(bool isNewPath) noexcept
{
    _isNewPathConfig = isNewPath;   
}

bool ClassSFML::getIsNewPathConfig() const noexcept
{
    return (_isNewPathConfig);
}

extern "C"
{
    IGraphic *entryPoint(void)
    {
        ClassSFML *instance = new ClassSFML();
        return (instance);
    }
}

