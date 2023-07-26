#include <catch.hpp>

#include "libaoc.hpp"

const auto sample_starting_stacks{ get_starting_stacks(InputMode::Sample) };
const auto puzzle_starting_stacks{ get_starting_stacks(InputMode::Puzzle) };
const auto sample_input{ read_input("sample_input.txt") };
const auto puzzle_input{ read_input("puzzle_input.txt") };

TEST_CASE("Sample starting stacks should contain 3 stacks")
{
    CHECK(sample_starting_stacks.size() == 3);
}

TEST_CASE("Puzzle starting stacks should contain 9 stacks")
{
    CHECK(puzzle_starting_stacks.size() == 9);
}

TEST_CASE("Sample starting stacks should be in correct order")
{
    CHECK(sample_starting_stacks.at(0).top() == 'N');
    CHECK(sample_starting_stacks.at(1).top() == 'D');
    CHECK(sample_starting_stacks.at(2).top() == 'P');
}

TEST_CASE("puzzle starting stacks should be in correct order")
{
    CHECK(puzzle_starting_stacks.at(0).top() == 'P');
    CHECK(puzzle_starting_stacks.at(1).top() == 'V');
    CHECK(puzzle_starting_stacks.at(2).top() == 'C');
    CHECK(puzzle_starting_stacks.at(3).top() == 'B');
    CHECK(puzzle_starting_stacks.at(4).top() == 'C');
    CHECK(puzzle_starting_stacks.at(5).top() == 'M');
    CHECK(puzzle_starting_stacks.at(6).top() == 'S');
    CHECK(puzzle_starting_stacks.at(7).top() == 'J');
    CHECK(puzzle_starting_stacks.at(8).top() == 'V');
}

TEST_CASE("Sample input should contain 4 moves")
{
    CHECK(sample_input.size() == 4);
}

TEST_CASE("Puzzle input should contain 501 moves")
{
    CHECK(puzzle_input.size() == 501);
}

TEST_CASE("Part 1 answer with sample data should be CMZ")
{
    const auto part1_answer{ part1(sample_input)};
    CHECK(part1_answer == "CMZ");
}

TEST_CASE("Part 1 answer with puzzle data should be JDTMRWCQJ")
{
    const auto part1_answer{ part1(puzzle_input)};
    CHECK(part1_answer == "JDTMRWCQJ");
}

TEST_CASE("Part 2 answer with sample data should be MCD")
{
    const auto part2_answer{ part2(sample_input)};
    CHECK(part2_answer == "MCD");
}

TEST_CASE("Part 2 answer with puzzle data should be VHJDDCWRD")
{
    const auto part2_answer{ part2(puzzle_input)};
    CHECK(part2_answer == "VHJDDCWRD");
}
