#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_DX11_Window.h"
#include "QD3D11Widget.h"
#include <QDockWidget>
#include <QTreeWidget>
#include "qtpropertymanager.h"
#include "qtvariantproperty.h"
#include "qttreepropertybrowser.h"

class Qt_DX11_Window : public QMainWindow
{
	Q_OBJECT

public:
	Qt_DX11_Window(QWidget *parent = Q_NULLPTR);

private:
	void AddDockWindow();
	void CreatePropertyGrid();
private:
	//Ui::Qt_DX11_WindowClass ui;
	QD3D11Widget *mD3D11Widget;
	QDockWidget *mPropertyDock;
	QtTreePropertyBrowser *mPropertyBrowser;
};
