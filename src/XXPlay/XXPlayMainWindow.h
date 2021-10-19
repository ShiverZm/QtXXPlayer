#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_XXPlayMainWindow.h"

class XXPlayMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    XXPlayMainWindow(QWidget *parent = Q_NULLPTR);
	virtual ~XXPlayMainWindow() {};
	void resizeEvent(QResizeEvent *e);
	void timerEvent(QTimerEvent* pEvent) override;

public slots:
	void open();
	void openFile(QString name);
	void sliderPress();
	void sliderRelease();
	void play();

private:
    Ui::XXPlayMainWindowClass ui;
	bool isPressSlider = true;
};
