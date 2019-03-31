/*
** EPITECH PROJECT, 2019
** ClassNcurses.cpp
** File description:
** ClassNcurses
*/

#include "ClassNcurses.hpp"

/*!
 * \fn ClassNcurses::ClassNcurses()
 * \brief Create the Ncurses window and set the getters at false
 * it also creates subwindows for the menu
 * \param void
 */

ClassNcurses::ClassNcurses() :
    _key(999),
    _str(""),
    _posi_menu(0),
    _isNewMap(false),
    _isNewKey(false),
    _isNewPathConfig(false)
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

/*!
 * \fn ClassNcurses::~ClassNcurses()
 * \brief Ncurses Class destructor, just quit the Ncurses
 *
 * \param void
 */

ClassNcurses::~ClassNcurses()
{
    endwin();
}
/*!
 * \fn ClassNcurses::displayGame()
 * \brief Print the game in Ncurses format
 *
 * \param void
 */
void ClassNcurses::displayGame()
{
    std::vector<DataParsingConfig> parsingResult = _parsing.getResult();
    std::string wall;
    std::string miam;
    std::string perso;
    std::string enemy;
    std::string super_miam;
    int i = 0;
    for (auto it = parsingResult.begin(); it != parsingResult.end(); ++it) {
        switch (i) {
            case 1:
                wall = it->caractere;
                break;
            case 2:
                miam = it->caractere;
                break;
            case 3:
                perso = it->caractere;
                break;
            case 4:
                enemy = it->caractere;
                break;
            case 5:
                super_miam = it->caractere;
                break;
            default:
                break;
        }
        i++;
    }
    size_t lock_wall = 0;
    size_t posi = 1;
    std::ifstream ncurses("./lib/lib_arcade_ncurses.so");
    std::ifstream sdl("./lib/lib_arcade_sdl2.so");
    std::ifstream sfml("./lib/lib_arcade_sfml.so");

    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_WHITE);
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
                            printw("%s", wall.c_str());
                        attroff(COLOR_PAIR(1));
                        break;
                case POINT: printw("%s", miam.c_str());
                        break;
                case PLAYER: attron(COLOR_PAIR(2));
                        printw("%s", perso.c_str());
                        attroff(COLOR_PAIR(2));
                        break;
                case GHOST: printw("%s", enemy.c_str());
                        break;
                case BONUS: printw("%s", super_miam.c_str());
                        break;
                /*case SDL: if (sdl.good()) {
                            if (_posi_menu == 0)
                                box(_window_menu_sdl, ACS_VLINE, ACS_HLINE);
                            mvwprintw(_window_menu_sdl, 1, 4, "SDL");
                        }
                        break;
                case SFML: if (sfml.good()) {
                            if (_posi_menu == 1)
                                box(_window_menu_sfml, ACS_VLINE, ACS_HLINE);
                            mvwprintw(_window_menu_sfml, 1, 3, "SFML");
                        }
                        break;
                case NCURSES: if (ncurses.good()) {
                                if (_posi_menu == 2)
                                    box(_window_menu_ncurses, ACS_VLINE, ACS_HLINE);
                                mvwprintw(_window_menu_ncurses, 1, 2, "NCURSES");
                        }
                        break;*/
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
    wborder(_window, '|', '|', '-', '-', '+', '+', '+', '+');
    ncurses.close();
    sdl.close();
    sfml.close();
}

/*!
 * \fn ClassNcurses::getEvent()
 * \brief Handle the events of the Ncurses
 *
 * \param void
 */

bool ClassNcurses::getEvent()
{
    _c = getch();

    switch (_c) {
        case ERR:
            break;
        case 'x':
            setLastKey(0);
            return (true);
        case 'r':
            if (_posi_menu == 0)
                _posi_menu = 2;
            else
                _posi_menu -= 1;
            break;
        case 'f':
            if (_posi_menu == 2)
                _posi_menu = 0;
            else
                _posi_menu += 1;
            break;
        default:
            translateKey();
            break;
    }
    return (false);
}
/*!
 * \fn ClassNcurses::get_input()
 * \brief Handle the inputs of the user
 *
 * \param void
 */
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
/*!
 * \fn ClassNcurses::runGraph()
 * \brief Handle the events of the Ncurses
 *
 * \param void
 */
bool ClassNcurses::runGraph()
{
    if (getIsNewPathConfig() == true) {
        _parsing.clearData();
        setIsNewPathConfig(false);
        _parsing.setFilename(getPathConfig());
        _parsing.readFile();
        setMapTexture();
    }
    //setMapTexture();
    //wborder(_window, '|', '|', '-', '-', '+', '+', '+', '+');
    /*get_input();
    attron(A_DIM);
    mvprintw(0, 0, "%s", _str.c_str());
    attroff(A_DIM);*/
    if (getEvent())
        return (true);
    if (_isNewMap) {
        clear();
        displayGame();
        _isNewMap = false;
    }
    //timeout(100);
    refresh();
    return (false);
}

