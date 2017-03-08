#include "test.h"
#include "../src/vec2.h"

using namespace jogurt;

NUMERIC_TEST_CASE("2D vector addition", "[vec2]")
{
    vec2<T> v0 = {  1, 10 };
    vec2<T> v1 = { 20,  2 };
    vec2<T> v2 = {  4, 40 };

    SECTION("Zero is the neutral element")
    {
        REQUIRE(v0 + zero2<T>() == v0);
        REQUIRE(v1 + zero2<T>() == v1);
        REQUIRE(v0 - zero2<T>() == v0);
        REQUIRE(v1 - zero2<T>() == v1);
    }

    SECTION("Is comutative")
    {
        REQUIRE(v0 + v1 == v1 + v0);
        REQUIRE(v0 - v1 == -(v1 - v0));
    }

    SECTION("Is associative")
    {
        REQUIRE((v0 + v1) + v2 == v0 + (v1 + v2));
    }

    SECTION("Subtracting is adding the opposite")
    {
        REQUIRE(v0 - v1 == v0 + (-v1));
        REQUIRE(v1 - v0 == v1 + (-v0));
    }

    SECTION("Addition is distributive over multiplication")
    {
        REQUIRE(2 * (v0 + v1) == 2 * v0 + 2 * v1);
        REQUIRE(3 * (v1 - v2) == 3 * v1 - 3 * v2);
    }
}
