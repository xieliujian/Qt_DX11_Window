
#ifndef __QD3D11Widget_h__
#define __QD3D11Widget_h__

#include <QWidget>
#include <QTimer>
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
	virtual void RenderScene();

	// event
	QPaintEngine* paintEngine() const { return 0; }	// ‘ –Ìdx‰÷»æ

	QTimer mTimer;
	QPoint mCurMousePt;

public:
	void CreateD3DApp(HWND hwnd);
private:
	D3DApplication *mD3DApp;
};

#endif

