/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionSettings;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionSave_console;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QComboBox *maintype_select;
    QSpacerItem *verticalSpacer;
    QListWidget *model_list;
    QListWidget *console;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_clear;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(884, 700);
        actionSettings = new QAction(MainWindowClass);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionExit = new QAction(MainWindowClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(MainWindowClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionSave_console = new QAction(MainWindowClass);
        actionSave_console->setObjectName(QStringLiteral("actionSave_console"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        maintype_select = new QComboBox(centralWidget);
        maintype_select->setObjectName(QStringLiteral("maintype_select"));
        maintype_select->setMinimumSize(QSize(100, 0));

        verticalLayout->addWidget(maintype_select);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        model_list = new QListWidget(centralWidget);
        model_list->setObjectName(QStringLiteral("model_list"));
        model_list->setSortingEnabled(false);

        horizontalLayout->addWidget(model_list);


        verticalLayout_2->addLayout(horizontalLayout);

        console = new QListWidget(centralWidget);
        console->setObjectName(QStringLiteral("console"));
        console->setMinimumSize(QSize(0, 200));
        console->setMaximumSize(QSize(16777215, 500));
        console->setSelectionRectVisible(true);

        verticalLayout_2->addWidget(console);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_clear = new QPushButton(centralWidget);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));

        horizontalLayout_2->addWidget(btn_clear);


        verticalLayout_3->addLayout(horizontalLayout_2);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 884, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionSave_console);
        menuFile->addSeparator();
        menuFile->addAction(actionSettings);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", Q_NULLPTR));
        actionSettings->setText(QApplication::translate("MainWindowClass", "Settings", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindowClass", "Exit", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindowClass", "About", Q_NULLPTR));
        actionSave_console->setText(QApplication::translate("MainWindowClass", "Export console", Q_NULLPTR));
        maintype_select->clear();
        maintype_select->insertItems(0, QStringList()
         << QApplication::translate("MainWindowClass", "Fixed wing", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "Land", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "Lifeform", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "Rotary wing", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "Submersible", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "Surface", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "Weapons", Q_NULLPTR)
        );
        btn_clear->setText(QApplication::translate("MainWindowClass", "Clear", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindowClass", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
