#include "mainwindow.h"
#include "ui_mainwindow.h"

QString alerts[5] = {"File can't be opened!", "File saved", "File opened", "File created", "Error"};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

files::files() : fontSize(12), nowFontSize(12), prevIndex(0) { }
files * getFile = new files();
files::~files() { delete getFile; }

theme::theme() : itsTheme("Default"), nowTheme("Default") { }
theme * getTheme = new theme();
theme::~theme()  { delete getTheme; }

void MainWindow::on_actionSave_triggered()
{
    QString CommandText = ui->command->text();
    std::string stdCommandText = CommandText.toStdString();
    getFile->fout.open(stdCommandText);
    if (!getFile->fout.is_open()) {
        ui->statusBar->showMessage(alerts[0]);
    }
    else {
        QString TextToSave = ui->text->toPlainText();
        std::string stdTextToSave = TextToSave.toStdString();
        getFile->fout << stdTextToSave;
        ui->statusBar->showMessage(alerts[1]);
    }
    getFile->fout.close();
}

void MainWindow::on_actionOpen_triggered()
{
    QString CommandText = ui->command->text();
    std::string stdCommandText = CommandText.toStdString();
    ui->tabWidget->setCurrentIndex(0);
    getFile->fin.open(stdCommandText);
    if (!getFile->fin.is_open()) {
        ui->statusBar->showMessage(alerts[0]);
    }
    else {
        ui->statusBar->showMessage(alerts[2]);
        ui->tabWidget->addTab(new QWidget(), QString(ui->command->text()));
        ui->tabWidget->count() +1;
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()+1);
        std::string stdTextToOpen;
        ui->text->setText("");
        while (getline(getFile->fin, stdTextToOpen)) {
            QString TextToOpen = QString::fromStdString(stdTextToOpen);
            ui->text->append(TextToOpen);
        }
    }
    getFile->fin.close();
}

void MainWindow::on_actionClear_triggered()
{
    ui->text->setText("");
}

void MainWindow::on_actionCreate_triggered()
{
    QString CommandText = ui->command->text();
    std::string stdCommandText = CommandText.toStdString();
    getFile->fout.open(stdCommandText);
    QString inCommand = ui->command->text();
    if (!getFile->fout.is_open()) {
        ui->statusBar->showMessage(alerts[4]);
    }
    if (inCommand == "") {
        ui->statusBar->showMessage(alerts[4]);
    }
    else {
        ui->statusBar->showMessage(alerts[3]);
    }
    getFile->fout.close();
}

void MainWindow::on_action8_triggered()
{
    getFile->fontSize = 8;
    if (getFile->nowFontSize == getFile->fontSize) {
        QMessageBox::critical(this, "Alert", "You already have installed this font!");
    }
    ui->text->setFontPointSize(getFile->fontSize);
    getFile->nowFontSize = 8;
}

void MainWindow::on_action9_triggered()
{
    getFile->fontSize = 9;
    if (getFile->nowFontSize == getFile->fontSize) {
        QMessageBox::critical(this, "Alert", "You already have installed this font!");
    }
    ui->text->setFontPointSize(getFile->fontSize);
    getFile->nowFontSize = 9;
}

void MainWindow::on_action10_triggered()
{
    getFile->fontSize = 10;
    if (getFile->nowFontSize == getFile->fontSize) {
        QMessageBox::critical(this, "Alert", "You already have installed this font!");
    }
    ui->text->setFontPointSize(getFile->fontSize);
    getFile->nowFontSize = 10;
}

void MainWindow::on_action11_triggered()
{
    getFile->fontSize = 11;
    if (getFile->nowFontSize == getFile->fontSize) {
        QMessageBox::critical(this, "Alert", "You already have installed this font!");
    }
    ui->text->setFontPointSize(getFile->fontSize);
    getFile->nowFontSize = 11;
}

void MainWindow::on_action12_triggered()
{
    getFile->fontSize = 12;
    if (getFile->nowFontSize == getFile->fontSize) {
        QMessageBox::critical(this, "Alert", "You already have installed this font!");
    }
    ui->text->setFontPointSize(getFile->fontSize);
    getFile->nowFontSize = 12;
}

