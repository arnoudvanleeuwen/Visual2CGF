#include "mainwindow.h"
#include "optionswindow.h"
#include "Settings.h"
#include "DirIterator.h"

#include <Windows.h>
#include <sstream>

//#include <boost/filesystem.hpp>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), m_nmgr(nullptr) {
	ui.setupUi(this);

	//Connections
	connect(ui.actionSettings, SIGNAL(triggered()), this, SLOT(showOptions()));
	connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(close()));
	connect(ui.maintype_select, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(showModels(const QString &)));

	m_nmgr = new NetworkManager(L"\\\\dbdev2\\Data3", L"visdbdev", L"v1sdb@ATTS");
	showModels(ui.maintype_select->currentText());
}

MainWindow::~MainWindow() {
	delete m_nmgr;
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

	// If no local path to visual-MM is set, establish connection with dbdev2
	if (path.empty()) {
		if (stng.drive_letter().toStdString().empty()) {
			write_error("Default drive letter not set, cannot establish remote connection. Set default drive in File->Settings");
			return;
		}
		std::stringstream ss;
		if (!m_nmgr->connected()) {
			switch (m_nmgr->connect()) {
			case NO_ERROR:
				ss << "Connected to " << m_nmgr->drive();
				write_info(ss.str().c_str());
				break;
			case ERROR_INVALID_FUNCTION:
				ss << "Connection to " << m_nmgr->drive() << " succeeded with errors, ERROR_INVALID_FUNCTION";
				write_warning(ss.str().c_str());
				break;
			case ERROR_BAD_DEVICE:
				ss << "Connection to " << m_nmgr->drive() << " failed, ERROR_BAD_DEVICE";
				write_error(ss.str().c_str());
				return;
			default:
				ss << "Connection to " << m_nmgr->drive() << " failed (error code 0x" << std::hex << m_nmgr->status() << ")";
				write_error(ss.str().c_str());
				return;
			}
		}
	}
	else {
		std::stringstream ss;
		ss << "Local visual-MM directory found at " << path;
		write_info(ss.str().c_str());
	}

	// juiste folder adhv type
	switch (e) {
	case MainWindow::FixedWing:
		path.append("\\AIR_MOVING_MODELS\\FIXED_WING_MODELS");
		break;
	case MainWindow::LifeForm:
		path.append("\\LIFEFORM");
		break;
	case MainWindow::Weapons:
		path.append("\\EXTERNAL_STORE_MODELS");
		break;
	case MainWindow::RotaryWing:
		path.append("\\AIR_MOVING_MODELS\\HELICOPTER_MODELS");
		break;
	case MainWindow::Submersible:
		path.append("\\NAVAL_MOVING_MODELS\\MAN_OF_WAR\\SUBMARINES");
		break;
	case MainWindow::Surface:
		path.append("\\NAVAL_MOVING_MODELS");
		break;
	case MainWindow::Land:
		path.append("\\LAND_MOVING_MODELS");
		break;
	default:
		return;
	}

	//poulate list
	parseDir(path);
}

void MainWindow::parseDir(std::string path) {
	std::vector < std::string > vec;
	DirIterator it;
	it.find_files(".flt", path, vec, true);
}

void MainWindow::showModels(const QString & s) {
	if (s == "Fixed wing") {
		populateEntityList(entity_types::FixedWing);
	}
	else if (s == "Lifeform") {
		populateEntityList(entity_types::LifeForm);
	}
	else if (s == "Weapons") {
		populateEntityList(entity_types::Weapons);
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
	else if (s == "Land") {
		populateEntityList(entity_types::Land);
	}
}

void MainWindow::showOptions() {
	OptionsWindow *o = new OptionsWindow(this);
	o->show();
}
