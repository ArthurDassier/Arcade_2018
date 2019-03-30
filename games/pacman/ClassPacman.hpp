/*
** EPITECH PROJECT, 2019
** ClassPacman.hpp
** File description:
** ClassPacman
*/

#pragma once

#include "ClassEntity.hpp"
#include "IGame.hpp"

class ClassPacman : public IGame
{
    public:
        ClassPacman();
        ~ClassPacman();

        bool runGame();
        void setMap(std::shared_ptr<std::vector<std::string>>);
        std::shared_ptr<std::vector<std::string>> getMap(void) const;
        void readMap(void);

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

        void setMove(Move);
        Move getMove() const;
        bool canMove() const;

        void moveDown(void);
        void moveLeft(void);
        void moveRight(void);
        void moveUp(void);

        void checkNextCase(char);

        std::string getPathConfig() const noexcept;
        std::string getPathMap() const noexcept;

    private:
        std::string _pathConfig;
        std::string _pathMap;
        bool _isNewMap;
        std::shared_ptr<std::vector<std::string>> _map;
        Move _lastMove;
        clock_t _clock;
        time_t _start;
        int _key;
        bool _isNewKey;
        size_t _score;
        bool _canMove;
        bool _bonus;
        bool _lock_create_map;
};
