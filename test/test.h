#ifndef JOGURT_MATH_TEST_H
#define JOGURT_MATH_TEST_H

#include "catch/single_include/catch.hpp"

#define NUMERIC_TEST_CASE2(name, tags, runner_name) \
    template <class T> void runner_name(); \
    TEST_CASE(name, tags) \
    { \
        SECTION( "With float as scalar type") { runner_name<float>(); } \
        SECTION("With double as scalar type") { runner_name<double>(); } \
    } \
    template <class T> void runner_name()

#define NUMERIC_TEST_CASE(name, tags) \
    NUMERIC_TEST_CASE2(name, tags, INTERNAL_CATCH_UNIQUE_NAME(____N_U_M_E_R_I_C____T_E_S_T____))

#endif // JOGURT_MATH_TEST_H
