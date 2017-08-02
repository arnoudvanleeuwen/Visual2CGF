#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <qstring.h>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	void write_info(const char* msg);
	void write_warning(const char* msg);
	void write_error(const char* msg);

private:
	Ui::MainWindowClass ui;

	private slots:
	void showOptions();
};

#endif // MAINWINDOW_H
