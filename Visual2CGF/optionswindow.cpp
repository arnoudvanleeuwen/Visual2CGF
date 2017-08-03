#include "optionswindow.h"
#include "pugixml-1.8\pugixml.hpp"
#include <qfiledialog.h>

OptionsWindow::OptionsWindow(MainWindow *main, QWidget *parent)
	: QWidget(parent), mpMain(main), mSettings() {
	ui.setupUi(this);

	connect(ui.btn_save, SIGNAL(clicked()), this, SLOT(save_settings()));
	connect(ui.btn_browse_localrepo, SIGNAL(clicked()), this, SLOT(browse_localrepo()));
	connect(ui.btn_browse_localmodels, SIGNAL(clicked()), this, SLOT(browse_dbdev2()));
	connect(ui.drive_letter_select, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(setDriveLetter(const QString &)));

	mSettings = new Settings();
	ui.line_pathtolocalrepo->setText(mSettings->path_to_repo().c_str());
	ui.line_pathtolocalmodels->setText(mSettings->path_to_data3().c_str());
	if (mSettings->drive_letter().isEmpty()) {
		ui.drive_letter_select->setCurrentIndex(0);
	}
	else {
		ui.drive_letter_select->setCurrentText(mSettings->drive_letter());
	}
}

OptionsWindow::~OptionsWindow() {

}

void OptionsWindow::save_settings() {
	if (!mSettings->save()) {
		mpMain->write_warning("Could not save settings file");
	}
	else close();
}

void OptionsWindow::browse_localrepo() {
	std::string dir = QFileDialog::getExistingDirectory(NULL, "Select the visual moving models root directory", "", QFileDialog::ShowDirsOnly).toStdString();
	mSettings->set_path_to_repo(dir);
	ui.line_pathtolocalrepo->setText(dir.c_str());
}

void OptionsWindow::browse_dbdev2() {
	std::string dir = QFileDialog::getExistingDirectory(NULL, "Select the visual moving models root directory", "", QFileDialog::ShowDirsOnly).toStdString();
	mSettings->set_path_to_data(dir);
	ui.line_pathtolocalmodels->setText(dir.c_str());
}

void OptionsWindow::setDriveLetter(const QString & s) {
	mSettings->set_default_drive(s.toStdString());
}
