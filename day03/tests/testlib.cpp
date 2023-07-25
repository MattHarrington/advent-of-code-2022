#include <catch.hpp>

#include "libaoc.hpp"

const auto sample_input{ read_input("sample_input.txt") };
const auto puzzle_input{ read_input("puzzle_input.txt") };

TEST_CASE("Sample input should contain 6 rucksacks")
{
	CHECK(sample_input.size() == 6);
}

TEST_CASE("Puzzle input should contain 300 rucksacks")
{
	CHECK(puzzle_input.size() == 300);
}

TEST_CASE("Part 1 answer with sample input should be 157")
{
	const auto part1_answer{ part1(sample_input) };
	CHECK(part1_answer == 157);
}

TEST_CASE("Part 1 answer with puzzle input should be 8053")
{
	const auto part1_answer{ part1(puzzle_input) };
	CHECK(part1_answer == 8053);
}

TEST_CASE("Part 2 answer with sample input should be 70")
{
	const auto part2_answer{ part2(sample_input) };
	CHECK(part2_answer == 70);
}

TEST_CASE("Part 2 answer with puzzle input should be 2425")
{
	const auto part2_answer{ part2(puzzle_input) };
	CHECK(part2_answer == 2425);
}
