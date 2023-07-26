#include <catch.hpp>

#include "libaoc.hpp"

const auto sample_input{ read_input("sample_input.txt") };
const auto puzzle_input{ read_input("puzzle_input.txt") };

TEST_CASE("Sample input should contain 6 assignments")
{
    CHECK(sample_input.size() == 6);
}

TEST_CASE("Puzzle input should contain 1000 assignments")
{
    CHECK(puzzle_input.size() == 1000);
}

TEST_CASE("Part 1 answer with sample input should be 2")
{
    const auto part1_answer{ part1(sample_input) };
    CHECK(part1_answer == 2);
}

TEST_CASE("Part 1 answer with puzzle input should be 459")
{
    const auto part1_answer{ part1(puzzle_input) };
    CHECK(part1_answer == 459);
}

TEST_CASE("Part 2 answer with sample input should be 4")
{
    const auto part2_answer{ part2(sample_input) };
    CHECK(part2_answer == 4);
}

TEST_CASE("Part 2 answer with puzzle input should be 779")
{
    const auto part2_answer{ part2(puzzle_input) };
    CHECK(part2_answer == 779);
}
