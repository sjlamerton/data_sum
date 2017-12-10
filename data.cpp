#include <fstream>
#include <numeric>
#include <QtGlobal>
// #include <QThread>

#include "data.h"

namespace data {

Data load(FilePath input_path)
{
    Data data;

    std::ifstream file(input_path);

    if (!file.is_open()) {
        qCritical("Could not open input file");
        std::exit(1);
    }

    Data::value_type val;

    while (file >> val) {
        data.push_back(val);
    }

    return data;
}

double sum(const Data& data, int start, int end) {
    // QThread::msleep(500);
    // We could use std::reduce with the parallel execution policy if neccessary
    // in c++17
    return std::accumulate(data.begin() + start, data.begin() + end, 0.0);
}

}
