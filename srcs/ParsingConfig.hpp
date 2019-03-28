#include <vector>
#include <fstream>
#include <iostream>

struct DataParsingConfig {
    std::string path;
    int sizeX;
    int sizeY;
    std::string caractere;
};

class ParsingConfig {
    public:
        ParsingConfig() = default;
        ~ParsingConfig() = default;
        inline void setFilename(std::string name) noexcept {
            _filename = name;
        }
        void setIfStream();
        void readFile() {
            std::fstream file;
            std::string line;
            DataParsingConfig data;

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
                _sprite.push_back(data);
                getline(file, line);
            }
            file.close();
        }
        inline std::vector<DataParsingConfig> getResult() const noexcept { 
            return (_sprite);
        }

    private:
        std::vector<DataParsingConfig> _sprite;
        std::string _filename;
};
