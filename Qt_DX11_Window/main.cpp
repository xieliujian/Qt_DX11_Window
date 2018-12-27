#include "Qt_DX11_Window.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Qt_DX11_Window w;
	w.show();
	return a.exec();
}
