/*
** EPITECH PROJECT, 2019
** ClassSFML.cpp
** File description:
** ClassSFML
*/

#include "ClassSFML.hpp"

ClassSFML::ClassSFML():
    _key(0)
{
    _wind = std::make_unique<sf::RenderWindow>();
    _wind->create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Arcade");
    _wind->setPosition(SCREEN_POS);
    _wind->setFramerateLimit(FRAMERATE);
    _wall_texture.loadFromFile("./textures/wall.bmp", sf::IntRect(10, 10, 30, 30));
    _point_texture.loadFromFile("./textures/big_point.bmp", sf::IntRect(0, 0, 30, 30));
    _bonus_texture.loadFromFile("./textures/point.bmp", sf::IntRect(0, 0, 30, 30));
    _player_texture.loadFromFile("./textures/tile000.bmp");
    // if (!_player_texture.loadFromFile("pacman_spritesheet.png")) {
    //     std::cout << "Failed to load player spritesheet!" << std::endl;
    //     exit(EXIT_FAILURE);
    // }
    // _MoveDownAnimation.setSpriteSheet(_player_texture);
    // _MoveDownAnimation.addFrame(sf::IntRect(15, 48, 15, 15));
    // _MoveDownAnimation.addFrame(sf::IntRect(0, 48, 15, 15));

    // _MoveLeftAnimation.setSpriteSheet(_player_texture);
    // _MoveLeftAnimation.addFrame(sf::IntRect(15, 15, 15, 15));
    // _MoveLeftAnimation.addFrame(sf::IntRect(0, 15, 15, 15));

    // _MoveRightAnimation.setSpriteSheet(_player_texture);
    // _MoveRightAnimation.addFrame(sf::IntRect(15, 0, 15, 15));
    // _MoveRightAnimation.addFrame(sf::IntRect(0, 0, 15, 15));

    // _MoveUpAnimation.setSpriteSheet(_player_texture);
    // _MoveUpAnimation.addFrame(sf::IntRect(15, 32, 15, 15));
    // _MoveUpAnimation.addFrame(sf::IntRect(31, 0, 15, 15));

    // // _MoveRightAnimation.addFrame(sf::IntRect(31, 0, 15, 15));

    // _currentAnimation = &_MoveRightAnimation;
    // AnimatedSprite animatedSprite(sf::seconds(0.1), true, false);
    // _animatedSprite = animatedSprite;
}

ClassSFML::~ClassSFML()
{
    _wind->close();
}

void ClassSFML::setMapTexture()
{
    float x = 0;
    float y = 0;

    for (auto it = _map->begin(); it != _map->end(); ++it) {
        x = 0;
        for (auto it_str = it->begin(); it_str != it->end(); ++it_str) {
            switch (it_str->first) {
                case WALL:
                    it_str->second.setTexture(_wall_texture);
                    it_str->second.setColor(sf::Color(103, 183, 250));
                    it_str->second.setPosition({x, y});
                    // it_str->second.first.setSpriteSheet(_wall_texture);
                    // it_str->second.second.setPosition({x, y});
                    break;
                case POINT:
                    it_str->second.setTexture(_point_texture);
                    it_str->second.setColor(sf::Color(255, 186, 156));
                    it_str->second.setPosition({x + 12, y + 12});
                    // it_str->second.first.setSpriteSheet(_point_texture);
                    // it_str->second.second.setPosition({x + 12, y + 12});
                    break;
                case PLAYER:
                    it_str->second.setTexture(_player_texture);
                    it_str->second.scale(sf::Vector2f(1.5f, 1.5f));
                    it_str->second.setPosition({x + 5, y + 4});
                    // _animatedSprite.setPosition({x + 5, y + 4});
                    // it_str->second.first.setSpriteSheet(_player_texture);
                    // it_str->second.second.setPosition({x + 5, y + 4});
                    break;
                case ENEMY:
                    break;
                case BONUS:
                    it_str->second.setTexture(_bonus_texture);
                    it_str->second.setColor(sf::Color(255, 186, 156));
                    it_str->second.setPosition({x + 9, y + 9});
                    // it_str->second.first.setSpriteSheet(_bonus_texture);
                    // it_str->second.second.setPosition({x + 9, y + 9});
                    break;
                default:
                    break;
            }
            x += _wall_texture.getSize().x;
        }
        y += _wall_texture.getSize().y;
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
            if (getLastKey() == 38 || getLastKey() == 39 || getLastKey() == 40)
                return (true);
        }
        // if (_event.type == sf::Event::KeyReleased)
        //     setIsNewKey(false);
    }
    return (false);
}

