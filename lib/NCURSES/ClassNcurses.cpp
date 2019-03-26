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
    _window_menu_sdl = subwin(stdscr, 3, 11, (LINES / 4) + 3 , (COLS / 2) - 30);
    _window_menu_sfml = subwin(stdscr, 3, 11, (LINES / 4) + 6, (COLS / 2) - 30);
    _window_menu_ncurses = subwin(stdscr, 3, 11, (LINES / 4) + 9, (COLS / 2) - 30);
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

void ClassNcurses::displayGame()
{
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
            if (getLastKey() == 38 || getLastKey() == 39 || getLastKey() == 40)
                return (true);
            break;
    }
    return (false);
}

void ClassNcurses::setMapTexture()
{
    size_t lock_wall = 0;
    size_t posi = 1;
    std::ifstream ncurses("./lib/lib_arcade_ncurses.so");
    std::ifstream sdl("./lib/lib_arcade_sdl.so");
    std::ifstream sfml("./lib/lib_arcade_sfml.so");

    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    move((LINES/2) - (_map->size()/2), (COLS/2) - (_map->begin()->size()/2)); //dimensions de la map
    for (auto it = _map->begin(); it != _map->end(); ++it) {
        for (auto i = it->begin(); i != it->end(); ++i) {
            switch (*i) {
                case NOTHING: printw(" ");
                        break;
                case WALL: attron(COLOR_PAIR(1));
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
                case SDL: if (sdl.good()) {
                            box(_window_menu_sdl, ACS_VLINE, ACS_HLINE);
                            mvwprintw(_window_menu_sdl, 1, 4, "SDL");
                        }
                        break;
                case SFML: if (sfml.good()) {
                            box(_window_menu_sfml, ACS_VLINE, ACS_HLINE);
                            mvwprintw(_window_menu_sfml, 1, 3, "SFML");
                        }
                        break;
                case NCURSES: if (ncurses.good()) {
                            box(_window_menu_ncurses, ACS_VLINE, ACS_HLINE);
                            mvwprintw(_window_menu_ncurses, 1, 2, "NCURSES");
                        }
                        break;
                default: printw(" ");
                        if (i == it->begin())
                            lock_wall++;
                        break;
            }
        }
        printw("\n");
        move((LINES/2) - (_map->size()/2) + posi, (COLS/2) - (_map->begin()->size()/2));
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
    /*attron(A_DIM);
    mvprintw(0, 0, "%s", _str.c_str());
    attroff(A_DIM);*/
    if (getEvent())
        return (false);
    timeout(100);
    refresh();
    return (true);
}

void ClassNcurses::setMap(std::shared_ptr<std::vector<std::string>> map)
{
    _map = std::make_unique<std::vector<std::string>>();
    for (auto it = map->begin(); it != map->end(); ++it) {
        _map->push_back(*it);
    }
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

void ClassNcurses::setScore(size_t score)
{
    _score = score;
}

size_t ClassNcurses::getScore() const
{
    return (_score);
}

extern "C"
{
    IGraphic *entryPoint(void)
    {
        ClassNcurses *instance = new ClassNcurses();
        return (instance);
    }
}

