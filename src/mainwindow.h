#include <iostream>
#include <fstream>
#include <QMessageBox>
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QSettings>
#include <iostream>

#include "workspace.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setFont(int size);
    ~MainWindow();

private slots:
    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionClear_triggered();

    void on_actionCreate_triggered();

    void on_action8_triggered();

    void on_action9_triggered();

    void on_action10_triggered();

    void on_action11_triggered();

    void on_action12_triggered();

    void on_actionFind_triggered();

    void on_actionVersion_2_triggered();

    void on_actionQt_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void on_tabWidget_currentChanged(int index);

    void on_actionDefault_triggered();

    void on_actionDark_2_triggered();

    void on_actionLight_2_triggered();

    void on_actionBold_triggered();

    void on_actionItalic_triggered();

    void on_actionDefault_3_triggered();

    void on_actionLeft_triggered();

    void on_actionCenter_triggered();

    void on_actionRight_triggered();

    void on_actionLeft_2_triggered();

    void on_actionCenter_2_triggered();

    void on_actionRight_2_triggered();

    void on_actionBold_2_triggered();

    void on_actionItalic_2_triggered();

    void on_actionDefault_4_triggered();

    void on_actionFind_2_triggered();

    void on_actionSave_2_triggered();

    void on_actionOpen_2_triggered();

    void on_actionClear_2_triggered();

    void on_actionCreate_2_triggered();

    void on_actionPlus_Font_triggered();

    void on_actionMinus_Font_triggered();

    void on_action13_triggered();

    void on_action14_triggered();

    void on_action15_triggered();

    void on_action16_triggered();

    void on_actionApply_ToolBar_triggered();

    // Settings
    void loadSettings();
    void saveSettings();

    void on_actionContrast_triggered();

private:
    Ui::MainWindow *ui;
    QSettings *st;
};

#endif // MAINWINDOW_H
