#include <algorithm>
#include <fstream>
#include <stdexcept>

#include "libaoc.hpp"

std::string read_input(const std::string& filename)
{
    std::fstream in{ filename };
    if (!in)
    {
        throw std::runtime_error("File not found");
    }

    std::string line;
    getline(in, line);

    return line;
}

int part1(const std::string& datastream)
{
    size_t pos{ 0 };

    for (size_t i{ 0 }; i < datastream.size(); ++i)
    {
        // Brute force search for duplicates
        if (datastream.at(i + 0) != datastream.at(i + 1)
            && datastream.at(i + 0) != datastream.at(i + 2)
            && datastream.at(i + 0) != datastream.at(i + 3)
            && datastream.at(i + 0) != datastream.at(i + 4)
            && datastream.at(i + 1) != datastream.at(i + 2)
            && datastream.at(i + 1) != datastream.at(i + 3)
            && datastream.at(i + 1) != datastream.at(i + 4)
            && datastream.at(i + 2) != datastream.at(i + 3)
            && datastream.at(i + 2) != datastream.at(i + 4)
            && datastream.at(i + 3) != datastream.at(i + 4))
        {
            // Found start-of-packet
            pos = i + 4;
            break;
        }
    }
    return static_cast<int>(pos);
}

int part2(const std::string& datastream)
{
    size_t pos{ 0 };

    for (size_t i{ 0 }; i < datastream.size(); ++i)
    {
        auto possible_som{ datastream.substr(i, 14) }; // Possible start-of-message packet
        std::sort(std::begin(possible_som), std::end(possible_som)); // Need to sort before std::unique
        auto res{ std::unique(std::begin(possible_som), std::end(possible_som)) };
        if (res == std::end(possible_som))
        {
            // No characters removed, so string has unique characters.
            // This means start-of-message packet found.
            pos = i + 14;
            break;
        }
    }

    return static_cast<int>(pos);
}
