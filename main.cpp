#include <QApplication>

#include "data.h"
#include "window.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    data::Data data = data::load("data/numbers.csv");

    Window window(std::move(data));
    window.show();

    return app.exec();
}
