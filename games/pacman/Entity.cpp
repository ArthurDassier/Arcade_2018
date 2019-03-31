/*
** EPITECH PROJECT, 2019
** Entity.cpp
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(PacmanObjs entity = NOTHING):
    _entity(entity), _score(0), _bonus(false),
    _isNewMap(true), _isNewKey(false)
{
    std::vector<std::string>::iterator it;
    _pos = std::make_pair(it, 0);
}

Entity::~Entity()
{
}

void Entity::move(Move direction, std::shared_ptr<std::vector<std::string>> map)
{
    if (_bonus && difftime(time(0), _start) >= 12) {
        std::cout << "BONUS END" << std::endl;
        setBonus(false);
    }
    setIsNewMap(false);
    switch (direction) {
        case UP:
            moveUp(map);
            break;
        case LEFT:
            moveLeft(map);
            break;
        case DOWN:
            moveDown(map);
            break;
        case RIGHT:
            moveRight(map);
            break;
        default:
            break;
    }
}

void Entity::moveDown(std::shared_ptr<std::vector<std::string>> map)
{
    bool found = false;

    for (auto it = (*map).begin(); it != (*map).end(); ++it) {
        auto it_c = find(it->begin(), it->end(), _entity);
        if (it_c != it->end()) {
            found = true;
            ptrdiff_t pos = std::distance(it->begin(), find(it->begin(), it->end(), *it_c));
            auto next = std::next(it)->at(pos);
            if (!checkNextCase(next)) {
                *it_c = NOTHING;
                std::next(it)->at(pos) = ENEMY;
                break;
            }
            if (next != WALL) {
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
                std::next(it)->at(pos) = _entity;
                setPosition(std::make_pair(std::next(it), pos));
                setIsNewMap(true);
            } else
                setIsNewMap(false);
            break;
        }
    }
    setIsNewKey(found);
}

void Entity::moveLeft(std::shared_ptr<std::vector<std::string>> map)
{
    bool found = false;

    for (auto it = (*map).begin(); it != (*map).end(); ++it) {
        auto it_c = find(it->begin(), it->end(), _entity);
        if (it_c != it->end() && *std::prev(it_c) != WALL) {
            found = true;
            ptrdiff_t pos = std::distance(it->begin(), find(it->begin(), it->end(), *it_c));
            if (!checkNextCase(std::prev(it_c) != it->begin() ? it->at(pos - 1) : *std::prev(it->end()))) {
                *std::prev(it_c) = ENEMY;
                *it_c = NOTHING;
                break;
            }
            if (*it->begin() != WALL && it_c == std::next(it->begin())) {
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
                *std::prev(it->end()) = _entity;
            } else {
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
                *std::prev(it_c) = _entity;
            }
            setPosition(std::make_pair(it, pos - 1));
            setIsNewMap(true);
            break;
        } else
            setIsNewMap(false);
    }
    setIsNewKey(found);
}

void Entity::moveRight(std::shared_ptr<std::vector<std::string>> map)
{
    bool found = false;

    for (auto it = (*map).begin(); it != (*map).end(); ++it) {
        auto it_c = find(it->begin(), it->end(), _entity);
        if (it_c != it->end() && *std::next(it_c) != WALL) {
            found = true;
            ptrdiff_t pos = std::distance(it->begin(), find(it->begin(), it->end(), *it_c));
            if (!checkNextCase(std::next(it_c) != it->end() ? it->at(pos + 1) : *it->begin())) {
                *std::next(it_c) = ENEMY;
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
                break;
            }
            if (*it->end() != WALL && it_c == std::prev(it->end())) {
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
                std::replace(it->begin(), it->end(), it->at(0), (char)_entity);
            } else {
                *std::next(it_c) = _entity;
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
            }
            setPosition(std::make_pair(it, pos + 1));
            setIsNewMap(true);
            break;
        } else
            setIsNewMap(false);
    }
    setIsNewKey(found);
}

void Entity::moveUp(std::shared_ptr<std::vector<std::string>> map)
{
    bool found = false;

    for (auto it = (*map).begin(); it != (*map).end(); ++it) {
        auto it_c = find(it->begin(), it->end(), _entity);
        if (it_c != it->end()) {
            found = true;
            ptrdiff_t pos = std::distance(it->begin(), find(it->begin(), it->end(), *it_c));
            auto next = std::prev(it)->at(pos);
            if (!checkNextCase(next)) {
                std::prev(it)->at(pos) = ENEMY;
                *it_c = NOTHING;
                break;
            }
            if (next != WALL) {
                std::replace(it->begin(), it->end(), it->at(pos), (char)NOTHING);
                std::prev(it)->at(pos) = _entity;
                setPosition(std::make_pair(std::prev(it), pos));
                setIsNewMap(true);
            } else {
                setIsNewMap(false);
            }
            break;
        }
    }
    setIsNewKey(found);
}

bool Entity::checkNextCase(char nextPos)
{
    if (nextPos == POINT) {
        std::cout << "+10" << std::endl;
        setScore(getScore() + 10);
    } else if (nextPos == BONUS) {
        std::cout << "BONUS" << std::endl;
        setBonus(true);
    } else if (nextPos != _entity && nextPos != NOTHING && nextPos != WALL) {
        if (!_bonus && _entity == PLAYER) {
            std::cout << "GAME OVER" << std::endl;
            return (false);
        } else if (_bonus && _entity == PLAYER) {
            std::cout << "+200" << std::endl;
            setScore(getScore() + 200);
        }
    }
    return (true);
}

const PacmanObjs Entity::getEntity() const noexcept
{
    return (_entity);
}

void Entity::setSpeed(float speed)
{
    _speed = speed;
}

float Entity::getSpeed() const
{
    return (_speed);
}

void Entity::setPosition(std::pair<std::vector<std::string>::iterator, ptrdiff_t> pos)
{
    _pos = pos;
}

std::pair<std::vector<std::string>::iterator, ptrdiff_t> Entity::getPosition() const
{
    return (_pos);
}

void Entity::setIsNewMap(bool isNewMap)
{
    _isNewMap = isNewMap;
}

bool Entity::getIsNewMap() const
{
    return (_isNewMap);
}

void Entity::setIsNewKey(bool isNewKey)
{
    _isNewKey = isNewKey;
}

bool Entity::getIsNewKey() const
{
    return (_isNewKey);
}

void Entity::setLastMove(Move move)
{
    _move = move;
}

Move Entity::getLastMove() const
{
    return (_move);
}

void Entity::setScore(size_t score)
{
    _score = score;
}

size_t Entity::getScore() const
{
    return (_score);
}

void Entity::setBonus(bool bonus)
{
    if (bonus)
        _start = time(0);
    _bonus = bonus;
}