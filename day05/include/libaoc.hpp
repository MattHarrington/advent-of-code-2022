#pragma once

#include <stack>
#include <string>
#include <vector>

/// \brief Signals use of either sample input or puzzle input.
enum class InputMode
{
    Sample, Puzzle
};

/// \brief An instruction followed by the crane operator.
struct Move
{
    int quantity, from_location, to_location;
};

/// \brief Get the starting stack configuration.
///
/// \return A vector of stacks
std::vector<std::stack<char>> get_starting_stacks(
        InputMode mode ///< Either Sample or Puzzle
);

/// \brief Read all the moves to be performed by the crane operator.
///
/// \return A vector of moves
std::vector<Move> read_input(
        const std::string& filename ///< Filename
);

/// \brief Perform all moves on the stacks according to part 1's rules
///
/// \return String representation of the top of all stacks
std::string part1(
        const std::vector<Move>& moves ///< Vector of moves
);

/// \brief Perform all moves on the stacks according to part 2's rules
///
/// \return String representation of the top of all stacks
std::string part2(
        const std::vector<Move>& moves ///< Vector of moves
);
