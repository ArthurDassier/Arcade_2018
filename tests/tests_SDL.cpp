/*
** EPITECH PROJECT, 2019
** tests_sdl.cpp
** File description:
** tests_sdl
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ClassSDL.hpp"

Test(tests_SDL, test_getIsNewKeyIsTrue)
{
    ClassSDL test;

    test.setIsNewKey(true);
    cr_assert_eq(test.getIsNewKey(), true);
}

Test(tests_SDL, test_getIsNewKeyIsFalse)
{
    ClassSDL test;

    test.setIsNewKey(false);
    cr_assert_eq(test.getIsNewKey(), false);
}

Test(tests_SDL, test_getIsNewMapIsTrue)
{
    ClassSDL test;

    test.setIsNewMap(true);
    cr_assert_eq(test.getIsNewMap(), true);
}

Test(tests_SDL, test_getIsNewMapIsFalse)
{
    ClassSDL test;

    test.setIsNewMap(false);
    cr_assert_eq(test.getIsNewMap(), false);
}
Test(tests_SDL, test_getLastKeyIsTrue)
{
    ClassSDL test;

    test.setLastKey(true);
    cr_assert_eq(test.getLastKey(), true);
}

Test(tests_SDL, test_getLastKeyIsFalse)
{
    ClassSDL test;

    test.setLastKey(false);
    cr_assert_eq(test.getLastKey(), false);
}