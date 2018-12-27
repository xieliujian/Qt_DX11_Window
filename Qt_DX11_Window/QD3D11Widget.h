
#ifndef __QD3D11Widget_h__
#define __QD3D11Widget_h__

#include <QWidget>
#include <QTimer>
#include <QtGui>
#include "D3DApplication.h"

using namespace GameEngine;

class QD3D11Widget : public QWidget
{
	Q_OBJECT
public:
	QD3D11Widget(QWidget *parent);
	virtual ~QD3D11Widget();
public slots:
	void Idle();
protected:
	// event
	QPaintEngine* paintEngine() const { return 0; }	// ‘ –Ìdx‰÷»æ

	virtual void resizeEvent(QResizeEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);

	QTimer mTimer;
	QPoint mCurMousePt;

public:
	void CreateD3DApp(HWND hwnd);

	virtual void RenderScene();
private:
	D3DApplication *mD3DApp;
};

#endif

