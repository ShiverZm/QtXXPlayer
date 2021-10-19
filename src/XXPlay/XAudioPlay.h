/*******************************************************************************
**                                                                            **
**                    Jiedi(China nanjing)Ltd.                                **
**	      ��Ȩ���Ĳܿ����У��˴���ֻ����Ϊѧϰ�ο�����������                  **                                                                            **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Project       : XAudioPlay
** Description   : ��Ƶ������
** Contact       : xiacaojun@qq.com
**        ����   : http://blog.csdn.net/jiedichina
**        QQ	 : 99981441
**		  QQȺ	 ��462249121
**   ΢�Ź��ں�  : jiedi2007
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