void ClassNcurses::setMapTexture()
{
    // std::vector<DataParsingConfig> parsingResult = _parsing.getResult();
    // std::string wall;
    // std::string miam;
    // std::string perso;
    // std::string enemy;
    // std::string super_miam;
    // int i = 0;
    // for (auto it = parsingResult.begin(); it != parsingResult.end(); ++it) {
    //     switch (i) {
    //         case 0:
    //             wall = it->caractere;
    //             break;
    //         case 1:
    //             miam = it->caractere;
    //             break;
    //         case 2:
    //             perso = it->caractere;
    //             break;
    //         case 3:
    //             enemy = it->caractere;
    //             break;
    //         case 4:
    //             super_miam = it->caractere;
    //             break;
    //         default:
    //             break;
    //     }
    //     i++;
    // }
    // size_t lock_wall = 0;
    // size_t posi = 1;
    // std::ifstream ncurses("./lib/lib_arcade_ncurses.so");
    // std::ifstream sdl("./lib/lib_arcade_sdl2.so");
    // std::ifstream sfml("./lib/lib_arcade_sfml.so");

    // init_pair(1, COLOR_BLUE, COLOR_BLACK);
    // init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    // init_pair(3, COLOR_BLUE, COLOR_WHITE);
    // move((LINES/2) - (_map->size()/2), (COLS/2) - (_map->begin()->size()/2)); //dimensions de la map
    // for (auto it = _map->begin(); it != _map->end(); ++it) {
    //     for (auto i = it->begin(); i != it->end(); ++i) {
    //         switch (*i) {
    //             case NOTHING: printw(" ");
    //                     break;
    //             case WALL: attron(COLOR_PAIR(1));
    //                     if (it == _map->begin() || ((it + 1) == _map->end()))
    //                         printw("-");
    //                     else if (i == it->begin() || ((i + 1) == it->end()))
    //                         printw("|");
    //                     else if (lock_wall != 0) {
    //                         printw("|");
    //                         lock_wall = 0;
    //                     } else
    //                         printw("%s", wall.c_str());
    //                     attroff(COLOR_PAIR(1));
    //                     break;
    //             case POINT: printw("%s", miam.c_str());
    //                     break;
    //             case PLAYER: attron(COLOR_PAIR(2));
    //                     printw("%s", perso.c_str());
    //                     attroff(COLOR_PAIR(2));
    //                     break;
    //             case GHOST: printw("%s", enemy.c_str());
    //                     break;
    //             case BONUS: printw("%s", super_miam.c_str());
    //                     break;
    //             case SDL: if (sdl.good()) {
    //                         if (_posi_menu == 0)
    //                             box(_window_menu_sdl, ACS_VLINE, ACS_HLINE);
    //                         mvwprintw(_window_menu_sdl, 1, 4, "SDL");
    //                     }
    //                     break;
    //             case SFML: if (sfml.good()) {
    //                         if (_posi_menu == 1)
    //                             box(_window_menu_sfml, ACS_VLINE, ACS_HLINE);
    //                         mvwprintw(_window_menu_sfml, 1, 3, "SFML");
    //                     }
    //                     break;
    //             case NCURSES: if (ncurses.good()) {
    //                             if (_posi_menu == 2)
    //                                 box(_window_menu_ncurses, ACS_VLINE, ACS_HLINE);
    //                             mvwprintw(_window_menu_ncurses, 1, 2, "NCURSES");
    //                     }
    //                     break;
    //             default: printw(" ");
    //                     if (i == it->begin())
    //                         lock_wall++;
    //                     break;
    //         }
    //     }
    //     printw("\n");
    //     move((LINES/2) - (_map->size()/2) + posi, (COLS/2) - (_map->begin()->size()/2));
    //     posi++;
    // }
}

void ClassNcurses::buildMap(std::shared_ptr<std::vector<std::string>> map = nullptr)
{

}
/*!
 * \fn ClassNcurses::setMap()
 * \brief Change the char in our _map of textures corresponding to the map
 *
 * \param std::shared_ptr<std::vector<std::string>> map
 */
void ClassNcurses::setMap(std::shared_ptr<std::vector<std::string>> map)
{
    if (!map)
        return;
    _map = std::make_unique<std::vector<std::string>>();
    for (auto it = map->begin(); it != map->end(); ++it) {
        _map->push_back(*it);
    }
}

/*!
 * \fn ClassNcurses::translateKey()
 * \brief Translate the Ncurses event key to the keycode that the core will understand
 *
 * \param void
 */


void ClassNcurses::translateKey()
{
    if (_c != ERR) {
        for (size_t i = 0; KeyNcurses[i].code_lib != 1000; ++i) {
            if (_c == KeyNcurses[i].code_lib) {
                setLastKey(KeyNcurses[i].code_core);
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

void ClassNcurses::setPathConfig(std::string path) noexcept
{
    _pathConfig = path;
}

std::string ClassNcurses::getPathConfig() const noexcept
{
    return (_pathConfig);
}

void ClassNcurses::setIsNewPathConfig(bool isNewPath) noexcept
{
    _isNewPathConfig = isNewPath;
}

bool ClassNcurses::getIsNewPathConfig() const noexcept
{
    return (_isNewPathConfig);
}

extern "C"
{
    IGraphic *entryPoint(void)
    {
        ClassNcurses *instance = new ClassNcurses();
        return (instance);
    }
}

