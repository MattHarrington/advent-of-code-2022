#include <catch.hpp>

#include "libaoc.hpp"

const auto sample_input{ read_input("sample_input.txt") };
const auto puzzle_input{ read_input("puzzle_input.txt") };

TEST_CASE("Sample input should contain 3 turns")
{
	CHECK(sample_input.size() == 3);
}

TEST_CASE("Puzzle input should contain 2500 turns")
{
	CHECK(puzzle_input.size() == 2500);
}

TEST_CASE("Part 1 answer with sample input should be 15")
{
	const auto part1_answer{ part1(sample_input) };
	CHECK(part1_answer == 15);
}

TEST_CASE("Part 1 answer with puzzle input should be 8933")
{
	const auto part1_answer{ part1(puzzle_input) };
	CHECK(part1_answer == 8933);
}

TEST_CASE("Part 2 answer with sample input should be 12")
{
	const auto part2_answer{ part2(sample_input) };
	CHECK(part2_answer == 12);
}

TEST_CASE("Part 2 answer with puzzle input should be 11'998")
{
	const auto part2_answer{ part2(puzzle_input) };
	CHECK(part2_answer == 11'998);
}
