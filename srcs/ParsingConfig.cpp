// /*
// ** EPITECH PROJECT, 2019
// ** Core.cpp
// ** File description:
// ** Core
// */

// #include "ParsingConfig.hpp"

// void ParsingConfig::setFilename(std::string name) noexcept
// {
//     _filename = name;
// }

// void ParsingConfig::setIfStream()
// {
// }

// void ParsingConfig::readFile()
// {
//     std::fstream file;
//     std::string line;
//     DataParsingConfig data;

//     file.open(_filename, std::fstream::in);
//     file.seekg(0, file.beg);
//     while (getline(file, line)) {
//         data.path = line;
//         getline(file, line);
//         data.sizeX = std::stoi(line);
//         getline(file, line);
//         data.sizeY = std::stoi(line);
//         getline(file, line);
//         data.caractere = line;
//         _sprite.push_back(data);
//         getline(file, line);
//     }
//     file.close();
// }

// std::vector<DataParsingConfig> ParsingConfig::getResult() const noexcept
// {
//     return (_sprite);
// }