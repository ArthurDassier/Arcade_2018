/*
** EPITECH PROJECT, 2019
** Pacman.cpp
** File description:
** Pacman
*/

#include "Pacman.hpp"

/*!
 * \fn Pacman::Pacman()
 * \brief Create the Pacman game
 *
 * \param void
 */

Pacman::Pacman():
    _pathConfig("./games/pacman/config/sprites.config"),
    _pathMap("./games/pacman/config/map.config"),
    _isNewMap(true),
    _score(0),
    _key(0),
    _bonus(false),
    _lock_create_map(true)
{
    _map = std::make_shared<std::vector<std::string>>();
    for (size_t i = 0; i < 4; i++)
        _clock[i] = clock();
    _pacman = std::make_shared<Entity>(PLAYER);
    _pacman->setSpeed(0.1);
    std::shared_ptr<Entity> ghost = std::make_shared<Entity>(ENEMY);
    ghost->setSpeed(5);
    _ghosts.push_back(ghost);
}

/*!
 * \fn Pacman::~Pacman()
 * \brief Pacman Class destructor
 *
 * \param void
 */

Pacman::~Pacman()
{
    _lock_create_map = true;
}

/*!
 * \fn Pacman::runGame()
 * \brief Set the clock of the game and handle the logic
 *
 * \param void
 */

bool Pacman::runGame()
{
    // static bool first_time = true;
    
    setIsNewMap(false);
    if (_lock_create_map) {
        _lock_create_map = false;
        readMap();
        this->setMap(_map);
        setIsNewMap(true);
    }
    if (getLastKey() == 41) {
        _lock_create_map = true;
        _ghosts.at(0)->setSpeed(5);
        _score = 0;
        _bonus = false;
        return (true);
    }
    if (static_cast<double>((clock() - _clock[0])) / CLOCKS_PER_SEC > _pacman->getSpeed()) {
        setMove((Move)getLastKey());
        _pacman->move(getMove(), _map);
        _clock[0] = clock();
        setIsNewMap(true);
    }
    if (static_cast<double>((clock() - _clock[1])) / CLOCKS_PER_SEC > _ghosts.at(0)->getSpeed()) {
        _ghosts.at(0)->move(UP, _map);
        _ghosts.at(0)->setSpeed(0.1);
        _ghosts.at(0)->move(UP, _map);
        // std::cout << "ghost pos: " << _ghosts.at(0)->getPosition().second << std::endl;
        _clock[1] = clock();
        setIsNewMap(true);
    }
    setScore(_pacman->getScore());
    // setIsNewMap(_pacman->getIsNewMap() || _ghosts.at(0)->getIsNewMap() ? true : false);
    // if (_pacman->getIsNewMap() || _ghosts.at(0)->getIsNewMap())
    // setIsNewMap(true);
    // else
    //     setIsNewMap(false);
    setIsNewKey(_pacman->getIsNewKey());
    return (true);
}

/*!
 * \fn Pacman::readMap()
 * \brief Read the map
 *
 * \param void
 */

void Pacman::readMap()
{
    // size_t i = 0;
    std::string line;
    std::ifstream map_file(_pathMap);

    _map = std::make_shared<std::vector<std::string>>();
    // std::map<size_t, std::map<size_t, char>> _tmp;
    // _tmp = std::make_shared<std::map<size_t, std::map<size_t, char>>>();
    if (map_file) {
        while (getline(map_file, line)) {
            _map->push_back(line);
            // std::map<size_t, char> tmp;
            // for (size_t j = 0; j < line.length(); j++) {
            // // for (auto it = line.begin(); it != line.end(); ++it) {
            //     tmp[j] = line.at(j);
            //     _tmp[i] = tmp;
            // }
            // i++;
        }
        map_file.close();
    }
    // for (auto it = _tmp.begin(); it != _tmp.end(); ++it) {
    //     std::cout << it->first << std::endl;
    //     for (auto it_c = it->second.begin(); it_c != it->second.end(); ++it_c) {
    //         std::cout << "[" << it_c->first << "]=" << it_c->second << std::endl;
    //     }
    // }
}

void Pacman::setMap(std::shared_ptr<std::vector<std::string>> map)
{
    _map = map;
}

std::shared_ptr<std::vector<std::string>> Pacman::getMap(void) const
{
    return (_map);
}

void Pacman::setIsNewMap(bool map)
{
    _isNewMap = map;
}

bool Pacman::getIsNewMap(void) const
{
    return (_isNewMap);
}

void Pacman::setIsNewKey(bool isNewKey)
{
    _isNewKey = isNewKey;
}

bool Pacman::getIsNewKey(void) const
{
    return (_isNewKey);
}

void Pacman::setLastKey(int key)
{
    _key = key;
}

int Pacman::getLastKey(void) const
{
    return (_key);
}

void Pacman::setScore(size_t score)
{
    _score = score;
}

size_t Pacman::getScore() const
{
    return (_score);
}

const std::string Pacman::getPathConfig() const noexcept
{
    return (_pathConfig);
}

const std::string Pacman::getPathMap() const noexcept
{
    return (_pathMap);
}

void Pacman::setMove(Move lastMove)
{
    _lastMove = lastMove;
    // setIsNewMap(true);
}

Move Pacman::getMove() const
{
    return (_lastMove);
}

extern "C"
{
    IGame *entryPoint(void)
    {
        Pacman *instance = new Pacman();
        return (instance);
    }
}