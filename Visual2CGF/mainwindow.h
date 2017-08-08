#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <qstring.h>
#include <map>
#include <vector>
#include <boost/filesystem.hpp>

#include "ConsoleMessage.h"
#include "NetworkManager.h"
#include "OpenFlight/Model.h"

typedef std::vector<ConsoleMessage> msg_list;
typedef msg_list::iterator msg_list_it;

class MainWindow : public QMainWindow
{
	Q_OBJECT

		enum entity_types
	{
		FixedWing, Land, LifeForm, RotaryWing, Submersible, Surface, Weapons
	};

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	void write_msg(const ConsoleMessage msg);

private:
	//members
	NetworkManager *m_nmgr;
	Ui::MainWindowClass ui;
	std::map<QListWidgetItem*, OpenFlight::Model*> models;
	msg_list messages;
	boost::filesystem::path mPath;

	private slots:
	void findFltFiles(int type);
	void showOptions();
	void onModelDoubleClick(QListWidgetItem *item);
	void saveConsole();
	void clearConsole();
};


#endif // MAINWINDOW_H
