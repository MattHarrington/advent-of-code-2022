#pragma once

#include <string>

/// \brief Read input file.
///
/// \return Datastream of characters
std::string read_input(
        const std::string& filename ///< Filename
);

/// \brief Search datastream for start-of-packet.
///
/// \return End position of the found packet
int part1(
        const std::string& datastream ///< Stream of input characters
);

/// \brief Search datastream for start-of-message packet.
///
/// \return End position of the found packet
int part2(
        const std::string& datastream ///< Stream of input characters
);
