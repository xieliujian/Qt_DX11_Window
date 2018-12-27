

#include "QD3D11Widget.h"

QD3D11Widget::QD3D11Widget(QWidget *parent)
{
	QWidget::setAttribute(Qt::WA_PaintOnScreen); // 允许DX渲染 ...
	setFocusPolicy(Qt::WheelFocus); // 允许按键时间 ...
	setMouseTracking(true); // 允许鼠标移动 ...

	mTimer.setInterval(0);
	QObject::connect(&mTimer, SIGNAL(timeout()), this, SLOT(Idle()));
	mTimer.start();
}

QD3D11Widget::~QD3D11Widget()
{

}

void QD3D11Widget::Idle()
{
	RenderScene();
}

void QD3D11Widget::CreateD3DApp(HWND hwnd)
{
	mD3DApp = new D3DApplication(nullptr);
	mD3DApp->InitQt(hwnd);
}

void QD3D11Widget::RenderScene()
{
	mD3DApp->RenderQt();
}