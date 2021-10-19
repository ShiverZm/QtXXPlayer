/*******************************************************************************
**                                                                            **
**                    Jiedi(China nanjing)Ltd.                                **
**	      版权归夏曹俊所有，此代码只能作为学习参考，不得商用                  **                                                                            **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Project       : XAudioPlay
** Description   : 音频播放类
** Contact       : xiacaojun@qq.com
**        博客   : http://blog.csdn.net/jiedichina
**        QQ	 : 99981441
**		  QQ群	 ：462249121
**   微信公众号  : jiedi2007
** Creation date : 2016-12-20
**
*******************************************************************************/

#pragma once
class XAudioPlay
{
public:
	static XAudioPlay *Get();
	virtual bool Start() = 0;
	virtual void Stop() = 0;
	virtual void Play(bool isplay) = 0;
	virtual bool Write(const char *data, int datasize)=0;
	virtual int GetFree() = 0;
	int sampleRate = 48000;
	int sampleSize = 16;
	int channel = 2;

	virtual ~XAudioPlay();
protected:
	XAudioPlay();
};

