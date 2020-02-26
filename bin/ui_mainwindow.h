/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionClear;
    QAction *actionCreate;
    QAction *action8;
    QAction *action9;
    QAction *action10;
    QAction *action11;
    QAction *action12;
    QAction *actionDark;
    QAction *actionLight;
    QAction *actionFind;
    QAction *actionVersion;
    QAction *actionVersion_2;
    QAction *actionQt;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QTextEdit *text;
    QLineEdit *command;
    QMenuBar *menuBar;
    QMenu *menuSave_File;
    QMenu *menuSettings;
    QMenu *menuFonts;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(944, 565);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(11);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/seuqoia-icon-opened.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        actionCreate = new QAction(MainWindow);
        actionCreate->setObjectName(QString::fromUtf8("actionCreate"));
        action8 = new QAction(MainWindow);
        action8->setObjectName(QString::fromUtf8("action8"));
        action9 = new QAction(MainWindow);
        action9->setObjectName(QString::fromUtf8("action9"));
        action10 = new QAction(MainWindow);
        action10->setObjectName(QString::fromUtf8("action10"));
        action11 = new QAction(MainWindow);
        action11->setObjectName(QString::fromUtf8("action11"));
        action12 = new QAction(MainWindow);
        action12->setObjectName(QString::fromUtf8("action12"));
        actionDark = new QAction(MainWindow);
        actionDark->setObjectName(QString::fromUtf8("actionDark"));
        actionLight = new QAction(MainWindow);
        actionLight->setObjectName(QString::fromUtf8("actionLight"));
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        actionVersion = new QAction(MainWindow);
        actionVersion->setObjectName(QString::fromUtf8("actionVersion"));
        actionVersion_2 = new QAction(MainWindow);
        actionVersion_2->setObjectName(QString::fromUtf8("actionVersion_2"));
        actionQt = new QAction(MainWindow);
        actionQt->setObjectName(QString::fromUtf8("actionQt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        text = new QTextEdit(centralWidget);
        text->setObjectName(QString::fromUtf8("text"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Droid Sans"));
        font1.setPointSize(12);
        text->setFont(font1);
        text->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(text, 1, 0, 1, 1);

        command = new QLineEdit(centralWidget);
        command->setObjectName(QString::fromUtf8("command"));
        QFont font2;
        font2.setPointSize(12);
        command->setFont(font2);

        gridLayout->addWidget(command, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 944, 29));
        menuSave_File = new QMenu(menuBar);
        menuSave_File->setObjectName(QString::fromUtf8("menuSave_File"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuFonts = new QMenu(menuSettings);
        menuFonts->setObjectName(QString::fromUtf8("menuFonts"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSave_File->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuSave_File->addAction(actionFind);
        menuSave_File->addSeparator();
        menuSave_File->addAction(actionSave);
        menuSave_File->addAction(actionOpen);
        menuSave_File->addAction(actionCreate);
        menuSave_File->addAction(actionClear);
        menuSettings->addAction(menuFonts->menuAction());
        menuFonts->addAction(action8);
        menuFonts->addAction(action9);
        menuFonts->addAction(action10);
        menuFonts->addAction(action11);
        menuFonts->addAction(action12);
        menuHelp->addAction(actionVersion_2);
        menuHelp->addAction(actionQt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Sequoia", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open ", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        actionCreate->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        action8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        action9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        action10->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        action11->setText(QCoreApplication::translate("MainWindow", "11", nullptr));
        action12->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        actionDark->setText(QCoreApplication::translate("MainWindow", "Dark", nullptr));
        actionLight->setText(QCoreApplication::translate("MainWindow", "Light", nullptr));
        actionFind->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        actionVersion->setText(QCoreApplication::translate("MainWindow", "Version", nullptr));
        actionVersion_2->setText(QCoreApplication::translate("MainWindow", "Version", nullptr));
        actionQt->setText(QCoreApplication::translate("MainWindow", "Qt", nullptr));
        text->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Droid Sans','DejaVu Sans Mono'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans Serif'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        command->setText(QCoreApplication::translate("MainWindow", "/home/", nullptr));
        menuSave_File->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        menuFonts->setTitle(QCoreApplication::translate("MainWindow", "Fonts", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
