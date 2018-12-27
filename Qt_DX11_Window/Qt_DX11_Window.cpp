#include "Qt_DX11_Window.h"

Qt_DX11_Window::Qt_DX11_Window(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);

	// Ä¬ÈÏ³ß´ç...
	QMainWindow::resize(800, 600);

	AddDockWindow();

	mD3D11Widget = new QD3D11Widget(parent);
	setCentralWidget(mD3D11Widget);

	QMainWindow::setWindowState(Qt::WindowMaximized);

	mD3D11Widget->CreateD3DApp((HWND)mD3D11Widget->winId());
}

void Qt_DX11_Window::AddDockWindow()
{
	mTreeWidget = new QTreeWidget(this);

	mPropertyDock = new QDockWidget(this);
	mPropertyDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	mPropertyDock->setObjectName(QString::fromUtf8("PropertyDock"));
	mPropertyDock->setWidget(mTreeWidget);
	addDockWidget(static_cast<Qt::DockWidgetArea>(1), mPropertyDock);

	mPropertyDock->raise();
}
