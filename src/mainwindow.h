#include <iostream>
#include <fstream>
#include <QMessageBox>
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void openPoint(std::string &path);
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

private:
    Ui::MainWindow *ui;
};

class files {
public:
    std::ofstream fout;
    std::ifstream fin;
    int fontSize;
    int nowFontSize;
    QString find_cross;
    int prevIndex;
    int index;
    files();
    ~files();
};

class theme {
public:
    std::string itsTheme;
    std::string nowTheme;
    theme();
    ~theme();
};

#endif // MAINWINDOW_H
