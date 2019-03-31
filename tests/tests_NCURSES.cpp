/*
** EPITECH PROJECT, 2019
** tests_ncurses.cpp
** File description:
** tests_ncurses
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ClassNcurses.hpp"

Test(tests_NCURSES, test_getIsNewKeyIsTrue)
{
    ClassNcurses test;
    bool ret = 0;

    test.setIsNewKey(true);
    ret = test.getIsNewKey();
    cr_assert_eq(ret, true);
}

Test(tests_NCURSES, test_getIsNewKeyIsFalse)
{
    ClassNcurses test;
    bool ret = 0;

    test.setIsNewKey(false);
    ret = test.getIsNewKey();
    cr_assert_eq(ret, false);
}

Test(tests_NCURSES, test_getIsNewMapIsTrue)
{
    ClassNcurses test;
    bool ret = 0;

    test.setIsNewMap(true);
    ret = test.getIsNewMap();
    cr_assert_eq(ret, true);
}

Test(tests_NCURSES, test_getIsNewMapIsFalse)
{
    ClassNcurses test;
    bool ret = 0;

    test.setIsNewMap(false);
    ret = test.getIsNewMap();
    cr_assert_eq(ret, false);
}

Test(tests_NCURSES, test_getLastKeyIsTrue)
{
    ClassNcurses test;
    bool ret = 0;

    test.setLastKey(true);
    ret = test.getLastKey();
    cr_assert_eq(ret, true);
}

Test(tests_NCURSES, test_getLastKeyIsFalse)
{
    ClassNcurses test;
    bool ret = 0;

    test.setLastKey(false);
    ret = test.getLastKey();
    cr_assert_eq(ret, false);
}

Test(tests_NCURSES, test_getScore)
{
    ClassNcurses test;
    int ret = 0;

    test.setScore(0);
    ret = test.getScore();
    cr_assert_eq(ret, 0);
    test.setScore(10);
    ret = test.getScore();
    cr_assert_eq(ret, 10);
    test.setScore(900);
    ret = test.getScore();
    cr_assert_eq(ret, 900);
}

Test(tests_NCURSES, test_getPathConfig)
{
    ClassNcurses test;
    std::string ret = "";

    test.setPathConfig("");
    ret = test.getPathConfig();
    cr_assert_eq(ret, "");
    test.setPathConfig("coucou");
    ret = test.getPathConfig();
    cr_assert_eq(ret, "coucou");
    test.setPathConfig("./srcs/core/path_menu.config");
    ret = test.getPathConfig();
    cr_assert_eq(ret, "./srcs/core/path_menu.config");
}

Test(tests_NCURSES, test_getIsNewPathConfigIsTrue)
{
    ClassNcurses test;
    bool ret = 0;

    test.setIsNewPathConfig(true);
    ret = test.getIsNewPathConfig();
    cr_assert_eq(ret, true);
}

Test(tests_NCURSES, test_getIsNewPathConfigIsFalse)
{
    ClassNcurses test;
    bool ret = 0;

    test.setIsNewPathConfig(false);
    ret = test.getIsNewPathConfig();
    cr_assert_eq(ret, false);
}