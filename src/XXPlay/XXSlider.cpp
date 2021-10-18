#include "XXSlider.h"
#include <QMouseEvent>

XXSlider::XXSlider(QWidget *p):QSlider(p)
{
}


XXSlider::~XXSlider()
{
}

void XXSlider::mousePressEvent(QMouseEvent * e)
{
	int value = ((float)e->pos().x() / (float)this->width())*(this->maximum() + 1);
	this->setValue(value);
	QSlider::mousePressEvent(e);
}
