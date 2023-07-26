#pragma once

#include <string>
#include <tuple>
#include <vector>

/// \brief Starting and ending points for assigned regions for a pair of elves.
struct Assignment
{
    std::tuple<int, int> first_elf;
    std::tuple<int, int> second_elf;
};

/// \brief Read an input file.
///
/// \return Vector of assignments
std::vector<Assignment> read_input(
        const std::string& filename ///< The filename to read
);

/// \brief Find assigned regions between pairs of elves which fully overlap.
///
/// \return Number of assignments which fully overlap
int part1(
        const std::vector<Assignment>& assignments ///< The assignments
);

/// \brief Find assigned regions between pairs of elves which overlap at all.
///
/// \return Number of assignments which fully or partially overlap
int part2(
        const std::vector<Assignment>& assignments ///< The assignments
);
