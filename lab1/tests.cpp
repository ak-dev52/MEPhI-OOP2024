#define CATCH_CONFIG_MAIN
#include "catch2/catch_test_macros.hpp"
#include "lib.h"

TEST_CASE("in_check") {
    SECTION("true") {
        REQUIRE(in_check("Sam", "SAM"));
        REQUIRE(in_check("Sam", "sam"));
        REQUIRE(in_check("Sam", "SaM"));
        REQUIRE(in_check("Sam", "HAM SAM HAM"));
        REQUIRE(in_check("Sam", "ham sam ham"));
    }
    SECTION("false") {
        REQUIRE_FALSE(in_check("Sam", "THERE IS JUST HAM"));
        REQUIRE_FALSE(in_check("Sam", ""));
        REQUIRE_FALSE(in_check("Sam", "SA AM"));
        REQUIRE_FALSE(in_check("Sam", "sa am"));
        REQUIRE_FALSE(in_check("Sam", "sdnfHhkjbkbBK"));
    }
}

TEST_CASE("char* cycle") {
    SECTION("OK") {
        std::ifstream file("file.txt");
        REQUIRE_NOTHROW(cycle(file, "sam"));
        REQUIRE_NOTHROW(cycle(file, "ham"));
    }
}

TEST_CASE("std::string cycle") {
    SECTION("OK") {
        std::ifstream file("file.txt");
        REQUIRE_NOTHROW(cycle(file, std::string("sam")));
        REQUIRE_NOTHROW(cycle(file, std::string("ham")));
    }
}

TEST_CASE("file_is_ok") {
    std::string filename = "file.txt", wrong = "wrong";
    std::ifstream file(filename);
    std::ifstream wfile(wrong);
    REQUIRE_NOTHROW(file_is_OK(file, filename));
    REQUIRE_THROWS(file_is_OK(wfile, wrong));
}
