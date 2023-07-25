#include <algorithm>
#include <fstream>
#include <functional>
#include <numeric>
#include <stdexcept>

#include "libaoc.hpp"

std::vector<std::vector<int>> read_input(const std::string& filename)
{
	std::fstream in{ filename };
	if (!in) throw std::runtime_error("File not found");

	std::vector<std::vector<int>> inventory;
	std::vector<int> elf_calories;
	std::string line;

	while (getline(in, line))
	{
		if (line.empty())
		{
			inventory.push_back(elf_calories);
			elf_calories.clear();
		}
		else
		{
			elf_calories.push_back(std::stoi(line));
		}
	}
	inventory.push_back(elf_calories); // Handles the last elf in the input

	return inventory;
}

int part1(const std::vector<std::vector<int>>& inventory)
{
	std::vector<int> calorie_sums;
	for (const auto& elf: inventory)
	{
		auto calorie_sum{ std::accumulate(std::begin(elf), std::end(elf), 0) };
		calorie_sums.push_back(calorie_sum);
	}
	return *std::max_element(std::begin(calorie_sums), std::end(calorie_sums));
}

int part2(const std::vector<std::vector<int>>& inventory)
{
	std::vector<int> calorie_sums;
	for (const auto& elf: inventory)
	{
		auto calorie_sum{ std::accumulate(std::begin(elf), std::end(elf), 0) };
		calorie_sums.push_back(calorie_sum);
	}
	std::sort(std::begin(calorie_sums), std::end(calorie_sums), std::greater<>());
	auto top_three{ std::accumulate(std::begin(calorie_sums), std::begin(calorie_sums) + 3, 0) };

	return top_three;
}
