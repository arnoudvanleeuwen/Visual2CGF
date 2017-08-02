#include "optionswindow.h"
#include "pugixml-1.8\pugixml.hpp"
#include <qfiledialog.h>

OptionsWindow::OptionsWindow(MainWindow *main, QWidget *parent)
	: QWidget(parent), mpMain(main), mSettings() {
	ui.setupUi(this);

	connect(ui.btn_save, SIGNAL(clicked()), this, SLOT(save_settings()));
	connect(ui.btn_browse_localrepo, SIGNAL(clicked()), this, SLOT(browse_localrepo()));
	connect(ui.btn_browse_localmodels, SIGNAL(clicked()), this, SLOT(browse_dbdev2()));

	mSettings = new ProgramSettings();
	ui.line_pathtolocalrepo->setText(mSettings->path_to_repo().c_str());
	ui.line_pathtolocalmodels->setText(mSettings->path_to_data3().c_str());
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

/*
* -------------------------------------------
* CLASS: Settings
* -------------------------------------------
*/

ProgramSettings::ProgramSettings() {
	//parse settings.xml
	pugi::xml_parse_result res = mdoc.load_file(SETTING_FILE);
	if (!res) {
		auto decl = mdoc.append_child(pugi::node_declaration);
		decl.append_attribute("version") = "1.0";
		decl.append_attribute("encoding") = pugi::encoding_auto;
		auto root = mdoc.append_child("Settings");
		pugi::xml_node datanode = root.append_child(SETTING_DATA3);
		pugi::xml_node reponode = root.append_child(SETTING_REPO);
		datanode.append_child(pugi::node_pcdata).set_value("");
		reponode.append_child(pugi::node_pcdata).set_value("");
		this->save();
	}
}

ProgramSettings::~ProgramSettings() {
}

void ProgramSettings::set_path_to_repo(std::string s) {
	mdoc.document_element().child(SETTING_REPO).text().set(s.c_str());
}

void ProgramSettings::set_path_to_data(std::string s) {
	mdoc.document_element().child(SETTING_DATA3).text().set(s.c_str());
}

std::string ProgramSettings::path_to_repo() const {
	return std::string(mdoc.document_element().child(SETTING_REPO).child_value());
}

std::string ProgramSettings::path_to_data3() const {
	return std::string(mdoc.document_element().child(SETTING_DATA3).child_value());
}
