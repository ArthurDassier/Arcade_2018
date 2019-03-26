/*
** EPITECH PROJECT, 2019
** ClassPacman.cpp
** File description:
** ClassPacman
*/

#include "ClassPacman.hpp"

ClassPacman::ClassPacman()
{
    std::string line;
    std::ifstream map_file("map.txt");

    if (map_file) {
        while (getline(map_file, line)) {
            std::cout << line << std::endl;
        }
        map_file.close();
    }
}

ClassPacman::~ClassPacman()
{
}

bool ClassPacman::runGame()
{
    std::cout << "runGame" << std::endl;
}

void ClassPacman::setIsNewMap(bool)
{

}

bool ClassPacman::getIsNewMap(void) const
{
    
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

void ClassPacman::moveDown(void)
{

}

void ClassPacman::moveLeft(void)
{

}

void ClassPacman::moveRight(void)
{

}

void ClassPacman::moveUp(void)
{

}