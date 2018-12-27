
#include "Application.h"

NAMESPACEBEGIN(GameEngine)

Application::Application(HINSTANCE hInstance)
	:mMainWndCaption(L"D3D11 Application"),
	mClientWidth(1024),
	mClientHeight(768)
{
	mClearColor = Color(49.0f / 255.0f, 77.0f / 255.0f, 121.0f / 255.0f, 1.0f);
}

Application::~Application()
{

}

NAMESPACEEND
