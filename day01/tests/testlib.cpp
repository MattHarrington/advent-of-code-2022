#include <catch.hpp>

#include "libaoc.hpp"

const auto sample_input{ read_input("sample_input.txt") };
const auto puzzle_input{ read_input("puzzle_input.txt") };

TEST_CASE("Sample input should contain values for 5 elves")
{
	CHECK(sample_input.size() == 5);
}

TEST_CASE("Puzzle input should contain values for 251 elves")
{
	CHECK(puzzle_input.size() == 251);
}

TEST_CASE("Part 1 answer with sample input should be 24'000")
{
	const auto part1_answer{ part1(sample_input) };
	CHECK(part1_answer == 24'000);
}

TEST_CASE("Part 1 answer with puzzle input should be 72'511")
{
	const auto part1_answer{ part1(puzzle_input) };
	CHECK(part1_answer == 72'511);
}

TEST_CASE("Part 2 answer with sample input should be 45'000")
{
	const auto part2_answer{ part2(sample_input) };
	CHECK(part2_answer == 45'000);
}

TEST_CASE("Part 2 answer with puzzle input should be 212'117")
{
	const auto part2_answer{ part2(puzzle_input) };
	CHECK(part2_answer == 212'117);
}
