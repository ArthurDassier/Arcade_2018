/*
** EPITECH PROJECT, 2019
** Entity.hpp
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

enum Move
{
    RIGHT = 3,
    LEFT = 16,
    DOWN = 18,
    UP = 25
};

enum PacmanObjs
{
    NOTHING = '0',
    WALL = '1',
    POINT = '2',
    PLAYER = '3',
    ENEMY = '4',
    BONUS = '5',
};

typedef struct s_pos {
    size_t  x;
    size_t  y;
}   t_pos;

class Entity
{
	public:
        Entity(PacmanObjs);
		~Entity();

        void move(Move, std::shared_ptr<std::vector<std::string>>);
        // void move(Move, std::map<size_t, std::map<size_t, char>>);
        std::map<size_t, std::map<size_t, char>> getMap() const;

        const PacmanObjs getEntity() const noexcept;

        void setSpeed(float);
        float getSpeed() const;

        void setPosition(std::pair<std::vector<std::string>::iterator, ptrdiff_t>);
        std::pair<std::vector<std::string>::iterator, ptrdiff_t> getPosition() const;

        void setIsNewMap(bool);
        bool getIsNewMap() const;

        void setIsNewKey(bool);
        bool getIsNewKey() const;

        void setLastKey(int);
        int getLastKey() const;

        void setLastMove(Move);
        Move getLastMove() const;

        void setScore(size_t);
        size_t getScore() const;

        void setBonus(bool);
        bool getBonus() const;

	private:
        const PacmanObjs _entity;
        std::map<size_t, std::map<size_t, char>> _map;
        std::pair<std::vector<std::string>::iterator, ptrdiff_t> _pos;
        time_t _start;
        size_t _score;
        float _speed;
        bool _bonus;
        Move _move;

        bool _isNewMap;
        bool _isNewKey;

        void moveDown(std::shared_ptr<std::vector<std::string>>);
        // void moveDown(std::map<size_t, std::map<size_t, char>>);
        void moveLeft(std::shared_ptr<std::vector<std::string>>);
        // void moveLeft(std::map<size_t, std::map<size_t, char>>);
        void moveRight(std::shared_ptr<std::vector<std::string>>);
        // void moveRight(std::map<size_t, std::map<size_t, char>>);
        void moveUp(std::shared_ptr<std::vector<std::string>>);
        // void moveUp(std::map<size_t, std::map<size_t, char>>);
        bool checkNextCase(char);
};

#endif /* !ENTITY_HPP_ */