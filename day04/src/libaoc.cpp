#include <fstream>
#include <regex>
#include <stdexcept>
#include <string>

#include "libaoc.hpp"

std::vector<Assignment> read_input(const std::string& filename)
{
    std::fstream in{ filename };
    if (!in) throw std::runtime_error("File not found");

    std::vector<Assignment> assignments;

    std::string line;

    const std::regex r1{ R"(([\d]+)-([\d]+),([\d]+)-([\d]+))" };

    while (getline(in, line))
    {
        std::smatch sm;
        std::regex_match(line, sm, r1);
        const auto first_elf_assignment{ std::make_tuple(std::stoi(sm[1]), std::stoi(sm[2])) };
        const auto second_elf_assignment{ std::make_tuple(std::stoi(sm[3]), std::stoi(sm[4])) };
        const Assignment assignment{ first_elf_assignment, second_elf_assignment };
        assignments.emplace_back(assignment);
    }

    return assignments;
}

int part1(const std::vector<Assignment>& assignments)
{
    int number_of_complete_overlaps{ 0 };

    for (const auto& assignment: assignments)
    {
        if (std::get<0>(assignment.first_elf) >= std::get<0>(assignment.second_elf)
            && std::get<1>(assignment.first_elf) <= std::get<1>(assignment.second_elf))
        {
            // First elf's assignment is within region of second elf's assignment
            ++number_of_complete_overlaps;
        }
        else if (std::get<0>(assignment.second_elf) >= std::get<0>(assignment.first_elf)
                 && std::get<1>(assignment.second_elf) <= std::get<1>(assignment.first_elf))
        {
            // Second elf's assignment is within region of first elf's assignment
            ++number_of_complete_overlaps;
        }
    }

    return number_of_complete_overlaps;
}

int part2(const std::vector<Assignment>& assignments)
{
    int number_of_overlaps{ 0 };

    for (const auto& assignment: assignments)
    {
        if (std::get<0>(assignment.first_elf) >= std::get<0>(assignment.second_elf)
            && std::get<0>(assignment.first_elf) <= std::get<1>(assignment.second_elf))
        {
            // First elf's starting region is with second elf's region
            ++number_of_overlaps;
        }
        else if (std::get<0>(assignment.second_elf) >= std::get<0>(assignment.first_elf)
                 && std::get<0>(assignment.second_elf) <= std::get<1>(assignment.first_elf))
        {
            // Second elf's starting region is within first elf's region
            ++number_of_overlaps;
        }
        else if (std::get<1>(assignment.first_elf) >= std::get<0>(assignment.second_elf)
                 && std::get<1>(assignment.first_elf) <= std::get<1>(assignment.second_elf))
        {
            // First elf's ending region is within second elf's region
            ++number_of_overlaps;
        }
        else if (std::get<1>(assignment.second_elf) >= std::get<0>(assignment.first_elf)
                 && std::get<1>(assignment.second_elf) <= std::get<1>(assignment.first_elf))
        {
            // Second elf's ending region is within first elf's region
            ++number_of_overlaps;
        }
    }

    return number_of_overlaps;
}
