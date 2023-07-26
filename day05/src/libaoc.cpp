#include <fstream>
#include <regex>
#include <sstream>
#include <stdexcept>

#include "libaoc.hpp"

std::vector<std::stack<char>> get_starting_stacks(InputMode mode)
{
    std::vector<std::stack<char>> stacks;

    if (mode == InputMode::Sample)
    {
        /* Starting configuration of stacks
                [D]
            [N] [C]
            [Z] [M] [P]
             1   2   3
         */
        const std::stack<char> stack1({ 'Z', 'N' });
        const std::stack<char> stack2({ 'M', 'C', 'D' });
        const std::stack<char> stack3({ 'P' });
        stacks = { stack1, stack2, stack3 };
    }
    else if (mode == InputMode::Puzzle)
    {
        /* Starting configuration of stacks
            [P]     [C]         [M]
            [D]     [P] [B]     [V] [S]
            [Q] [V] [R] [V]     [G] [B]
            [R] [W] [G] [J]     [T] [M]     [V]
            [V] [Q] [Q] [F] [C] [N] [V]     [W]
            [B] [Z] [Z] [H] [L] [P] [L] [J] [N]
            [H] [D] [L] [D] [W] [R] [R] [P] [C]
            [F] [L] [H] [R] [Z] [J] [J] [D] [D]
             1   2   3   4   5   6   7   8   9
         */
        const std::stack<char> stack1({ 'F', 'H', 'B', 'V', 'R', 'Q', 'D', 'P' });
        const std::stack<char> stack2({ 'L', 'D', 'Z', 'Q', 'W', 'V' });
        const std::stack<char> stack3({ 'H', 'L', 'Z', 'Q', 'G', 'R', 'P', 'C' });
        const std::stack<char> stack4({ 'R', 'D', 'H', 'F', 'J', 'V', 'B' });
        const std::stack<char> stack5({ 'Z', 'W', 'L', 'C' });
        const std::stack<char> stack6({ 'J', 'R', 'P', 'N', 'T', 'G', 'V', 'M' });
        const std::stack<char> stack7({ 'J', 'R', 'L', 'V', 'M', 'B', 'S' });
        const std::stack<char> stack8({ 'D', 'P', 'J' });
        const std::stack<char> stack9({ 'D', 'C', 'N', 'W', 'V' });
        stacks = { stack1, stack2, stack3, stack4, stack5, stack6, stack7, stack8, stack9 };
    }
    return stacks;
}

std::vector<Move> read_input(const std::string& filename)
{
    std::fstream in{ filename };
    if (!in)
    {
        throw std::runtime_error("File not found");
    }

    std::vector<Move> moves;
    const std::regex r1{ R"(move ([\d]+) from ([\d]+) to ([\d]+))" };
    std::string line;

    while (getline(in, line))
    {
        std::smatch sm;
        if (std::regex_match(line, sm, r1))
        {
            // Found a match
            const Move move{ std::stoi(sm[1]), std::stoi(sm[2]), std::stoi(sm[3]) };
            moves.emplace_back(move);
        }
    }

    return moves;
}

std::string part1(const std::vector<Move>& moves)
{
    std::vector<std::stack<char>> stacks;
    if (moves.size() == 4)
    {
        stacks = get_starting_stacks(InputMode::Sample);
    }
    else if (moves.size() == 501)
    {
        stacks = get_starting_stacks(InputMode::Puzzle);
    }

    for (const auto& move: moves)
    {
        for (auto i{ 0 }; i < move.quantity; ++i)
        {
            // stacks vector is 0-based and moves are 1-based
            auto crate{ stacks.at(move.from_location - 1).top() };
            stacks.at(move.from_location - 1).pop();
            stacks.at(move.to_location - 1).push(crate);
        }
    }

    // Find the top crate on each stack
    std::stringstream ss;
    for (const auto& stack: stacks)
    {
        ss << stack.top();
    }

    return ss.str();
}

std::string part2(const std::vector<Move>& moves)
{
    std::vector<std::stack<char>> stacks;
    if (moves.size() == 4)
    {
        stacks = get_starting_stacks(InputMode::Sample);
    }
    else if (moves.size() == 501)
    {
        stacks = get_starting_stacks(InputMode::Puzzle);
    }

    for (const auto& move: moves)
    {
        std::stack<char> crates_to_move;
        for (auto i{ 0 }; i < move.quantity; ++i)
        {
            // stacks vector is 0-based and moves are 1-based
            auto crate{ stacks.at(move.from_location - 1).top() };
            stacks.at(move.from_location - 1).pop();
            crates_to_move.push(crate);
        }
        while (!crates_to_move.empty())
        {
            stacks.at(move.to_location - 1).push(crates_to_move.top());
            crates_to_move.pop();
        }
    }

    // Find the top crate on each stack
    std::stringstream ss;
    for (const auto& stack: stacks)
    {
        ss << stack.top();
    }

    return ss.str();
}
