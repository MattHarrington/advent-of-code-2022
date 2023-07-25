#pragma once

#include <string>
#include <tuple>
#include <vector>

/// \brief A player's choice according to the input file.
enum class Choice
{
	Rock = 1, Paper, Scissors, X, Y, Z
};

/// \brief A round of Rock, Paper, Scissors.
struct Round
{
	Choice opponent_choice;
	Choice my_choice;
};

/// \brief Read an input file.
///
/// \return Vector of rounds in the game
std::vector<Round> read_input(
		const std::string& filename ///< The filename to read
);

/// \brief Score a round according to part 1.
///
/// \return Tuple of opponent's score and my score
std::tuple<int, int> score_round_part1(
		const Round& round ///< The round to score
);

/// \brief Score a round according to part 2.
///
/// \return Tuple of opponent's score and my score
std::tuple<int, int> score_round_part2(
		const Round& round ///< The round to score
);

/// \brief Finds my score in a game of Rock, Paper, Scissors according to part 1.
///
/// \return My score
int part1(
		const std::vector<Round>& game ///< Vector of rounds in the game
);

/// \brief Finds my score in a game of Rock, Paper, Scissors according to part 2.
///
/// \return My score
int part2(
		const std::vector<Round>& game ///< Vector of rounds in the game
);
