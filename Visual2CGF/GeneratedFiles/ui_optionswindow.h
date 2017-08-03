/********************************************************************************
** Form generated from reading UI file 'optionswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSWINDOW_H
#define UI_OPTIONSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionsWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *line_pathtolocalmodels;
    QPushButton *btn_browse_localmodels;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *line_pathtolocalrepo;
    QPushButton *btn_browse_localrepo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *drive_letter_select;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_save;
    QPushButton *btn_cancel;

    void setupUi(QWidget *OptionsWindow)
    {
        if (OptionsWindow->objectName().isEmpty())
            OptionsWindow->setObjectName(QStringLiteral("OptionsWindow"));
        OptionsWindow->resize(540, 164);
        verticalLayout = new QVBoxLayout(OptionsWindow);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(OptionsWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(170, 23));

        horizontalLayout_2->addWidget(label);

        line_pathtolocalmodels = new QLineEdit(OptionsWindow);
        line_pathtolocalmodels->setObjectName(QStringLiteral("line_pathtolocalmodels"));
        line_pathtolocalmodels->setMinimumSize(QSize(50, 23));

        horizontalLayout_2->addWidget(line_pathtolocalmodels);

        btn_browse_localmodels = new QPushButton(OptionsWindow);
        btn_browse_localmodels->setObjectName(QStringLiteral("btn_browse_localmodels"));
        btn_browse_localmodels->setMinimumSize(QSize(27, 23));
        btn_browse_localmodels->setMaximumSize(QSize(27, 23));

        horizontalLayout_2->addWidget(btn_browse_localmodels);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(OptionsWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(170, 23));

        horizontalLayout_3->addWidget(label_2);

        line_pathtolocalrepo = new QLineEdit(OptionsWindow);
        line_pathtolocalrepo->setObjectName(QStringLiteral("line_pathtolocalrepo"));
        line_pathtolocalrepo->setMinimumSize(QSize(50, 23));

        horizontalLayout_3->addWidget(line_pathtolocalrepo);

        btn_browse_localrepo = new QPushButton(OptionsWindow);
        btn_browse_localrepo->setObjectName(QStringLiteral("btn_browse_localrepo"));
        btn_browse_localrepo->setMinimumSize(QSize(27, 23));
        btn_browse_localrepo->setMaximumSize(QSize(27, 23));

        horizontalLayout_3->addWidget(btn_browse_localrepo);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(OptionsWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(170, 23));

        horizontalLayout_4->addWidget(label_3);

        drive_letter_select = new QComboBox(OptionsWindow);
        drive_letter_select->setObjectName(QStringLiteral("drive_letter_select"));
        drive_letter_select->setMinimumSize(QSize(40, 0));
        drive_letter_select->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_4->addWidget(drive_letter_select);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_save = new QPushButton(OptionsWindow);
        btn_save->setObjectName(QStringLiteral("btn_save"));

        horizontalLayout->addWidget(btn_save);

        btn_cancel = new QPushButton(OptionsWindow);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));

        horizontalLayout->addWidget(btn_cancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(OptionsWindow);
        QObject::connect(btn_cancel, SIGNAL(clicked()), OptionsWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(OptionsWindow);
    } // setupUi

    void retranslateUi(QWidget *OptionsWindow)
    {
        OptionsWindow->setWindowTitle(QApplication::translate("OptionsWindow", "OptionsWindow", Q_NULLPTR));
        label->setText(QApplication::translate("OptionsWindow", "Path to local \\dbdev2Data3 drive", Q_NULLPTR));
        btn_browse_localmodels->setText(QApplication::translate("OptionsWindow", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("OptionsWindow", "Path to local visual-mm repository", Q_NULLPTR));
        btn_browse_localrepo->setText(QApplication::translate("OptionsWindow", "...", Q_NULLPTR));
        label_3->setText(QApplication::translate("OptionsWindow", "Default External drive letter", Q_NULLPTR));
        drive_letter_select->clear();
        drive_letter_select->insertItems(0, QStringList()
         << QApplication::translate("OptionsWindow", "A:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "B:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "D:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "E:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "F:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "G:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "H:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "I:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "J:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "K:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "L:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "M:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "O:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "R:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "R:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "S:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "T:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "V:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "W:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "X:", Q_NULLPTR)
         << QApplication::translate("OptionsWindow", "Z:", Q_NULLPTR)
        );
        btn_save->setText(QApplication::translate("OptionsWindow", "Save", Q_NULLPTR));
        btn_cancel->setText(QApplication::translate("OptionsWindow", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OptionsWindow: public Ui_OptionsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSWINDOW_H
