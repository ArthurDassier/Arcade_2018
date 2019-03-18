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

    test.setIsNewKey(true);
    cr_assert_eq(test.getIsNewKey(), true);
}

Test(tests_NCURSES, test_getIsNewKeyIsFalse)
{
    class_ncurses test;

    test.setIsNewKey(false);
    cr_assert_eq(test.getIsNewKey(), false);
}

Test(tests_NCURSES, test_getIsNewMapIsTrue)
{
    class_ncurses test;

    test.setIsNewMap(true);
    cr_assert_eq(test.getIsNewMap(), true);
}

Test(tests_NCURSES, test_getIsNewMapIsFalse)
{
    class_ncurses test;

    test.setIsNewMap(false);
    cr_assert_eq(test.getIsNewMap(), false);
}
Test(tests_NCURSES, test_getLastKeyIsTrue)
{
    class_ncurses test;

    test.setLastKey(true);
    cr_assert_eq(test.getLastKey(), true);
}

Test(tests_NCURSES, test_getLastKeyIsFalse)
{
    class_ncurses test;

    test.setLastKey(false);
    cr_assert_eq(test.getLastKey(), false);
}