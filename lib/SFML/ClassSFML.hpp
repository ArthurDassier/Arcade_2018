/*
** EPITECH PROJECT, 2019
** ClassSFML.hpp
** File description:
** ClassSFML
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include "IGraphic.hpp"
#include "../srcs/ParsingConfig.hpp"

#define SCREEN_POS {675, 225}

enum Graphics {
    NOTHING = '0',
    WALL = '1',
    POINT = '2',
    PLAYER = '3',
    ENEMY = '4',
    BONUS = '5',
    SDL = '6',
    SFML = '7',
    NCURSES = '8'
};

/*! \class ClassSFML
* \brief Class representing ClassSFML logic
*
*  This class contains the fonctions that handle the SFML
*/

class ClassSFML : public IGraphic
{
    public:
        ClassSFML();
        ~ClassSFML();

        //Members
        bool runGraph();
        void setMap(std::shared_ptr<std::vector<std::string>>);
        void translateKey();

        void setIsNewMap(bool);
        bool getIsNewMap(void) const;

        void setIsNewKey(bool);
        bool getIsNewKey(void) const;

        void setLastKey(int);
        int getLastKey(void) const;

        void setScore(size_t);
        size_t getScore() const;

        void setPathConfig(std::string) noexcept;
        std::string getPathConfig() const noexcept;

        void setIsNewPathConfig(bool) noexcept;
        bool getIsNewPathConfig() const noexcept;

        bool getEvent();
        void setMapTexture(void);
        void displayGame(void);

        void buildMap(std::shared_ptr<std::vector<std::string>>);

    private:
        std::unique_ptr<sf::RenderWindow> _wind;
        std::unique_ptr<std::vector<std::vector<std::pair<char, sf::Sprite>>>> _map;

        sf::Event _event;
        ParsingConfig _parsing;
        std::vector<std::pair<sf::Vector2i, std::shared_ptr<sf::Texture>>> _textures;

        std::string _pathConfig;
        bool _isNewPathConfig;
        bool _isNewMap;
        bool _isNewKey;
        size_t _score;
        int _key;
};

struct KeySFML {
    int code_lib;
    int code_core;
};

static struct KeySFML KeySFML[] = {
    {0, 0},
    {1, 1},
    {2, 2},
    {3, 3},
    {4, 4},
    {5, 5},
    {6, 6},
    {7, 7},
    {8, 8},
    {9, 9},
    {10, 10},
    {11, 11},
    {12, 12},
    {13, 13},
    {14, 14},
    {15, 15},
    {16, 16},
    {17, 17},
    {18, 18},
    {19, 19},
    {20, 20},
    {21, 21},
    {22, 22},
    {23, 23},
    {24, 24},
    {25, 25},
    {75, 26},
    {76, 27},
    {77, 28},
    {78, 29},
    {79, 30},
    {80, 31},
    {81, 32},
    {82, 33},
    {83, 34},
    {84, 35},
    {73, 36}, // Up
    {74, 37}, // Down
    {72, 38}, // Right
    {71, 39}, // Left
    {58, 40}, // Enter
    {57, 41}, // Space
    {59, 42}, // BackSpace
    {60, 43}, // Tab
    {-1, -1},
};

