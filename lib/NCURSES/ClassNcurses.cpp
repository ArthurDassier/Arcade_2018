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
    _isNewMap(false),
    _isNewKey(false),
    _isNewPathConfig(false),
    _window(nullptr, [](WINDOW *){}),
    _window_menu_sdl(nullptr, [](WINDOW *){}),
    _window_menu_sfml(nullptr, [](WINDOW *){}),
    _window_menu_ncurses(nullptr, [](WINDOW *){}),
    _window_pacman(nullptr, [](WINDOW *){})
{
    initscr();
    _window.reset(subwin(stdscr, LINES / 2, COLS, LINES / 4, 0), [](WINDOW *){});
    _window_menu_sdl.reset(subwin(stdscr, 3, 11, (LINES / 4) + 3 , (COLS / 2) - 30), [](WINDOW *){});
    _window_menu_sfml.reset(subwin(stdscr, 3, 11, (LINES / 4) + 9, (COLS / 2) - 30), [](WINDOW *){});
    _window_menu_ncurses.reset(subwin(stdscr, 3, 11, (LINES / 4) + 15, (COLS / 2) - 30), [](WINDOW *){});
    _window_pacman.reset(subwin(stdscr, 3, 11, (LINES / 4) + 9, (COLS / 2) + 10), [](WINDOW *){});
    curs_set(false);
    noecho();
    cbreak();
    keypad(stdscr, true);
    nodelay(stdscr, true);
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
 * \fn ClassNcurses::displayMenu()
 * \brief display the menu
 *
 * \param void
 */

void ClassNcurses::displayMenu()
{
    std::ifstream ncurses("./lib/lib_arcade_ncurses.so");
    std::ifstream sdl("./lib/lib_arcade_sdl2.so");
    std::ifstream sfml("./lib/lib_arcade_sfml.so");

    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    attron(A_DIM);
    if (sdl.good()) {
        box(_window_menu_sdl.get(), ACS_VLINE, ACS_HLINE);
        mvwprintw(_window_menu_sdl.get(), 1, 4, "SDL");
        move((LINES / 4) + 4, (COLS / 2) - 18);
        printw("Press Key : l");
    }
    if (sfml.good()) {
        box(_window_menu_sfml.get(), ACS_VLINE, ACS_HLINE);
        mvwprintw(_window_menu_sfml.get(), 1, 3, "SFML");
        move((LINES / 4) + 10, (COLS / 2) - 18);
        printw("Press Key : k");
    }
    if (ncurses.good()) {
        box(_window_menu_ncurses.get(), ACS_VLINE, ACS_HLINE);
        mvwprintw(_window_menu_ncurses.get(), 1, 2, "NCURSES");
        move((LINES / 4) + 16, (COLS / 2) - 18);
        printw("Press Key : j");
    }
    box(_window_pacman.get(), ACS_VLINE, ACS_HLINE);
    mvwprintw(_window_pacman.get(), 1, 2, "PACMAN");
    move((LINES / 4) + 10, (COLS / 2) + 22);
    printw("Press Key : ENTER");
    move((LINES/2) + 10, (COLS/2) - (12/2));
    printw("For Quit : x");
    attroff(A_DIM);
    attroff(COLOR_PAIR(1));
}

/*!
 * \fn ClassNcurses::displayLetters()
 * \brief Create differents words for the menu
 * 
 * \param void
 */

void ClassNcurses::displayLetters()
{
    std::string str1 = "    /\\    /\\     -------  |\\   |  |    |";
    std::string str2 = "   /  \\  /  \\    |_____   | \\  |  |    |";
    std::string str3 = "  /    \\/    \\   |        |  \\ |  |    |";
    std::string str4 = " /            \\  -------  |   \\|  |____|";
    std::vector<std::string> vec_menu;
    std::string str5 = "    ----     -------  /-----     ----     ------\\   -------";
    std::string str6 = "   /    \\    |     |  |         /    \\    |      |  |_____";
    std::string str7 = "  /------\\   |------  |        /------\\   |      |  |";
    std::string str8 = " /        \\  |     \\  \\-----  /        \\  ------/   -------";
    std::vector<std::string> vec_arcade;

    vec_menu.push_back(str1);
    vec_menu.push_back(str2);
    vec_menu.push_back(str3);
    vec_menu.push_back(str4);
    vec_arcade.push_back(str5);
    vec_arcade.push_back(str6);
    vec_arcade.push_back(str7);
    vec_arcade.push_back(str8);
    int posi = 16;

    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(5));
    attron(A_BOLD);
    for (auto it = vec_menu.begin(); it != vec_menu.end(); it++) {
        move((LINES/2) - posi, (COLS/2) - (str1.size()/2));
        printw("%s\n", it->c_str());
        posi--;
    }
    attroff(COLOR_PAIR(5));
    posi = 12;
    attron(COLOR_PAIR(6));
    for (auto it = vec_arcade.begin(); it != vec_arcade.end(); it++) {
        move((LINES/2) + posi, (COLS/2) - (str5.size()/2));
        printw("%s\n", it->c_str());
        posi++;
    }
    attroff(COLOR_PAIR(6));
    attroff(A_BOLD);
}

