/*
** EPITECH PROJECT, 2019
** ClassPacman.hpp
** File description:
** ClassPacman
*/

#ifndef CLASSPACMAN_HPP_
    #define CLASSPACMAN_HPP_

#include "IGame.hpp"

class ClassPacman : public IGame
{
    public:
        ClassPacman();
        ~ClassPacman();

        bool runGame();
        void setMap(std::shared_ptr<std::vector<std::string>>);
        std::shared_ptr<std::vector<std::string>> getMap(void) const;

        void setIsNewMap(bool);
        bool getIsNewMap(void) const;

        void setIsNewKey(bool);
        bool getIsNewKey(void) const;

        void setLastKey(int);
        int getLastKey(void) const;

        void setScore(size_t);
        size_t getScore() const;

        void setBonus(bool);
        bool getBonus(void) const;

        enum Move {
            RIGHT = 3,
            LEFT = 16,
            DOWN = 18,
            UP = 25
        };

        void setLastMove(Move);
        Move getLastMove() const;

        void moveDown(void);
        void moveLeft(void);
        void moveRight(void);
        void moveUp(void);

        void checkNextCase(char);

	private:
        bool _isNewMap;
        std::shared_ptr<std::vector<std::string>> _map;
        Move _lastMove;
        time_t _start;
        int _key;
        bool _isNewKey;
        size_t _score;
        bool _bonus;
};

#endif /* !CLASSPACMAN_HPP_ */