/*
** EPITECH PROJECT, 2019
** ClassEntity.hpp
** File description:
** ClassEntity
*/

#pragma once

enum Move
{
    RIGHT = 3,
    LEFT = 16,
    DOWN = 18,
    UP = 25
};

enum PacmanObjs
{
    NOTHING = 0,
    WALL = 1,
    POINT = 2,
    PLAYER = 3,
    ENEMY = 4,
    BONUS = 5,
};

class ClassEntity
{
    public:
        ClassEntity();
        ~ClassEntity();

    protected:
    private:
};
