#include <catch.hpp>

#include "libaoc.hpp"

const auto sample_input{ read_input("sample_input.txt") };
const auto puzzle_input{ read_input("puzzle_input.txt") };

TEST_CASE("Sample input should contain 30 characters")
{
    CHECK(sample_input.size() == 30);
}

TEST_CASE("Puzzle input should contain 4095 stacks")
{
    CHECK(puzzle_input.size() == 4095);
}

TEST_CASE("Part 1 answer with sample input should be 7")
{
    const auto part1_answer{ part1(sample_input) };
    CHECK(part1_answer == 7);
}

TEST_CASE("Part 1 answer with puzzle input should be 1582")
{
    const auto part1_answer{ part1(puzzle_input) };
    CHECK(part1_answer == 1582);
}

TEST_CASE("Part 2 answer with sample input should be 19")
{
    const auto part2_answer{ part2(sample_input) };
    CHECK(part2_answer == 19);
}

TEST_CASE("Part 2 answer with puzzle input should be 3588")
{
    const auto part2_answer{ part2(puzzle_input) };
    CHECK(part2_answer == 3588);
}
