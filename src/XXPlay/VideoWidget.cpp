#include "VideoWidget.h"
#include "XFFmpeg.h"
#include "VideoThread.h"
#include <QPainter>


VideoWidget::VideoWidget(QWidget * parent):QOpenGLWidget(parent)
{
	//XFFmpeg::Get()->Open("D:\\video.mp4");
	startTimer(20);
	VideoThread::Get()->start();
}

void VideoWidget::paintEvent(QPaintEvent * pEvent)
{
	static QImage* pImage = nullptr;
	static int w = 0;
	static int h = 0;
	if (w != width() || h != height())
	{
		if (pImage)
		{
			delete pImage->bits();
			delete pImage;
			pImage = nullptr;
		}
	}

	if (pImage == nullptr) {
		unsigned char *pBuffer = new unsigned char[width() * height() * 4];
		pImage = new QImage(pBuffer, width(), height(), QImage::Format_ARGB32);
	}

	XFFmpeg::Get()->ToRGB((char*)pImage->bits(), width(), height());
	QPainter  painter;
	painter.begin(this);
	painter.drawImage(QPoint(0, 0),*pImage);
	painter.end();
}

void VideoWidget::timerEvent(QTimerEvent * pEvent)
{
	this->update();
}

VideoWidget::~VideoWidget()
{

}
