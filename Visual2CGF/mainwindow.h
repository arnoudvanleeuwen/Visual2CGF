#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <qstring.h>
#include <vector>
#include "NetworkManager.h"
#include "MovingModel.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

		enum entity_types
	{
		FixedWing, Land, LifeForm, Weapons, RotaryWing, Submersible, Surface
	};

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	void write_info(const QString msg);
	void write_warning(const QString msg);
	void write_error(const QString msg);

private:
	//members
	NetworkManager *m_nmgr;
	Ui::MainWindowClass ui;
	std::vector<MovingModel*> list;

	//methods
	void populateEntityList(entity_types);
	void parseDir(std::string path);

	private slots:
	void showOptions();
	void showModels(const QString&);
};

#endif // MAINWINDOW_H
