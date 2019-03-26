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

        void setIsNewMap(bool);
        bool getIsNewMap(void) const;

        void setIsNewKey(bool);
        bool getIsNewKey(void) const;

        void setLastKey(int);
        int getLastKey(void) const;

        void moveDown(void);
        void moveLeft(void);
        void moveRight(void);
        void moveUp(void);

	private:
        // void setMap(std::shared_ptr<ICore::map_t> map);
        bool _isNewMap = 0;
        std::unique_ptr<std::vector<std::string>> _map;
        // std::shared_ptr<ICore::map_t> _map;
        clock_t _clock;
        int _key;
        bool _isNewKey;
};

#endif /* !CLASSPACMAN_HPP_ */