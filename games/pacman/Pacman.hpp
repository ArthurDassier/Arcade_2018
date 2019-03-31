/*
** EPITECH PROJECT, 2019
** Pacman.hpp
** File description:
** Pacman
*/

#pragma once

#include "Entity.hpp"
#include "IGame.hpp"

class Pacman : public IGame
{
    public:
        Pacman();
        ~Pacman();

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

        const std::string getPathConfig() const noexcept;
        const std::string getPathMap() const noexcept;

    private:
        std::string _pathConfig = "./games/pacman/config/sprites.config";
        std::string _pathMap = "./games/pacman/config/map.config";
        bool _isNewMap;
        std::shared_ptr<std::vector<std::string>> _map;
        std::map<size_t, std::map<size_t, char>> _tmp;
        Move _lastMove;
        clock_t _clock[4];
        time_t _start;
        int _key;
        bool _isNewKey;
        size_t _score;
        bool _canMove;
        bool _bonus;
        bool _lock_create_map;
        // std::unique_ptr<Entity> _pacman;
        Entity *_pacman;
        // std::vector<std::unique_ptr<Entity>> _ghosts;
        std::vector<Entity *> _ghosts;
};