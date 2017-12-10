#include <QApplication>
#include <QCommandLineParser>

#include "data.h"
#include "window.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    QCommandLineParser parser;
    parser.addPositionalArgument("path", "Path to data file");
    parser.process(app);

    QStringList args = parser.positionalArguments();

    if (args.size() > 1) {
        qCritical("Too many command line arguments");
        return 1;
    }

    // Default to "data/numbers.csv" if a data file isn't supplied
    QString path = args.size() == 0 ? "data/numbers.csv" : args[0];
    data::Data data = data::load(path.toStdString());

    Window window(std::move(data));
    window.show();

    return app.exec();
}
