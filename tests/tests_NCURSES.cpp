/*
** EPITECH PROJECT, 2019
** tests_ncurses.cpp
** File description:
** tests_ncurses
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "class_ncurses.hpp"

Test(tests_NCURSES, test_getIsNewKeyIsTrue)
{
    class_ncurses test;
    bool ret = 0;

    test.setIsNewKey(true);
    ret = test.getIsNewKey();
    cr_assert_eq(ret, true);
}

Test(tests_NCURSES, test_getIsNewKeyIsFalse)
{
    class_ncurses test;
    bool ret = 0;

    test.setIsNewKey(false);
    ret = test.getIsNewKey();
    cr_assert_eq(ret, false);
}

Test(tests_NCURSES, test_getIsNewMapIsTrue)
{
    class_ncurses test;
    bool ret = 0;

    test.setIsNewMap(true);
    ret = test.getIsNewMap();
    cr_assert_eq(ret, true);
}

Test(tests_NCURSES, test_getIsNewMapIsFalse)
{
    class_ncurses test;
    bool ret = 0;

    test.setIsNewMap(false);
    ret = test.getIsNewMap();
    cr_assert_eq(ret, false);
}

Test(tests_NCURSES, test_getLastKeyIsTrue)
{
    class_ncurses test;
    bool ret = 0;

    test.setLastKey(true);
    ret = test.getLastKey();
    cr_assert_eq(ret, true);
}

Test(tests_NCURSES, test_getLastKeyIsFalse)
{
    class_ncurses test;
    bool ret = 0;

    test.setLastKey(false);
    ret = test.getLastKey();
    cr_assert_eq(ret, false);
}