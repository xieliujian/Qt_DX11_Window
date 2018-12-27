#include "Qt_DX11_Window.h"

Qt_DX11_Window::Qt_DX11_Window(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);

	mD3D11Widget = new QD3D11Widget(parent);
	setCentralWidget(mD3D11Widget);

	QMainWindow::setWindowState(Qt::WindowMaximized);

	mD3D11Widget->CreateD3DApp((HWND)mD3D11Widget->winId());
}
