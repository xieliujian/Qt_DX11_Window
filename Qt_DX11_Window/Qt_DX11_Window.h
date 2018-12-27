#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_DX11_Window.h"
#include "QD3D11Widget.h"

class Qt_DX11_Window : public QMainWindow
{
	Q_OBJECT

public:
	Qt_DX11_Window(QWidget *parent = Q_NULLPTR);

private:
	//Ui::Qt_DX11_WindowClass ui;
	QD3D11Widget *mD3D11Widget;
};
