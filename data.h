#ifndef DATA_H
#define DATA_H

#include <vector>
#include <filesystem>

namespace data {

using Data = std::vector<double>;
// Once c++17 is supported outside the experimental namespace this can
// be swapped for using FilePath = std::filesystem::path;
using FilePath = std::experimental::filesystem::path;

Data load(FilePath input_path);
double sum(const Data& data, int start, int end);

}

#endif // DATA_H
