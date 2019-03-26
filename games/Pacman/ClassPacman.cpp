/*
** EPITECH PROJECT, 2019
** ClassPacman.cpp
** File description:
** ClassPacman
*/

#include "ClassPacman.hpp"

ClassPacman::ClassPacman():
    _isNewMap(false),
    _score(0),
    _key(0),
    _bonus(false)
{
}

ClassPacman::~ClassPacman()
{
}

bool ClassPacman::runGame()
{
    if (_bonus && difftime(time(0), _start) >= 12)
            setBonus(false);
    switch (getLastKey()) {
        case UP:
            moveUp();
            break;
        case LEFT:
            moveLeft();
            break;
        case DOWN:
            moveDown();
            break;
        case RIGHT:
            moveRight();
            break;
        default:
            break;
    }
    return (true);
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

void ClassPacman::setLastMove(Move lastMove)
{
    _lastMove = lastMove;
}

ClassPacman::Move ClassPacman::getLastMove() const
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
            if (*it->begin() != WALL && it_c == std::next(it->begin())) {
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
                *std::prev(it->end()) = PLAYER;
            } else {
                if (*std::prev(it_c) == POINT)
                    setScore(getScore() + 10);
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
                *std::prev(it_c) = PLAYER;
            }
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
            if (*it->end() != WALL && it_c == std::prev(it->end())) {
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
                std::replace(it->begin(), it->end(), it->at(0), (char)PLAYER);
            } else {
                if (*std::next(it_c) == POINT)
                    setScore(getScore() + 10);
                *std::next(it_c) = PLAYER;
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
            }
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
            if (next != WALL) {
                if (next == POINT)
                    setScore(getScore() + 10);
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
                std::prev(it)->at(pos) = PLAYER;
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