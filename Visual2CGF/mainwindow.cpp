#include "mainwindow.h"
#include "optionswindow.h"
#include "Settings.h"
#include <Windows.h>
//#include <boost/filesystem.hpp>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Connections
	connect(ui.actionSettings, SIGNAL(triggered()), this, SLOT(showOptions()));
	connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(close()));
	connect(ui.maintype_select, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(showModels(const QString &)));

	showModels(ui.maintype_select->currentText());
}

MainWindow::~MainWindow()
{

}

void MainWindow::write_info(const QString msg) {
	QListWidgetItem *it = new QListWidgetItem(QIcon("Resources\\information.png"), msg);
	ui.console->addItem(it);
}

void MainWindow::write_warning(const QString msg) {
	QListWidgetItem *it = new QListWidgetItem(QIcon("Resources\\warning.png"), msg);
	ui.console->addItem(it);
}

void MainWindow::write_error(const QString msg) {
	QListWidgetItem *it = new QListWidgetItem(QIcon("Resources\\error.png"), msg);
	ui.console->addItem(it);
}

void MainWindow::populateEntityList(entity_types e) {
	std::string path;
	Settings stng;
	path = stng.path_to_data3();
	path = stng.path_to_repo();
	if (path.empty()) {
		//No local repo or connection to \\dbdev2\Data3, lets create it
	}


	// juiste folder adhv type
	switch (e) {
	case MainWindow::FixedWing:
		break;
	case MainWindow::LifeForm:
		break;
	case MainWindow::Mine:
		break;
	case MainWindow::RotaryWing:
		break;
	case MainWindow::Submersible:
		break;
	case MainWindow::Surface:
		break;
	case MainWindow::Tracked:
		break;
	case MainWindow::Wheeled:
		break;
	default:
		break;
	}

	//poulate list
}

void MainWindow::showModels(const QString & s) {
	write_info(s);
	if (s == "Fixed wing") {
		populateEntityList(entity_types::FixedWing);
	}
	else if (s == "Lifeform") {
		populateEntityList(entity_types::LifeForm);
	}
	else if (s == "Mine") {
		populateEntityList(entity_types::Mine);
	}
	else if (s == "Rotary wing") {
		populateEntityList(entity_types::RotaryWing);
	}
	else if (s == "Submersible") {
		populateEntityList(entity_types::Submersible);
	}
	else if (s == "Surface") {
		populateEntityList(entity_types::Surface);
	}
	else if (s == "Tracked") {
		populateEntityList(entity_types::Tracked);
	}
	else {
		populateEntityList(entity_types::Wheeled);
	}
}

void MainWindow::showOptions() {
	OptionsWindow *o = new OptionsWindow(this);
	o->show();
}
