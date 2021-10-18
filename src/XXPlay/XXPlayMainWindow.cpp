#include "XXPlayMainWindow.h"
#include "XFFmpeg.h"

#include <QFileDialog>
#include <QMessageBox>


static bool isPlay = true;

#define PAUSE "QPushButton\
{border-image:url\
(:/XXPlayMainWindow/Resources/pause_normal.png);}"

#define PLAY "QPushButton\
{border-image:url\
(:/XXPlayMainWindow/Resources/play_normal.png);}"

XXPlayMainWindow::XXPlayMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	startTimer(40);
}

void XXPlayMainWindow::play()
{
	isPlay = !isPlay;
	XFFmpeg::Get()->isPlay = isPlay;
	if (isPlay)
	{
		//pause
		ui.playButton->setStyleSheet(PAUSE);
	}
	else
	{
		ui.playButton->setStyleSheet(PLAY);
	}
}

void XXPlayMainWindow::resizeEvent(QResizeEvent * e)
{
	ui.openGLWidget->resize(size());
	ui.playButton->move(this->width() / 2 + 50, this->height() - 80);
	ui.openButton->move(this->width() / 2 - 50, this->height() - 80);
	ui.playslider->move(25, this->height() - 120);
	ui.playslider->resize(this->width() - 50, ui.playslider->height());
	ui.playtime->move(25, ui.playButton->y());
	ui.sp->move(ui.playtime->x() + ui.playtime->width() + 5, ui.playtime->y());
	ui.totaltime->move(150, ui.playButton->y());
}

void XXPlayMainWindow::timerEvent(QTimerEvent *e) {
	int min = (XFFmpeg::Get()->m_pts / 1000) / 60;
	int sec = (XFFmpeg::Get()->m_pts / 1000) % 60;
	char buf[1024] = { 0 };
	sprintf(buf, "%03d:%02d", min, sec);
	ui.playtime->setText(buf);

	if (XFFmpeg::Get()->totalMs > 0)
	{
		float rate = (float)XFFmpeg::Get()->m_pts / (float)XFFmpeg::Get()->totalMs;
		if (!isPressSlider){
			ui.playslider->setValue(rate * 1000);
		}
	}
}

void XXPlayMainWindow::sliderPress()
{
	isPressSlider = true;
}

void XXPlayMainWindow::sliderRelease()
{
	isPressSlider = false;
	float pos = 0;
	pos = (float)ui.playslider->value() / (float)(ui.playslider->maximum() + 1);
	XFFmpeg::Get()->Seek(pos);
}

void XXPlayMainWindow::open()
{
	QString name = QFileDialog::getOpenFileName(
		this, QString::fromLocal8Bit("选择视频文件"));
	if (name.isEmpty()) {
		return;
	}
		
	this->setWindowTitle(name);
	int totalMs = XFFmpeg::Get()->Open(name.toLocal8Bit());

	if (totalMs <= 0)
	{
		QMessageBox::information(this, "err", "file open failed!");
		return;
	}
	char buf[1024] = { 0 };
	int min = (totalMs / 1000) / 60;
	int sec = (totalMs / 1000) % 60;
	sprintf(buf, "%03d:%02d", min, sec);
	ui.totaltime->setText(buf);
	XFFmpeg::Get()->isPlay = true;

	this->update();
}
