#include <QFormLayout>
#include <QSlider>
#include <QLineEdit>
#include <QLabel>

#include "window.h"

Window::Window(Data data, QWidget *parent) : input_data(data), QWidget(parent)
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
}
