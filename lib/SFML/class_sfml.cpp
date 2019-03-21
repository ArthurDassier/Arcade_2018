/*
** EPITECH PROJECT, 2019
** class_sfml.cpp
** File description:
** class_sfml
*/

#include "class_sfml.hpp"

class_sfml::class_sfml():
    _key(0)
{
    _wind = std::make_shared<sf::RenderWindow>();
    _wind->create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Arcade");
    _wind->setPosition(SCREEN_POS);
    _wind->setFramerateLimit(FRAMERATE);
    _wall_texture.loadFromFile("./textures/wall.png", sf::IntRect(10, 10, 30, 30));
    _object_texture.loadFromFile("./textures/big_point.png", sf::IntRect(0, 0, 30, 30));
    _super_object_texture.loadFromFile("./textures/point.png", sf::IntRect(0, 0, 30, 30));
    _character.loadFromFile("./textures/tile000.png");
}

class_sfml::~class_sfml()
{
    _wind->close();
}

void class_sfml::set_map_texture()
{
    float x = 0;
    float y = 0;

    for (auto it = _map->begin(); it != _map->end(); ++it) {
        x = 0;
        for (auto it_str = it->begin(); it_str != it->end(); ++it_str) {
            switch (it_str->first) {
                case '1':
                    it_str->second.setTexture(_wall_texture);
                    it_str->second.setColor(sf::Color(103, 183, 250));
                    it_str->second.setPosition({x, y});
                    break;
                case '2':
                    it_str->second.setTexture(_object_texture);
                    it_str->second.setColor(sf::Color(255, 186, 156));
                    it_str->second.setPosition({x + 12, y + 12});
                    break;
                case '3':
                    it_str->second.setTexture(_super_object_texture);
                    it_str->second.setColor(sf::Color(255, 186, 156));
                    it_str->second.setPosition({x + 9, y + 9});
                    break;
                case '4':
                    it_str->second.setTexture(_character);
                    it_str->second.scale(sf::Vector2f(1.5f, 1.5f));
                    it_str->second.setPosition({x + 5, y + 4});
                    break;
                default:
                    break;
            }
            x += _wall_texture.getSize().x;
        }
        y += _wall_texture.getSize().y;
    }
}

void class_sfml::display_game()
{
    static int x = 0;
    std::vector<sf::Texture> v_tmp;
    sf::Texture tmp0;
    sf::Texture tmp1;
    sf::Texture tmp2;
    tmp0.loadFromFile("./textures/tile000.png");
    tmp1.loadFromFile("./textures/tile001.png");
    tmp2.loadFromFile("./textures/tile002.png");
    v_tmp.push_back(tmp0);
    v_tmp.push_back(tmp1);
    v_tmp.push_back(tmp2);
    for (auto it = _map->begin(); it != _map->end(); ++it)
        for (auto it_sprite = it->begin(); it_sprite != it->end(); ++it_sprite) {
            if (it_sprite->first == '4') {
                it_sprite->second.setTexture(v_tmp[x]);
            }
            _wind->draw(it_sprite->second);
        }
    x++;
    if (x == 3)
        x = 0;
}

bool class_sfml::get_event()
{
    while (_wind->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            return (true);
        if (_event.type == sf::Event::KeyPressed) {
            translateKey();
            std::cout << getLastKey() << std::endl;
            if (getLastKey() == 0)
                return (true);
            if (getLastKey() == 38)
                std::cout << "change lib" << std::endl;
        }
    }
    return (false);
}

bool class_sfml::runGraph() 
{
    if (!(_wind->isOpen()))
        return (false);
    _wind->clear();
    if (get_event())
        return (false);
    display_game();
    _wind->display();
    return (true);
}

void class_sfml::setMap()
{
    std::string line;
    std::ifstream map_file("map.txt");

    _map = std::make_unique<std::vector<std::vector<std::pair<char, sf::Sprite>>>>();
    if (map_file) {
        while (getline(map_file, line)) {
            std::vector<std::pair<char, sf::Sprite>> tmp;
            for (auto it = line.begin(); it != line.end(); ++it) {
                sf::Sprite sprite;
                tmp.push_back(std::make_pair(*it, sprite));
            }
            _map->push_back(tmp);
        }
        map_file.close();
    }
    set_map_texture();
}

void class_sfml::translateKey()
{
    for (size_t i = 0; KeySFML[i].code_lib != 1000; i++)
        if (_event.key.code == KeySFML[i].code_lib) {
            setLastKey(KeySFML[i].code_core);
            break;
        }
}

void class_sfml::setIsNewMap(bool newMap)
{
    _isNewMap = newMap;
}

bool class_sfml::getIsNewMap(void) const
{
    return (_isNewMap);
}

void class_sfml::setIsNewKey(bool newKey)
{
    _isNewKey = newKey;
}

bool class_sfml::getIsNewKey(void) const
{
    return (_isNewKey);
}

void class_sfml::setLastKey(int key)
{
    _key = key;
}

int class_sfml::getLastKey(void) const
{
    return (_key);
}

extern "C"
{
    IGraphic *entryPoint(void)
    {
        class_sfml *instance = new class_sfml();
        return (instance);
    }
}
