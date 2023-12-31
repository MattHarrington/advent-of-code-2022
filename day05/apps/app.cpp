#include <cassert>
#include <fmt/core.h>

#include "libaoc.hpp"

int main()
{
    fmt::print("Advent of Code 2022 Day 5\n");

    const auto puzzle_input{ read_input("puzzle_input.txt") };

    const auto part1_answer{ part1(puzzle_input) };
    fmt::print("Part 1 answer: {}\n", part1_answer);
    assert(part1_answer == "JDTMRWCQJ");

    const auto part2_answer{ part2(puzzle_input) };
    fmt::print("Part 2 answer: {}\n", part2_answer);
    assert(part2_answer == "VHJDDCWRD");

    return 0;
}
