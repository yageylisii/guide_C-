#include "test.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test test function", "test")
{
    SECTION("Basic")
    {
        REQUIRE(test_func(2,3) == 4);
    }

    // SECTION("Special")
    // {
    //     REQUIRE(deComp("1A1a1A1a") == "AaAa");
    //     REQUIRE(deComp("2a2b2C") == "aabbCC");
    // }

    // SECTION("Large")
    // {
    //     REQUIRE(deComp("6A") == "AAAAAA");
    //     REQUIRE(deComp("10B") == "BBBBBBBBBB");
    // }
}
