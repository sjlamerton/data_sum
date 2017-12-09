#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QSlider;
class QLineEdit;

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

    QSlider *min_slider, *max_slider;
    QLineEdit *result_text;

signals:

public slots:
};

#endif // WINDOW_H
