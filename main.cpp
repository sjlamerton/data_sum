#include <filesystem>
#include <fstream>

#include <QApplication>

#include "data.h"
#include "window.h"

Data loadData(std::experimental::filesystem::path input_path);

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    Data data = loadData("data/numbers.csv");

    Window window(std::move(data));
    window.show();

    return app.exec();
}

Data loadData(std::experimental::filesystem::path input_path)
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