/*!
 * \fn ClassNcurses::displayGame()
 * \brief Translate the game's map and print it
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
    size_t lock_wall = 0;
    size_t posi = 1;

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

    if (wall.compare("sfml") == false) {
        displayMenu();
        displayLetters();
        return;
    }

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
        default:
            translateKey();
            break;
    }
    return (false);
}

/*!
 * \fn ClassNcurses::runGraph()
 * \brief Main fct manage the events, prints and create map
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
    if (_isNewMap) {
        clear();
        displayGame();
        wborder(_window.get(), '|', '|', '-', '-', '+', '+', '+', '+');
        refresh();
        _isNewMap = false;
    }
    if (getEvent())
        return (true);
    return (false);
}

/*!
 * \fn ClassNcurses::buildMap()
 * \brief do nothing
 * 
 * \param std::shared_ptr<std::vector<std::string>>
 */

void ClassNcurses::buildMap(std::shared_ptr<std::vector<std::string>> map = nullptr)
{

}

/*!
 * \fn ClassNcurses::setMapTexture()
 * \brief do nothing
 * 
 * \param void
 */

void ClassNcurses::setMapTexture()
{

}

/*!
 * \fn ClassNcurses::setMap()
 * \brief Change the char in our _map of textures corresponding to the map
 *
 * \param std::shared_ptr<std::vector<std::string>>
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
    for (size_t i = 0; KeyNcurses[i].code_lib != 1000; ++i) {
        if (_c == KeyNcurses[i].code_lib) {
            setLastKey(KeyNcurses[i].code_core);
            setIsNewKey(true);
            break;
        }
    }
}

/*!
 * \fn ClassNcurses::setIsNewMap()
 * \brief set bool if there's a new map
 *
 * \param bool
 */

void ClassNcurses::setIsNewMap(bool NewMap)
{
    _isNewMap = NewMap;
}

/*!
 * \fn ClassNcurses::getIsNewMap()
 * \brief return bool if there's a new map
 *
 * \param void
 */

bool ClassNcurses::getIsNewMap() const
{
    return (_isNewMap);
}

/*!
 * \fn ClassNcurses::setIsNewKey()
 * \brief set bool if there's a new key press
 *
 * \param bool
 */

void ClassNcurses::setIsNewKey(bool NewKey)
{
    _isNewKey = NewKey;
}

/*!
 * \fn ClassNcurses::getIsNewKey()
 * \brief return bool if there's a new key use
 *
 * \param void
 */

bool ClassNcurses::getIsNewKey() const
{
    return (_isNewKey);
}

/*!
 * \fn ClassNcurses::setLastKey()
 * \brief set the int key when a key is press
 *
 * \param int
 */

void ClassNcurses::setLastKey(int key)
{
    _key = key;
}

/*!
 * \fn ClassNcurses::getLastKey()
 * \brief return the int key when a key is press
 *
 * \param void
 */

int ClassNcurses::getLastKey() const
{
    return (_key);
}

/*!
 * \fn ClassNcurses::setScore()
 * \brief set the score when you're playing
 *
 * \param size_t
 */

void ClassNcurses::setScore(size_t score)
{
    _score = score;
}

/*!
 * \fn ClassNcurses::getScore()
 * \brief return the score when you finish to play
 *
 * \param void
 */

size_t ClassNcurses::getScore() const
{
    return (_score);
}

/*!
 * \fn ClassNcurses::setPathConfig()
 * \brief set when there's a new path config
 *
 * \param std::string
 */

void ClassNcurses::setPathConfig(std::string path) noexcept
{
    _pathConfig = path;
}

/*!
 * \fn ClassNcurses::getPathConfig()
 * \brief return the actual path config
 *
 * \param void
 */

std::string ClassNcurses::getPathConfig() const noexcept
{
    return (_pathConfig);
}

/*!
 * \fn ClassNcurses::setIsNewPathConfig()
 * \brief set bool if a new path config is set
 *
 * \param bool 
 */

void ClassNcurses::setIsNewPathConfig(bool isNewPath) noexcept
{
    _isNewPathConfig = isNewPath;
}

/*!
 * \fn ClassNcurses::getIsNewPathConfig()
 * \brief return bool if a new path config is set
 *
 * \param void 
 */

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

