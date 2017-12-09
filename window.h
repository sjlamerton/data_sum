#ifndef WINDOW_H
#define WINDOW_H

#include "data.h"

#include <QWidget>
#include <QFuture>
#include <QFutureWatcher>

class QSlider;
class QLineEdit;
class QLabel;

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(data::Data data);

private:
    void updateSum();
    void setRangeLabel();

    QSlider *min_slider, *max_slider;
    QLineEdit *result_text;
    QLabel *range_label;
    data::Data input_data;
    QFuture<double> async;
    QFutureWatcher<double> watcher;

public slots:
    void onMinUpdate(int value);
    void onMaxUpdate(int value);
    void onSumCalculated();
};

#endif // WINDOW_H
