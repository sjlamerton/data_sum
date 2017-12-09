#include <QFormLayout>
#include <QSlider>
#include <QLineEdit>
#include <QLabel>
#include <QtConcurrent>

#include "window.h"

Window::Window(data::Data data, QWidget *parent) : input_data(data), QWidget(parent)
{
    min_slider = new QSlider(Qt::Horizontal);
    min_slider->setMaximum(data.size());
    max_slider = new QSlider(Qt::Horizontal);
    max_slider->setMaximum(data.size());
    result_text = new QLineEdit();
    result_text->setReadOnly(true);
    auto formLayout = new QFormLayout();
    formLayout->addRow("", new QLabel("Please select the index range to sum using the sliders below"));
    formLayout->addRow("Minimum index", min_slider);
    formLayout->addRow("Maximum index", max_slider);
    formLayout->addRow("Sum:", result_text);
    setLayout(formLayout);
    setMinimumWidth(450);

    connect(min_slider, &QSlider::valueChanged, this, &Window::onMinUpdate);
    connect(max_slider, &QSlider::valueChanged, this, &Window::onMaxUpdate);
    connect(&watcher, &QFutureWatcher<double>::finished, this, &Window::onSumCalculated);

    // calculate the total sum to start
    updateSum();
}

void Window::onMinUpdate(int value) {
    if (max_slider->value() < value) {
        max_slider->setValue(value);
    }
    updateSum();
}

void Window::onMaxUpdate(int value) {
    if (min_slider->value() > value) {
        min_slider->setValue(value);
    }
    updateSum();
}

void Window::updateSum() {
    // The previous value may not have returned so cancel it first
    watcher.cancel();
    async = QtConcurrent::run(data::sum, input_data, min_slider->value(), max_slider->value());
    watcher.setFuture(async);
}

void Window::onSumCalculated() {
    result_text->setText(QString::number(watcher.result()));
}
