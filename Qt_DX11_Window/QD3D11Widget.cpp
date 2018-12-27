

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
	RECT rc;
	::GetClientRect(hwnd, &rc);
	int width = rc.right - rc.left;
	int height = rc.bottom - rc.top;

	mD3DApp = new D3DApplication(nullptr);
	mD3DApp->SetClientWidth(width);
	mD3DApp->SetClientHeight(height);
	mD3DApp->InitQt(hwnd);
}

void QD3D11Widget::RenderScene()
{
	mD3DApp->RenderQt();
}

void QD3D11Widget::resizeEvent(QResizeEvent *event)
{
	QSize size = event->size();
	int width = size.width();
	int height = size.height();
	mD3DApp->SetClientWidth(width);
	mD3DApp->SetClientHeight(height);
	mD3DApp->ResetQt();
}

void QD3D11Widget::mousePressEvent(QMouseEvent *event)
{

}

void QD3D11Widget::mouseReleaseEvent(QMouseEvent *event)
{

}

void QD3D11Widget::mouseMoveEvent(QMouseEvent *event)
{

}