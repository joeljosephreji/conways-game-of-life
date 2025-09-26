#include "fileHandlingUtils.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<std::string>
FileHandlingUtils::getFileLines(const std::string &filename) {
    std::ifstream infile(filename);
    std::vector<std::string> lines;
    std::string line;

    if (!infile) {
        throw std::runtime_error("Error opening the file");
    }

    while (std::getline(infile, line)) {
        lines.push_back(line);
    }
    return lines;
}
