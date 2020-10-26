#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workspace.h"
#include "workspace.cpp"

QString alerts[5] = {"File can't be opened!", "File saved", "File opened", "File created", "Error"};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    st(new QSettings("Sequoia", "sequoia-redactor"))
{
    ui->setupUi(this);
    loadSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

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
        ui->tabWidget->addTab(new QWidget(), QString(CommandText));
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

void MainWindow::setFont(int size) {
    getFile->fontSize = size;
    if (getFile->nowFontSize == getFile->fontSize) {
        QMessageBox::critical(this, "Alert", "You already have installed this font!");
    }
    ui->text->setFontPointSize(getFile->fontSize);
    getFile->nowFontSize = size;
}

void MainWindow::on_action8_triggered()
{
    this->setFont(8);
}

void MainWindow::on_action9_triggered()
{
    this->setFont(9);
}

void MainWindow::on_action10_triggered()
{
   this->setFont(10);
}

void MainWindow::on_action11_triggered()
{
    this->setFont(11);
}

void MainWindow::on_action12_triggered()
{
    this->setFont(12);
}

void MainWindow::on_action13_triggered()
{
    this->setFont(13);
}

void MainWindow::on_action14_triggered()
{
    this->setFont(14);
}

void MainWindow::on_action15_triggered()
{
    this->setFont(15);
}

void MainWindow::on_action16_triggered()
{
    this->setFont(16);
}

void MainWindow::on_actionFind_triggered()
{
    getFile->find_cross = QFileDialog::getOpenFileName(this, "Find file", "/home/");
    ui->command->setText(getFile->find_cross);
}

void MainWindow::on_actionVersion_2_triggered()
{
    QMessageBox::about(this, "Info", "Sequoia Redactor v1.5");
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
    ui->text->toPlainText();
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
    ui->toolBar->setStyleSheet("");
    ui->text->setStyleSheet("");
    ui->command->setStyleSheet("");
    getTheme->nowTheme = "Default";
    saveSettings();
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
    ui->toolBar->setStyleSheet("background-color: #31363b; color: white;");
    ui->text->setStyleSheet("background-color: #31363b; color: white;");
    ui->command->setStyleSheet("background-color: #31363b; color: white;");
    getTheme->nowTheme = "Dark";
    saveSettings();
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
    ui->toolBar->setStyleSheet("background-color: white; color: black;");
    ui->text->setStyleSheet("background-color: white; color: black;");
    ui->command->setStyleSheet("background-color: white; color: black;");
    getTheme->nowTheme = "Light";
    saveSettings();
}

void MainWindow::on_actionBold_triggered()
{
    ui->text->setFontWeight(600);
}

void MainWindow::on_actionItalic_triggered()
{
    ui->text->setFontItalic(true);
}

void MainWindow::on_actionDefault_3_triggered()
{
    ui->text->setFontWeight(0);
    ui->text->setFontItalic(false);
}

void MainWindow::on_actionLeft_triggered()
{
    ui->text->setAlignment(Qt::AlignLeft);
}

void MainWindow::on_actionCenter_triggered()
{
    ui->text->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_actionRight_triggered()
{
    ui->text->setAlignment(Qt::AlignRight);
}

void MainWindow::on_actionLeft_2_triggered()
{
    on_actionLeft_triggered();
}

void MainWindow::on_actionCenter_2_triggered()
{
    on_actionCenter_triggered();
}

void MainWindow::on_actionRight_2_triggered()
{
    on_actionRight_triggered();
}

void MainWindow::on_actionBold_2_triggered()
{
    on_actionBold_triggered();
}

void MainWindow::on_actionItalic_2_triggered()
{
    on_actionItalic_triggered();
}

void MainWindow::on_actionDefault_4_triggered()
{
    on_actionDefault_3_triggered();
}

void MainWindow::on_actionFind_2_triggered()
{
    on_actionFind_triggered();
}

void MainWindow::on_actionSave_2_triggered()
{
    on_actionSave_triggered();
}

void MainWindow::on_actionOpen_2_triggered()
{
    on_actionOpen_triggered();
}

void MainWindow::on_actionClear_2_triggered()
{
    on_actionClear_triggered();
}

void MainWindow::on_actionCreate_2_triggered()
{
    on_actionCreate_triggered();
}

void MainWindow::on_actionPlus_Font_triggered()
{
    if (getFile->nowFontSize == 16) {
        getFile->nowFontSize--;
        getFile->fontSize--;
    }
    getFile->fontSize++;
    ui->text->setFontPointSize(getFile->fontSize);
    getFile->nowFontSize++;
}

void MainWindow::on_actionMinus_Font_triggered()
{
    if (getFile->nowFontSize == 8) {
        getFile->nowFontSize++;
        getFile->fontSize++;
    }
    getFile->fontSize--;
    ui->text->setFontPointSize(getFile->fontSize);
    getFile->nowFontSize--;
}

void MainWindow::on_actionApply_ToolBar_triggered()
{
    st->beginGroup("toolBar");
    if (ui->actionAlign_Actions->isChecked()) {
        ui->actionLeft_2->setVisible(true);
        ui->actionCenter_2->setVisible(true);
        ui->actionRight_2->setVisible(true);
        st->setValue("align_actions", true);
    }
    else {
        ui->actionLeft_2->setVisible(false);
        ui->actionCenter_2->setVisible(false);
        ui->actionRight_2->setVisible(false);
        st->setValue("align_actions", false);
    }
    if (ui->actionText_Styles->isChecked()) {
        ui->actionBold_2->setVisible(true);
        ui->actionItalic_2->setVisible(true);
        ui->actionDefault_4->setVisible(true);
        st->setValue("text_styles", true);
    }
    else {
        ui->actionBold_2->setVisible(false);
        ui->actionItalic_2->setVisible(false);
        ui->actionDefault_4->setVisible(false);
        st->setValue("text_styles", false);
    }
    if (ui->actionClear_Area->isChecked()) {
        ui->actionClear_2->setVisible(true);
        st->setValue("clear_area", true);
    }
    else {
        ui->actionClear_2->setVisible(false);
        st->setValue("clear_area", false);
    }
    if (ui->actionFile_Actions->isChecked()) {
        ui->actionSave_2->setVisible(true);
        ui->actionOpen_2->setVisible(true);
        ui->actionCreate_2->setVisible(true);
        ui->actionFind_2->setVisible(true);
        st->setValue("file_actions", true);
    }
    else {
        ui->actionSave_2->setVisible(false);
        ui->actionOpen_2->setVisible(false);
        ui->actionCreate_2->setVisible(false);
        ui->actionFind_2->setVisible(false);
        st->setValue("file_actions", false);
    }
    if (ui->actionFont_Work->isChecked()) {
        ui->actionPlus_Font->setVisible(true);
        ui->actionMinus_Font->setVisible(true);
        st->setValue("font_work", true);
    }
    else {
        ui->actionPlus_Font->setVisible(false);
        ui->actionMinus_Font->setVisible(false);
        st->setValue("font_work", false);
    }
    st->endGroup();
}

void MainWindow::loadSettings() {
    st->beginGroup("theme");
    if (st->value("theme", getTheme->itsTheme).toString() == "Default") {
        on_actionDefault_triggered();
    }
    if (st->value("theme", getTheme->itsTheme) == "Dark") {
        on_actionDark_2_triggered();
    }
    if (st->value("theme", getTheme->itsTheme) == "Light") {
        on_actionLight_2_triggered();
    }
    if (st->value("theme", getTheme->itsTheme) == "Contrast") {
        on_actionContrast_triggered();
    }
    st->endGroup();
    st->beginGroup("toolBar");
    if (st->value("align_actions").toBool() == true) {
        ui->actionAlign_Actions->setChecked(true);
        ui->actionLeft_2->setVisible(true);
        ui->actionCenter_2->setVisible(true);
        ui->actionRight_2->setVisible(true);
    } else {
        ui->actionAlign_Actions->setChecked(false);
        ui->actionLeft_2->setVisible(false);
        ui->actionCenter_2->setVisible(false);
        ui->actionRight_2->setVisible(false);
    }
    if (st->value("text_styles").toBool() == true) {
        ui->actionText_Styles->setChecked(true);
        ui->actionBold_2->setVisible(true);
        ui->actionItalic_2->setVisible(true);
        ui->actionDefault_4->setVisible(true);
    } else {
        ui->actionText_Styles->setChecked(false);
        ui->actionBold_2->setVisible(false);
        ui->actionItalic_2->setVisible(false);
        ui->actionDefault_4->setVisible(false);
    }
    if (st->value("file_actions").toBool() == true) {
        ui->actionFile_Actions->setChecked(true);
        ui->actionSave_2->setVisible(true);
        ui->actionOpen_2->setVisible(true);
        ui->actionCreate_2->setVisible(true);
        ui->actionFind_2->setVisible(true);
    } else {
        ui->actionFile_Actions->setChecked(false);
        ui->actionSave_2->setVisible(false);
        ui->actionOpen_2->setVisible(false);
        ui->actionCreate_2->setVisible(false);
        ui->actionFind_2->setVisible(false);
    }
    if (st->value("clear_area").toBool() == true) {
        ui->actionClear_Area->setChecked(true);
        st->setValue("clear_area", true);
    } else {
        ui->actionClear_Area->setChecked(false);
        st->setValue("clear_area", false);
    }
    if (st->value("font_work").toBool() == true) {
        ui->actionFont_Work->setChecked(true);
        ui->actionPlus_Font->setVisible(true);
        ui->actionMinus_Font->setVisible(true);
    } else {
        ui->actionFont_Work->setChecked(false);
        ui->actionPlus_Font->setVisible(false);
        ui->actionMinus_Font->setVisible(false);
    }
    st->endGroup();
}

void MainWindow::saveSettings() {
    st->beginGroup("theme");
    st->setValue("theme", getTheme->itsTheme);
    st->endGroup();
}

void MainWindow::on_actionContrast_triggered()
{
    getTheme->itsTheme = "Contrast";
    if (getTheme->nowTheme == getTheme->itsTheme) {
        QMessageBox::critical(this, "Alert", "You already have installed this theme!");
    }
    ui->centralWidget->setStyleSheet("background-color: #88a2bd; color: white;");
    ui->statusBar->setStyleSheet("background-color: #88a2bd; color: white;");
    ui->menuBar->setStyleSheet("background-color: #88a2bd; color: white;");
    ui->toolBar->setStyleSheet("background-color: #88a2bd; color: white;");
    ui->text->setStyleSheet("background-color: #afbac5; color: black;");
    ui->command->setStyleSheet("background-color: #afbac5; color: black;");
    getTheme->nowTheme = "Contrast";
    saveSettings();
}
