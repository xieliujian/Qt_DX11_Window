
#ifndef __Application_h__
#define __Application_h__

#include "Core.h"
#include <windows.h>

NAMESPACEBEGIN(GameEngine)

class Application
{
public:
	Application(HINSTANCE hInstance);
	~Application();

	virtual bool Init() = 0;
	virtual int Run() = 0;
	virtual void Clear() = 0;
	virtual void Present() = 0;

	virtual bool InitQt(HWND hwnd) { return true; }
	virtual void RenderQt() {}
	virtual void ResetQt() {}

	void SetClientWidth(int width) { mClientWidth = width; }
	void SetClientHeight(int height) { mClientHeight = height; }
protected:
	HINSTANCE mhAppInst;
	GameTimer mTimer;

	std::wstring mMainWndCaption;
	int mClientWidth;
	int mClientHeight;
	Color mClearColor;
};

NAMESPACEEND

#endif