void MainWindow::on_actionFind_triggered()
{
    getFile->find_cross = QFileDialog::getOpenFileName(this, "Find file", "/home/");
    ui->command->setText(getFile->find_cross);
}

void MainWindow::on_actionVersion_2_triggered()
{
    QMessageBox::about(this, "Sequoia info", "Sequoia Redactor v1.3");
}

void MainWindow::on_actionQt_triggered()
{
    QMessageBox::aboutQt(this, "Sequoia and Qt");
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    QString tabText = ui->tabWidget->tabText(index);
    std::string stdTabText = tabText.toStdString();
    ui->tabWidget->setCurrentIndex(0);
    if (tabText != "Untitled") {
        ui->tabWidget->removeTab(index);
        ui->tabWidget->count() -1;
    }
    if (tabText == "Untitled") {
        QMessageBox::critical(this, "Error", "This tab can't be closed.");
    }
    if (ui->tabWidget->count() == 0) {
        QMessageBox::critical(this, "Error", "Last tab");
        ui->tabWidget->addTab(new QWidget(), QString("Untitled"));
        ui->tabWidget->count() +1;
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    QString TabText = ui->tabWidget->tabText(index);
    std::string stdTabText = TabText.toStdString();
    QString prevTabText = ui->tabWidget->tabText(getFile->prevIndex);
    std::string stdPrevTabText = prevTabText.toStdString();

    getFile->fout.open(stdPrevTabText);
    if (!getFile->fout.is_open()) {
        ui->statusBar->showMessage(alerts[0]);
    }
    else {
        QString TextToSave = ui->text->toPlainText();
        std::string stdTextToSave = TextToSave.toStdString();
        if (stdPrevTabText == "Untitled") {
            stdTextToSave = "";
        }
        getFile->fout << stdTextToSave;
        ui->statusBar->showMessage(alerts[1]);
    }
    getFile->fout.close();

    getFile->prevIndex = ui->tabWidget->currentIndex();

    getFile->fin.open(stdTabText);
    if (!getFile->fin.is_open()) {
        ui->statusBar->showMessage(alerts[0]);
    }
    else {
        std::string stdTextToOpen;
        ui->text->setText("");
        while (getline(getFile->fin, stdTextToOpen)) {
            QString TextToOpen = QString::fromStdString(stdTextToOpen);
            ui->text->append(TextToOpen);
        }
    }
    getFile->fin.close();
}

void MainWindow::on_actionDefault_triggered()
{
    getTheme->itsTheme = "Default";
    if (getTheme->nowTheme == getTheme->itsTheme) {
        QMessageBox::critical(this, "Alert", "You already have installed this theme!");
    }
    ui->centralWidget->setStyleSheet("");
    ui->statusBar->setStyleSheet("");
    ui->menuBar->setStyleSheet("");
    getTheme->nowTheme = "Default";
}

void MainWindow::on_actionDark_2_triggered()
{
    getTheme->itsTheme = "Dark";
    if (getTheme->nowTheme == getTheme->itsTheme) {
        QMessageBox::critical(this, "Alert", "You already have installed this theme!");
    }
    ui->centralWidget->setStyleSheet("background-color: #31363b; color: white;");
    ui->statusBar->setStyleSheet("background-color: #31363b; color: white;");
    ui->menuBar->setStyleSheet("background-color: #31363b; color: white;");
    getTheme->nowTheme = "Light";
}

void MainWindow::on_actionLight_2_triggered()
{
    getTheme->itsTheme = "Light";
    if (getTheme->nowTheme == getTheme->itsTheme) {
        QMessageBox::critical(this, "Alert", "You already have installed this theme!");
    }
    ui->centralWidget->setStyleSheet("background-color: white; color: black;");
    ui->statusBar->setStyleSheet("background-color: white; color: black;");
    ui->menuBar->setStyleSheet("background-color: white; color: black;");
    getTheme->nowTheme = "Light";
}
