/*
** EPITECH PROJECT, 2019
** ClassNcurses.cpp
** File description:
** ClassNcurses
*/

#include "ClassNcurses.hpp"

ClassNcurses::ClassNcurses() :
    _key(999)
{
    initscr();
    curs_set(FALSE);
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    start_color();
}

ClassNcurses::~ClassNcurses()
{
    endwin();
}

bool ClassNcurses::getEvent()
{
    _c = getch();

    switch (_c) {
        case 'Q':
            return (true);
            break;
        default:
            translateKey();
            break;
    }
    return (false);
}

void ClassNcurses::setMapTexture()
{
    size_t lock_wall = 0;

    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    for (auto it = _map->begin(); it != _map->end(); ++it) {
        for (auto i = it->begin(); i != it->end(); ++i)
            switch (*i) {
                case '0': printw(" ");
                        break;
                case '1': attron(COLOR_PAIR(1));
                        if (it == _map->begin() || ((it + 1) == _map->end()))
                            printw("-");
                        else if (i == it->begin() || ((i + 1) == it->end()))
                            printw("|");
                        else if (lock_wall != 0) {
                            printw("|");
                            lock_wall = 0;
                        } else
                            printw("#");
                        attroff(COLOR_PAIR(1));
                        break;
                case '2': printw("*");
                        break;
                case '3': printw("o");
                        break;
                case '4': attron(COLOR_PAIR(2));
                        printw("<");
                        attroff(COLOR_PAIR(2));
                        break;
                case '5': printw("M");
                        break;
                default: printw(" ");
                        if (i == it->begin())
                            lock_wall++;
                        break;
            }
        printw("\n");
    }
}

bool ClassNcurses::runGraph()
{
    clear();
    setMapTexture();
    if (getEvent())
        return (false);
    timeout(100);
    refresh();
    return (true);
}

void ClassNcurses::setMap()
{
    std::string tmp;
    std::ifstream file;

    _map = std::make_unique<std::vector<std::string>>();
    file.open("./map.txt");
    if (file.is_open() == false)
        std::cout << "FAIL" << std::endl;
    while (!file.eof()) {
        getline(file, tmp);
        _map->push_back(tmp);
    }
    file.close();
}

void ClassNcurses::translateKey()
{
    if (_c != ERR) {
        for (size_t i = 0; KeyNcurses[i].code_lib != 1000; ++i) {
            if (_c == KeyNcurses[i].code_lib) {
                this->setLastKey(KeyNcurses[i].code_core);
                break;
            }
        }
    }
}

void ClassNcurses::setIsNewMap(bool NewMap)
{
    _isNewMap = NewMap;
}

bool ClassNcurses::getIsNewMap(void) const
{
    return (_isNewMap);
}

void ClassNcurses::setIsNewKey(bool NewKey)
{
    _isNewKey = NewKey;
}

bool ClassNcurses::getIsNewKey(void) const
{
    return (_isNewKey);
}

void ClassNcurses::setLastKey(int key)
{
    _key = key;
}

int ClassNcurses::getLastKey(void) const
{
    return (_key);
}

extern "C"
{
    IGraphic *entryPoint(void)
    {
        ClassNcurses *instance = new ClassNcurses();
        return (instance);
    }
}
