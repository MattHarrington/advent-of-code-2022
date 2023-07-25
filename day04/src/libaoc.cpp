#include <fstream>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "libaoc.hpp"

std::vector<std::string> read_input(const std::string& filename)
{
    std::fstream in{ filename };
    if (!in) throw std::runtime_error("File not found");

    std::vector<std::string> rucksacks;

    std::string line;

    while (getline(in, line))
    {
        rucksacks.push_back(line);
    }

    return rucksacks;
}

int part1(const std::vector<std::string>& rucksacks)
{
    int sum_of_priorities{ 0 };

    for (const auto& rucksack: rucksacks)
    {
        // Bisect string to get each compartment
        auto first_compartment{ rucksack.substr(0, rucksack.size() / 2) };
        auto second_compartment{ rucksack.substr(rucksack.size() / 2) };

        // Look for unique item in each compartment
        std::unordered_map<char, int> counts;
        for (const auto& item: first_compartment)
        {
            counts[item] += 1;
        }
        for (const auto& item: second_compartment)
        {
            if (counts[item] != 0)
            {
                // Found duplicate
                if (item >= 65 && item <= 90) // ASCII values for uppercase
                {
                    int priority{ item - 64 + 26 }; // Per problem statement, A-Z priorities are 27-52
                    sum_of_priorities += priority;
                }
                else if (item >= 97 && item <= 122) // ASCII values for lowercase
                {
                    int priority{ item - 96 }; // Per problem statement, a-z priorities are 1-26
                    sum_of_priorities += priority;
                }
                break;
            }
        }
    }

    return sum_of_priorities;
}

int part2(const std::vector<std::string>& rucksacks)
{
    int sum_of_priorities{ 0 };

    for (auto it{ std::begin(rucksacks) }; it < std::end(rucksacks); it += 3)
    {
        auto rucksack1{ *it };
        auto rucksack2{ *(it + 1) };
        auto rucksack3{ *(it + 2) };

        std::unordered_map<char, int> counts;
        for (const auto& item: rucksack1)
        {
            if (counts[item] == 0) // Only count each item once
            {
                counts[item] += 1;
            }
        }
        for (const auto& item: rucksack2)
        {
            if (counts[item] == 1) // Item was also in rucksack1
            {
                counts[item] += 1;
            }
        }
        for (const auto& item: rucksack3)
        {
            if (counts[item] == 2) // Item was also in rucksack1 and rucksack2
            {
                if (item >= 65 && item <= 90) // ASCII values for uppercase
                {
                    int priority{ item - 64 + 26 }; // Per problem statement, A-Z priorities are 27-52
                    sum_of_priorities += priority;
                }
                else if (item >= 97 && item <= 122) // ASCII values for lowercase
                {
                    int priority{ item - 96 }; // Per problem statement, a-z priorities are 1-26
                    sum_of_priorities += priority;
                }
                break;
            }
        }
    }

    return sum_of_priorities;
}
