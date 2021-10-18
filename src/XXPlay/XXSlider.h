#pragma once
#include <qslider.h>
class XXSlider :public QSlider
{
public:
	XXSlider(QWidget *p = NULL);
	virtual ~XXSlider();

	void mousePressEvent(QMouseEvent *e) override;
};

