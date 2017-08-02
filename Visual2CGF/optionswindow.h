#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QWidget>
#include "ui_optionswindow.h"
#include "mainwindow.h"
#include "Settings.h"
#include <string>


class OptionsWindow : public QWidget
{
	Q_OBJECT

public:
	OptionsWindow(MainWindow *main, QWidget *parent = 0);
	~OptionsWindow();

private:
	Ui::OptionsWindow ui;
	MainWindow *mpMain;
	Settings *mSettings;

	private slots:
	void save_settings();
	void browse_localrepo();
	void browse_dbdev2();
};

#endif // OPTIONSWINDOW_H
