/*
** EPITECH PROJECT, 2019
** tests_sfml.cpp
** File description:
** tests_sfml
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ClassSFML.hpp"

Test(tests_SFML, test_getIsNewKeyIsTrue)
{
    ClassSFML test;

    test.setIsNewKey(true);
    cr_assert_eq(test.getIsNewKey(), true);
}

Test(tests_SFML, test_getIsNewKeyIsFalse)
{
    ClassSFML test;

    test.setIsNewKey(false);
    cr_assert_eq(test.getIsNewKey(), false);
}

Test(tests_SFML, test_getIsNewMapIsTrue)
{
    ClassSFML test;

    test.setIsNewMap(true);
    cr_assert_eq(test.getIsNewMap(), true);
}

Test(tests_SFML, test_getIsNewMapIsFalse)
{
    ClassSFML test;

    test.setIsNewMap(false);
    cr_assert_eq(test.getIsNewMap(), false);
}
Test(tests_SFML, test_getLastKeyIsTrue)
{
    ClassSFML test;

    test.setLastKey(true);
    cr_assert_eq(test.getLastKey(), true);
}

Test(tests_SFML, test_getLastKeyIsFalse)
{
    ClassSFML test;

    test.setLastKey(false);
    cr_assert_eq(test.getLastKey(), false);
}

Test(tests_SFML, test_getScore)
{
    ClassSFML test;

    test.setScore(0);
    cr_assert_eq(test.getScore(), 0);
    test.setScore(10);
    cr_assert_eq(test.getScore(), 10);
    test.setScore(900);
    cr_assert_eq(test.getScore(), 900);
}

Test(tests_SFML, test_getPathConfig)
{
    ClassSFML test;

    test.setPathConfig("");
    cr_assert_eq(test.getPathConfig(), "");
    test.setPathConfig("coucou");
    cr_assert_eq(test.getPathConfig(), "coucou");
    test.setPathConfig("./srcs/core/path_menu.config");
    cr_assert_eq(test.getPathConfig(), "./srcs/core/path_menu.config");
}

Test(tests_SFML, test_getIsNewPathConfigIsTrue)
{
    ClassSFML test;

    test.setIsNewPathConfig(true);
    cr_assert_eq(test.getIsNewPathConfig(), true);
}

Test(tests_SFML, test_getIsNewPathConfigIsFalse)
{
    ClassSFML test;

    test.setIsNewPathConfig(false);
    cr_assert_eq(test.getIsNewPathConfig(), false);
}