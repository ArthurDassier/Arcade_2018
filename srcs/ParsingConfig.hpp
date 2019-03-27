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
        inline void setFilename(std::string name) noexcept;
        inline void setIfStream();
        void readFile();
        inline std::vector<DataParsingConfig> getResult() const noexcept;

    private:
        std::vector<DataParsingConfig> _sprite;
        std::string _filename;
};
