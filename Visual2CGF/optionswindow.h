#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QWidget>
#include "ui_optionswindow.h"
#include "mainwindow.h"
#include "pugixml-1.8\pugixml.hpp"
#include <string>

#define SETTING_FILE	"settings.xml"
#define SETTING_REPO	"PathToRepo"
#define SETTING_DATA3	"PathToData3"


class ProgramSettings
{
public:
	ProgramSettings();
	~ProgramSettings();

	void set_path_to_repo(std::string);
	void set_path_to_data(std::string);
	inline bool save() const { return mdoc.save_file(SETTING_FILE); }
	std::string path_to_repo() const;
	std::string path_to_data3() const;

private:
	pugi::xml_document mdoc;

};


class OptionsWindow : public QWidget
{
	Q_OBJECT

public:
	OptionsWindow(MainWindow *main, QWidget *parent = 0);
	~OptionsWindow();

private:
	Ui::OptionsWindow ui;
	MainWindow *mpMain;
	ProgramSettings *mSettings;

	private slots:
	void save_settings();
	void browse_localrepo();
	void browse_dbdev2();
};

#endif // OPTIONSWINDOW_H
