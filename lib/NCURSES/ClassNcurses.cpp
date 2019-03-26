/*
** EPITECH PROJECT, 2019
** ClassNcurses.cpp
** File description:
** ClassNcurses
*/

#include "ClassNcurses.hpp"

ClassNcurses::ClassNcurses() :
    _key(999),
    _str(""),
    _isNewKey(false)
{
    initscr();
    _window = subwin(stdscr, LINES / 2, COLS, LINES / 4, 0);
    curs_set(false);
    noecho();
    cbreak();
    keypad(stdscr, true);
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
        case 'a':
            setLastKey(0);
            return (true);
        default:
            translateKey();
            if (getLastKey() == 38 || getLastKey() == 39)
                return (true);
            break;
    }
    return (false);
}

void ClassNcurses::setMapTexture()
{
    size_t lock_wall = 0;
    size_t posi = 2;
    size_t length = _map->begin()->size();
    size_t height = _map->size();

    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    move((LINES/2) - (height/2) + 1, (COLS/2) - (length/2)); //dimensions de la map
    for (auto it = _map->begin(); it != _map->end(); ++it) {
        for (auto i = it->begin(); i != it->end(); ++i) {
            switch (*i) {
                case NOTHING: printw(" ");
                        break;
                case WALL: attron(COLOR_PAIR(1));
                        if (it == _map->begin() || ((it + 2) == _map->end()))
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
                case POINT: printw("*");
                        break;
                case PLAYER: attron(COLOR_PAIR(2));
                        printw("<");
                        attroff(COLOR_PAIR(2));
                        break;
                case GHOST: printw("M");
                        break;
                case BONUS: printw("o");
                        break;
                default: printw(" ");
                        if (i == it->begin())
                            lock_wall++;
                        break;
            }
        }
        printw("\n");
        move((LINES/2) - (height/2) + posi, (COLS/2) - (length/2));
        posi++;
    }
}

int ClassNcurses::get_input()
{
    std::string str = get_string();
    int tmp_c = getLastKey();

    if (getIsNewKey() == false)
        return (0);
    if (tmp_c != 999) {
        if (tmp_c == 42 && _str.empty() == false)
            _str.pop_back();
        else if (tmp_c != 41 && tmp_c != 42)
            _str.push_back(translate_for_menu(tmp_c) - 32);
        setIsNewKey(false);
    }
}

std::string ClassNcurses::get_string()
{
    return (_str);
}

char ClassNcurses::translate_for_menu(int nb)
{
    for (size_t i = 0; KeyNcurses[i].code_lib != 1000; ++i) {
            if (nb == KeyNcurses[i].code_core)
                return (KeyNcurses[i].code_lib);
        }
}

bool ClassNcurses::runGraph()
{
    clear();
    setMapTexture();
    wborder(_window, '|', '|', '-', '-', '+', '+', '+', '+');
    get_input();
    attron(A_DIM);
    mvprintw(0, 0, "%s", _str.c_str());
    attroff(A_DIM);
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
                setIsNewKey(true);
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
