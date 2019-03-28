/*
** EPITECH PROJECT, 2019
** ClassEntity.hpp
** File description:
** ClassEntity
*/

#ifndef CLASSENTITY_HPP_
    #define CLASSENTITY_HPP_

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

#endif /* !CLASSENTITY_HPP_ */