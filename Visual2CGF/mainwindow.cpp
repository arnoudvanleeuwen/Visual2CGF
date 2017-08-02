#include "mainwindow.h"
#include "optionswindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Connections
	connect(ui.actionSettings, SIGNAL(triggered()), this, SLOT(showOptions()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::write_info(const char* msg) {
	QListWidgetItem *it = new QListWidgetItem(QIcon("Resources\\information.png"), msg);
	ui.console->addItem(it);
}

void MainWindow::write_warning(const char* msg) {
	QListWidgetItem *it = new QListWidgetItem(QIcon("Resources\\warning.png"), msg);
	ui.console->addItem(it);
}

void MainWindow::write_error(const char* msg) {
	QListWidgetItem *it = new QListWidgetItem(QIcon("Resources\\error.png"), msg);
	ui.console->addItem(it);
}

void MainWindow::showOptions() {
	OptionsWindow *o = new OptionsWindow(this);
	o->show();
}
