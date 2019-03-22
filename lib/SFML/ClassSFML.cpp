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
    _object_texture.loadFromFile("./textures/big_point.bmp", sf::IntRect(0, 0, 30, 30));
    _super_object_texture.loadFromFile("./textures/point.bmp", sf::IntRect(0, 0, 30, 30));
    _character.loadFromFile("./textures/tile000.bmp");
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

void ClassSFML::displayGame()
{
    static int x = 0;
    std::vector<sf::Texture> v_tmp;
    sf::Texture tmp0;
    sf::Texture tmp1;
    sf::Texture tmp2;
    tmp0.loadFromFile("./textures/tile000.bmp");
    tmp1.loadFromFile("./textures/tile001.bmp");
    tmp2.loadFromFile("./textures/tile002.bmp");
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

bool ClassSFML::get_event()
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

bool ClassSFML::runGraph() 
{
    if (!(_wind->isOpen()))
        return (false);
    _wind->clear();
    if (get_event())
        return (false);
    displayGame();
    _wind->display();
    return (true);
}

void ClassSFML::setMap()
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
    setMapTexture();
}

void ClassSFML::translateKey()
{
    for (size_t i = 0; KeySFML[i].code_lib != 1000; i++)
        if (_event.key.code == KeySFML[i].code_lib) {
            setLastKey(KeySFML[i].code_core);
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

extern "C"
{
    IGraphic *entryPoint(void)
    {
        ClassSFML *instance = new ClassSFML();
        return (instance);
    }
}
