/*
** EPITECH PROJECT, 2019
** ParsingConfig.hpp
** File description:
** ParsingConfig
*/

#pragma once

#include <iostream>
#include <fstream>
#include <vector>

/*!
 * \struct DataParsingConfig
 * \brief This Structure contains all the informations about our sprites, the path to the .bmp, it size in x and y, the ncurses character, the key in the eventuallity it's interactive and the name of the sprite
 */

struct DataParsingConfig {
    std::string path;
    int sizeX;
    int sizeY;
    std::string caractere;
    int launchKey;
    std::string name;
};

/*! \class ParsingConfig
* \brief Class representing parsing logic
*
*  This class contains the fonctions that will read into the configurations files and set the DataParsingConfig structure
*/

class ParsingConfig {
    public:
        ParsingConfig() = default;
        ~ParsingConfig() = default;

        // Members
         void setFilename(std::string name) noexcept {
            _filename = name;
            setIfStream();
        }

        void clearData() {
            _sprite.clear();
        }

        std::vector<DataParsingConfig> getResult() const noexcept {
            return _sprite;
        }

        void readFile() {
            DataParsingConfig data;
            std::fstream file;
            std::string line;

            file.open(_filename, std::fstream::in);
            file.seekg(0, file.beg);
            while (getline(file, line)) {
                data.path = line;
                getline(file, line);
                data.sizeX = std::stoi(line);
                getline(file, line);
                data.sizeY = std::stoi(line);
                getline(file, line);
                data.caractere = line;
                getline(file, line);
                data.launchKey = std::stoi(line);
                getline(file, line);
                data.name = line;
                getline(file, line);
                _sprite.push_back(data);
            }
            file.close();
        }

        void setIfStream() {
            /* 
                _ifs = std::ifstream(_filename, std::ifstream::in);
            */
        }

        std::vector<DataParsingConfig> _sprite;
    private:
        std::string _filename;
};
