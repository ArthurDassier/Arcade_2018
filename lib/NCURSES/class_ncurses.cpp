/*
** EPITECH PROJECT, 2019
** class_ncurses.cpp
** File description:
** class_ncurses
*/

#include <iostream>
#include "class_ncurses.hpp"

class_ncurses::class_ncurses()
{
    initscr();
    curs_set(FALSE);
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    _key = 999;
    start_color();
}

class_ncurses::~class_ncurses()
{
    endwin();
}

bool class_ncurses::get_event()
{
    _c = getch();
    switch (_c) {
        case 'Q': return (true);
            break;
        default:
            translateKey();
            break;
    }
    return (false);
}

void class_ncurses::set_map_texture()
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

bool class_ncurses::runGraph()
{
    clear();
    //printw("%d\n", this->getLastKey());
    set_map_texture();
    if (get_event())
        return (false);
    timeout(100);
    refresh();
    return (true);
}

void class_ncurses::setMap()
{
    //while gnl sur un fichier en brute
    //regle : 0->rien 1->mur 2->miamiam 3->miamiam2 4->perso 5->enemi
    std::string tmp;
    std::ifstream file;

    _map = std::make_unique<std::vector<std::string>>();
    file.open("pacman.txt");
    if (file.is_open() == false)
        std::cout << "FAIL" << std::endl;
    while (!file.eof()) {
        getline(file, tmp);
        _map->push_back(tmp);
    }
    file.close();
}

void class_ncurses::translateKey()
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

void class_ncurses::setIsNewMap(bool NewMap)
{
    _isNewMap = NewMap;
}

bool class_ncurses::getIsNewMap(void) const
{
    return (_isNewMap);
}

void class_ncurses::setIsNewKey(bool NewKey)
{
    _isNewKey = NewKey;
}

bool class_ncurses::getIsNewKey(void) const
{
    return (_isNewKey);
}

void class_ncurses::setLastKey(int key)
{
    _key = key;
}

int class_ncurses::getLastKey(void) const
{
    return (_key);
}

extern "C"
{
    IGraphic *entryPoint(void)
    {
        class_ncurses *instance = new class_ncurses();
        return (instance);
    }
}