bool ClassSFML::runGraph()
{
    // sf::Texture texture;
    // if (!texture.loadFromFile("pacman_spritesheet.png")) {
    //     std::cout << "Failed to load player spritesheet!" << std::endl;
    //     exit(EXIT_FAILURE);
    // }
    // Animation MoveRightAnimation;
    // MoveRightAnimation.setSpriteSheet(texture);
    // MoveRightAnimation.addFrame(sf::IntRect(15, 0, 15, 15));
    // MoveRightAnimation.addFrame(sf::IntRect(0, 0, 15, 15));
    // MoveRightAnimation.addFrame(sf::IntRect(31, 0, 15, 15));

    // Animation *currentAnimation = &MoveRightAnimation;

    // AnimatedSprite animatedSprite(sf::seconds(0.1), true, false);
    // float x = 0;
    // float y = 0;

    // for (auto it = _map->begin(); it != _map->end(); ++it) {
    //     x = 0;
    //     for (auto it_str = it->begin(); it_str != it->end(); ++it_str) {
    //         switch (it_str->first) {
    //             case PLAYER:
    //                     animatedSprite.setPosition({x + 5, y + 4});
    //                 break;
    //             default:
    //                 break;
    //         }
    //         x += _wall_texture.getSize().x;
    //     }
    //     y += _wall_texture.getSize().y;
    // }
    // sf::Clock frameClock;
    // while (_wind->isOpen()) {
    if (!_wind->isOpen())
        return (false);
    _wind->clear();
    // sf::Time frameTime = _frameClock.restart();
    // static sf::Time frameTime = _frameClock.restart();
    if (getEvent())
        return (false);
    // for (auto it = _map->begin(); it != _map->end(); ++it)
    //     for (auto it_sprite = it->begin(); it_sprite != it->end(); ++it_sprite)
    //         if (it_sprite->first == PLAYER) {
    //             it_sprite->second.second.play(*_currentAnimation);
    //             it_sprite->second.second.update(frameTime);
    //         }
    // // _animatedSprite.play(*_currentAnimation);
    // _animatedSprite.update(frameTime);
    // _wind->clear();
    // _wind->draw(_animatedSprite);
    displayGame();
    _wind->display();
    return (true);
    // }
}

void ClassSFML::setMap(std::shared_ptr<std::vector<std::string>> map)
{
    _map = std::make_unique<std::vector<std::vector<std::pair<char, sf::Sprite>>>>();
    // _map = std::make_unique<std::vector<std::vector<std::pair<char, std::pair<Animation, AnimatedSprite>>>>>();
    for (auto it = map->begin(); it != map->end(); ++it) {
        std::vector<std::pair<char, sf::Sprite>> tmp;
        // std::vector<std::pair<char, std::pair<Animation, AnimatedSprite>>> tmp;
        for (auto it_str = it->begin(); it_str != it->end(); ++it_str) {
            // Animation animation;
            // AnimatedSprite animatedSprite(sf::seconds(0.1), true, false);
            sf::Sprite sprite;
            tmp.push_back(std::make_pair(*it_str, sprite));
            // tmp.push_back(std::make_pair(*it_str, std::make_pair(animation, animatedSprite)));
        }
        _map->push_back(tmp);
    }
    setMapTexture();
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

extern "C"
{
    IGraphic *entryPoint(void)
    {
        ClassSFML *instance = new ClassSFML();
        return (instance);
    }
}

