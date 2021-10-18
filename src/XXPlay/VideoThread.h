#pragma once

#include <QThread>
class VideoThread :public QThread
{
public:
	VideoThread();

	static VideoThread *Get()
	{
		static VideoThread vt;
		return &vt;
	}

	void run() override;
	virtual ~VideoThread();
};

