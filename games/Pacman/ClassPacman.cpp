/*
** EPITECH PROJECT, 2019
** ClassPacman.cpp
** File description:
** ClassPacman
*/

#include "ClassPacman.hpp"

ClassPacman::ClassPacman():
    _isNewMap(true),
    _score(0),
    _key(0),
    _bonus(false)
{
    _clock = clock();
}

ClassPacman::~ClassPacman()
{
}

bool ClassPacman::runGame()
{
    static bool first_time = true;
    
    if (first_time) {
        first_time = false;
        readMap();
        this->setMap(_map);
    }
    if (_bonus && difftime(time(0), _start) >= 12)
            setBonus(false);
    // if (static_cast<double>((clock() - _clock)) / CLOCKS_PER_SEC > 0.2) {
        switch (getLastKey()) {
            case UP:
                moveUp();
                setMove(UP);
                break;
            case LEFT:
                moveLeft();
                setMove(LEFT);
                break;
            case DOWN:
                moveDown();
                setMove(DOWN);
                break;
            case RIGHT:
                moveRight();
                setMove(RIGHT);
                break;
            default:
                break;
        }
    // }
    return (true);
}

void ClassPacman::readMap()
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

void ClassPacman::setMap(std::shared_ptr<std::vector<std::string>> map)
{
    _map = map;
}

std::shared_ptr<std::vector<std::string>> ClassPacman::getMap(void) const
{
    return (_map);
}

void ClassPacman::setIsNewMap(bool map)
{
    _isNewMap = map;
}

bool ClassPacman::getIsNewMap(void) const
{
    return (_isNewMap);
}

void ClassPacman::setIsNewKey(bool isNewKey)
{
    _isNewKey = isNewKey;
}

bool ClassPacman::getIsNewKey(void) const
{
    return (_isNewKey);
}

void ClassPacman::setLastKey(int key)
{
    _key = key;
}

int ClassPacman::getLastKey(void) const
{
    return (_key);
}

void ClassPacman::setScore(size_t score)
{
    _score = score;
}

size_t ClassPacman::getScore() const
{
    return (_score);
}

const std::string ClassPacman::getPathConfig() const noexcept
{
    return (_pathConfig);
}

const std::string ClassPacman::getPathMap() const noexcept
{
    return (_pathMap);
}

void ClassPacman::setMove(Move lastMove)
{
    _lastMove = lastMove;
}

Move ClassPacman::getMove() const
{
    return (_lastMove);
}

void ClassPacman::setBonus(bool bonus)
{
    if (bonus)
        _start = time(0);
    _bonus = bonus;
}

bool ClassPacman::getBonus(void) const
{
    return (_bonus);
}

void ClassPacman::moveDown(void)
{
    for (auto it = _map->begin(); it != _map->end(); ++it) {
        auto it_c = find(it->begin(), it->end(), PLAYER);
        if (it_c != it->end()) {
            ptrdiff_t pos = std::distance(it->begin(), find(it->begin(), it->end(), *it_c));
            auto next = std::next(it)->at(pos);
            checkNextCase(next);
            if (next != WALL) {
                if (next == POINT)
                    setScore(getScore() + 10);
                std::next(it)->at(pos) = PLAYER;
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
                setIsNewMap(true);
            } else
                setIsNewKey(false);
            break;
        }
    }
}

void ClassPacman::moveLeft(void)
{
    for (auto it = _map->begin(); it != _map->end(); ++it) {
        auto it_c = find(it->begin(), it->end(), PLAYER);
        if (it_c != it->end() && *std::prev(it_c) != WALL) {
            ptrdiff_t pos = std::distance(it->begin(), find(it->begin(), it->end(), *it_c));
            checkNextCase(it->at(pos));
            if (*it->begin() != WALL && it_c == std::next(it->begin())) {
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
                *std::prev(it->end()) = PLAYER;
            } else {
                if (*std::prev(it_c) == POINT)
                    setScore(getScore() + 10);
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
                *std::prev(it_c) = PLAYER;
            }
            setIsNewMap(true);
            break;
        } else if (*std::next(it_c) == WALL)
            setIsNewKey(false);
    }
}

void ClassPacman::moveRight(void)
{
    for (auto it = _map->begin(); it != _map->end(); ++it) {
        auto it_c = find(it->begin(), it->end(), PLAYER);
        if (it_c != it->end() && *std::next(it_c) != WALL) {
            ptrdiff_t pos = std::distance(it->begin(), find(it->begin(), it->end(), *it_c));
            checkNextCase(it->at(pos));
            if (*it->end() != WALL && it_c == std::prev(it->end())) {
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
                std::replace(it->begin(), it->end(), it->at(0), (char)PLAYER);
            } else {
                if (*std::next(it_c) == POINT)
                    setScore(getScore() + 10);
                *std::next(it_c) = PLAYER;
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
            }
            setIsNewMap(true);
            break;
        } else if (*std::next(it_c) == WALL)
            setIsNewKey(false);
    }
}

void ClassPacman::moveUp(void)
{
    for (auto it = _map->begin(); it != _map->end(); ++it) {
        auto it_c = find(it->begin(), it->end(), PLAYER);
        if (it_c != it->end()) {
            ptrdiff_t pos = std::distance(it->begin(), find(it->begin(), it->end(), *it_c));
            auto next = std::prev(it)->at(pos);
            checkNextCase(next);
            if (next != WALL) {
                if (next == POINT)
                    setScore(getScore() + 10);
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
                std::prev(it)->at(pos) = PLAYER;
                setIsNewMap(true);
            } else
                setIsNewKey(false);
            break;
        }
    }
}

void ClassPacman::checkNextCase(char nextPos)
{
    switch (nextPos) {
        case ENEMY:
            std::cout << "Enemy" << std::endl;
            break;
        case BONUS:
            std::cout << "Bonus" << std::endl;
            setBonus(true);
            break;
        default:
            break;
    }
}

extern "C"
{
    IGame *entryPoint(void)
    {
        ClassPacman *instance = new ClassPacman();
        return (instance);
    }
}