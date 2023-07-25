#pragma once

#include <string>
#include <vector>

/// \brief Read an input file.
///
/// \return Vector of strings representing each rucksack
std::vector<std::string> read_input(
        const std::string& filename ///< The filename to read
);

/// \brief Find items contained in both compartments of a given rucksack.
///
/// \return Sum of priorities of all found items
int part1(
        const std::vector<std::string>& rucksacks ///< All rucksacks
);

/// \brief Find badge used by each group of 3 elves.
///
/// \return Sum of priorities of all badges
int part2(
        const std::vector<std::string>& rucksacks ///< All rucksacks
);
