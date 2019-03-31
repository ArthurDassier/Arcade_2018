/*
** EPITECH PROJECT, 2019
** Pacman.cpp
** File description:
** Pacman
*/

#include "Pacman.hpp"

/*!
 * \fn Pacman::Pacman()
 * \brief Create Pacman, set the getters and intialize entities
 *
 * \param void
 */
Pacman::Pacman():
    _pathConfig("./games/pacman/config/sprites.config"),
    _pathMap("./games/pacman/config/map.config"),
    _isNewMap(true),
    _key(0),
    _score(0),
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
 * \brief Pacman Class destructor, free vector of entity
 *
 * \param void
 */
Pacman::~Pacman()
{
    _lock_create_map = true;
}

/*!
 * \fn Pacman::runGame()
 * \brief Handle the events of the Pacman
 *
 * \param void
 */
bool Pacman::runGame()
{
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
        _clock[1] = clock();
        setIsNewMap(true);
    }
    setScore(_pacman->getScore());
    setIsNewKey(_pacman->getIsNewKey());
    return (true);
}

/*!
 * \fn Pacman::readMap()
 * \brief Read map.config and set game map
 *
 * \param void
 */
void Pacman::readMap()
{
    std::string line;
    std::ifstream map_file(_pathMap);

    _map = std::make_shared<std::vector<std::string>>();
    if (map_file) {
        while (getline(map_file, line))
            _map->push_back(line);
        map_file.close();
    }
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