#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>

#include "libaoc.hpp"

std::vector<Round> read_input(const std::string& filename)
{
	std::fstream in{ filename };
	if (!in) throw std::runtime_error("File not found");

	std::vector<Round> game;
	std::string line;

	while (getline(in, line))
	{
		Round round{};

		// Split the line and parse
		std::stringstream ss{ line };
		std::string choice;
		while (getline(ss, choice, ' '))
		{
			if (choice == "A")
			{
				round.opponent_choice = Choice::Rock;
			}
			else if (choice == "B")
			{
				round.opponent_choice = Choice::Paper;

			}
			else if (choice == "C")
			{
				round.opponent_choice = Choice::Scissors;
			}
			else if (choice == "X")
			{
				round.my_choice = Choice::X;
			}
			else if (choice == "Y")
			{
				round.my_choice = Choice::Y;
			}
			else if (choice == "Z")
			{
				round.my_choice = Choice::Z;
			}
		}

		game.push_back(round);
	}

	return game;
}

std::tuple<int, int> score_round_part1(const Round& round)
{
	int opponent_score{ 0 };
	int my_score{ 0 };
	if (round.opponent_choice == Choice::Rock && round.my_choice == Choice::X)
	{
		opponent_score += 1; // Rock
		my_score += 1; // Rock
		opponent_score += 3; // Draw
		my_score += 3; // Draw
	}
	else if (round.opponent_choice == Choice::Rock && round.my_choice == Choice::Y)
	{
		opponent_score += 1; // Rock
		my_score += 2; // Paper
		opponent_score += 0; // Opponent lost
		my_score += 6; // I won
	}
	else if (round.opponent_choice == Choice::Rock && round.my_choice == Choice::Z)
	{
		opponent_score += 1; // Rock
		my_score += 3; // Scissors
		opponent_score += 6; // Opponent won
		my_score += 0; // I lost
	}
	else if (round.opponent_choice == Choice::Paper && round.my_choice == Choice::X)
	{
		opponent_score += 2; // Paper
		my_score += 1; // Rock
		opponent_score += 6; // Opponent won
		my_score += 0; // I lost
	}
	else if (round.opponent_choice == Choice::Paper && round.my_choice == Choice::Y)
	{
		opponent_score += 2; // Paper
		my_score += 2; // Paper
		opponent_score += 3; // Draw
		my_score += 3; // Draw
	}
	else if (round.opponent_choice == Choice::Paper && round.my_choice == Choice::Z)
	{
		opponent_score += 2; // Paper
		my_score += 3; // Scissors
		opponent_score += 0; // Opponent lost
		my_score += 6; // I won
	}
	else if (round.opponent_choice == Choice::Scissors && round.my_choice == Choice::X)
	{
		opponent_score += 3; // Scissors
		my_score += 1; // Rock
		opponent_score += 0; // Opponent lost
		my_score += 6; // I won
	}
	else if (round.opponent_choice == Choice::Scissors && round.my_choice == Choice::Y)
	{
		opponent_score += 3; // Scissors
		my_score += 2; // Paper
		opponent_score += 6; // Opponent won
		my_score += 0; // I lost
	}
	else if (round.opponent_choice == Choice::Scissors && round.my_choice == Choice::Z)
	{
		opponent_score += 3; // Scissors
		my_score += 3; // Scissors
		opponent_score += 3; // Draw
		my_score += 3; // Draw
	}

	return std::make_tuple(opponent_score, my_score);
}

std::tuple<int, int> score_round_part2(const Round& round)
{
	int opponent_score{ 0 };
	int my_score{ 0 };
	if (round.opponent_choice == Choice::Rock && round.my_choice == Choice::X)
	{
		// I need to lose
		opponent_score += 1; // Rock
		my_score += 3; // Scissors
		opponent_score += 6; // Win
		my_score += 0; // Lose
	}
	else if (round.opponent_choice == Choice::Rock && round.my_choice == Choice::Y)
	{
		// I need to draw
		opponent_score += 1; // Rock
		my_score += 1; // Rock
		opponent_score += 3; // Draw
		my_score += 3; // Draw
	}
	else if (round.opponent_choice == Choice::Rock && round.my_choice == Choice::Z)
	{
		// I need to win
		opponent_score += 1; // Rock
		my_score += 2; // Paper
		opponent_score += 0; // Opponent lost
		my_score += 6; // I won
	}
	else if (round.opponent_choice == Choice::Paper && round.my_choice == Choice::X)
	{
		// I need to lose
		opponent_score += 2; // Paper
		my_score += 1; // Rock
		opponent_score += 6; // Opponent won
		my_score += 0; // I lost
	}
	else if (round.opponent_choice == Choice::Paper && round.my_choice == Choice::Y)
	{
		// I need to draw
		opponent_score += 2; // Paper
		my_score += 2; // Paper
		opponent_score += 3; // Draw
		my_score += 3; // Draw
	}
	else if (round.opponent_choice == Choice::Paper && round.my_choice == Choice::Z)
	{
		// I need to win
		opponent_score += 2; // Paper
		my_score += 3; // Scissors
		opponent_score += 0; // Opponent lost
		my_score += 6; // I won
	}
	else if (round.opponent_choice == Choice::Scissors && round.my_choice == Choice::X)
	{
		// I need to lose
		opponent_score += 3; // Scissors
		my_score += 2; // Paper
		opponent_score += 6; // Opponent won
		my_score += 0; // I lost
	}
	else if (round.opponent_choice == Choice::Scissors && round.my_choice == Choice::Y)
	{
		// I need to draw
		opponent_score += 3; // Scissors
		my_score += 3; // Scissors
		opponent_score += 3; // Draw
		my_score += 3; // Draw
	}
	else if (round.opponent_choice == Choice::Scissors && round.my_choice == Choice::Z)
	{
		// I need to win
		opponent_score += 3; // Scissors
		my_score += 1; // Rock
		opponent_score += 0; // Opponent lost
		my_score += 6; // I won
	}

	return std::make_tuple(opponent_score, my_score);
}

int part1(const std::vector<Round>& game)
{
	int my_total_score{ 0 };

	for (const Round& round: game)
	{
		auto [_, my_score_this_round] = score_round_part1(round);
		my_total_score += my_score_this_round;
	}
	return my_total_score;
}

int part2(const std::vector<Round>& game)
{
	int my_total_score{ 0 };

	for (const Round& round: game)
	{
		auto [_, my_score_this_round] = score_round_part2(round);
		my_total_score += my_score_this_round;
	}
	return my_total_score;
}
