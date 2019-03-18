/*
** EPITECH PROJECT, 2019
** tests_sdl.cpp
** File description:
** tests_sdl
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "class_sdl.hpp"

Test(tests_SDL, test_getIsNewKeyIsTrue)
{
    class_sdl test;

    test.setIsNewKey(true);
    cr_assert_eq(test.getIsNewKey(), true);
}

Test(tests_SDL, test_getIsNewKeyIsFalse)
{
    class_sdl test;

    test.setIsNewKey(false);
    cr_assert_eq(test.getIsNewKey(), false);
}

Test(tests_SDL, test_getIsNewMapIsTrue)
{
    class_sdl test;

    test.setIsNewMap(true);
    cr_assert_eq(test.getIsNewMap(), true);
}

Test(tests_SDL, test_getIsNewMapIsFalse)
{
    class_sdl test;

    test.setIsNewMap(false);
    cr_assert_eq(test.getIsNewMap(), false);
}
Test(tests_SDL, test_getLastKeyIsTrue)
{
    class_sdl test;

    test.setLastKey(true);
    cr_assert_eq(test.getLastKey(), true);
}

Test(tests_SDL, test_getLastKeyIsFalse)
{
    class_sdl test;

    test.setLastKey(false);
    cr_assert_eq(test.getLastKey(), false);
}