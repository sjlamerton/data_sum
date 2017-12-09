#ifndef WINDOW_H
#define WINDOW_H

#include "data.h"

#include <QWidget>

class QSlider;
class QLineEdit;

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(Data data, QWidget *parent = nullptr);

private:
    QSlider *min_slider, *max_slider;
    QLineEdit *result_text;
    Data input_data;

signals:

public slots:
};

#endif // WINDOW_H
