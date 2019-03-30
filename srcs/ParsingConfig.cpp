/*
** EPITECH PROJECT, 2019
** ParsingConfig.cpp
** File description:
** ParsingConfig
*/

// #include "ParsingConfig.hpp"

// ParsingConfig::ParsingConfig()
// {
// }

// ParsingConfig::~ParsingConfig()
// {
// }

// void ParsingConfig::setIfStream()
// {
// // _ifs = std::ifstream(_filename, std::ifstream::in);
// }

// void ParsingConfig::clearData()
// {
//     _sprite.clear();
// }

// void ParsingConfig::setFilename(std::string name) noexcept
// {
//     _filename = name;
//     setIfStream();
// }

// std::vector<DataParsingConfig> ParsingConfig::getResult() const noexcept
// {
//     return (_sprite);
// }

// void ParsingConfig::readFile()
// {
//     std::fstream file;
//     file.open(_filename, std::fstream::in);
//     file.seekg(0, file.beg);
//     std::string line;
//     DataParsingConfig data;
//     while (getline(file, line)) {
//         data.path = line;
//         getline(file, line);
//         data.sizeX = std::stoi(line);
//         getline(file, line);
//         data.sizeY = std::stoi(line);
//         getline(file, line);
//         data.caractere = line;
//         getline(file, line);
//         data.launchKey = std::stoi(line);
//         getline(file, line);
//         data.name = line;
//         getline(file, line);
//         _sprite.push_back(data);
//     }
//     file.close();
// }
