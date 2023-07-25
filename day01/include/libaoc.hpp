#pragma once

#include <string>
#include <vector>

/// \brief Read an input file.
///
/// \return Vector of a vector of carried calories for each elf.
std::vector<std::vector<int>> read_input(
		const std::string& filename ///< The filename to read
);

/// \brief Finds the total calories of the elf carrying the most calories.
///
/// \return Total calories
int part1(
		const std::vector<std::vector<int>>& inventory ///< All calories carried by all elves
);

/// \brief Finds the total calories of the top three elves carrying the most calories.
///
/// \return Total calories of the top three elves
int part2(
		const std::vector<std::vector<int>>& inventory ///< All calories carried by all elves
);
