#ifndef DATA_H
#define DATA_H

#include <vector>
#include <filesystem>

namespace data {

using Data = std::vector<double>;

Data load(std::experimental::filesystem::path input_path);
double sum(const Data& data, int start, int end);

}

#endif // DATA_H
