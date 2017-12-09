#ifndef WINDOW_H
#define WINDOW_H

#include "data.h"

#include <QWidget>
#include <QFuture>
#include <QFutureWatcher>

class QSlider;
class QLineEdit;

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(data::Data data, QWidget *parent = nullptr);

private:
    void updateSum();

    QSlider *min_slider, *max_slider;
    QLineEdit *result_text;
    data::Data input_data;
    QFuture<double> async;
    QFutureWatcher<double> watcher;

signals:

public slots:
    void onMinUpdate(int value);
    void onMaxUpdate(int value);
    void onSumCalculated();
};

#endif // WINDOW_H
