#include "controlpanel.h"

#include <QPushButton>

ControlPanel::ControlPanel(QWidget *parent) : QWidget(parent)
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setLayout(new QVBoxLayout);

    this->circleButton = new CircleButton(this);
    this->zoomSlider = new ZoomSlider(this);
    this->layout()->addWidget(this->circleButton);
    this->layout()->addWidget(this->zoomSlider);
    this->layout()->setAlignment(this->circleButton, Qt::AlignTop|Qt::AlignLeft);
    this->layout()->setAlignment(this->zoomSlider, Qt::AlignBottom);
}
