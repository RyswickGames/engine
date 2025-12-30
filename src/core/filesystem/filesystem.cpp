#include "filesystem.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>

namespace rfs {
std::string GetFileContentsAsStr(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) throw std::invalid_argument("invalid file " + filename);
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}
} // end rfs
