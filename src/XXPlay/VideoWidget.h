#pragma once

#include <QtWidgets/qwidget.h>
#include <QOpenGLWidget>
class VideoWidget :public QOpenGLWidget
{
public:
	VideoWidget(QWidget* parent = NULL);

	void paintEvent(QPaintEvent* pEvent) override;
	
	void timerEvent(QTimerEvent* pEvent) override;

	~VideoWidget();
};

