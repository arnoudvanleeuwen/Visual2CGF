#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <mgapiall.h>

int main(int argc, char *argv[])
{
    // Mandatory Openflight api intialisation
    mgInit(&argc, argv);

    // Qt window initialisation
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
