#include "catch2/catch.hpp"

#include "Image.h"
#include <iostream>
#include <fstream>
#include <string>

TEST_CASE("Image supports basic operations", "[Image]")
{
    const auto img1 = Image(5, 2);
    const auto img2 = Image(2, 5);

    SECTION("GetHeight, GetWidth works")
    {
        REQUIRE(img1.GetHeight() == 5);
        REQUIRE(img1.GetWidth() == 2);
    }

    SECTION("basic + operations works")
    {
        REQUIRE((img1 + img1).GetHeight() == 5);
        REQUIRE((img1 + img1).GetWidth() == 4);
    }

    SECTION("copy operations work")
    {
        auto img3 = img1;
        REQUIRE(img3 == img1);
    }
}

TEST_CASE("Empty Image", "[Image]")
{
    const auto img1 = Image();
    const auto img2 = Image(2, 5);

    REQUIRE(img1.GetHeight() == 0);
    REQUIRE(img1.GetWidth() == 0);

    SECTION("operations on empty Image")
    {
        SECTION("adding empty Image")
        {
            REQUIRE((img1 + img2).GetWidth() == 5);
        }

        //.....
    }

}

TEST_CASE("right-left Images", "[Image]")
{
    auto left = Image(3, 4);
    left(2, 2) = Pixel(176);
    auto right = Image(4, 3);
    right(2, 2) = Pixel(219);

    SECTION("+ operation work")
    {
        REQUIRE((right + left) != (left + right));
    }
    SECTION("| operation work")
    {
        REQUIRE((right | left) == (left | right));
    }
    SECTION("& operation work")
    {
        REQUIRE((right & left) == (left & right));
    }
    SECTION("more | operations")
    {
        auto result = right | left;
        REQUIRE(result.GetHeight() == 4);
        REQUIRE(result.GetWidth() == 4);
    }
    SECTION("more & operations")
    {
        auto result = right & left;
        REQUIRE(result.GetHeight() == 3);
        REQUIRE(result.GetWidth() == 3);
    }
}