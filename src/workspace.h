#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "mainwindow.h"

class files {
public:
    std::ofstream fout;
    std::ifstream fin;
    int fontSize;
    int nowFontSize;
    QString find_cross;
    int prevIndex;
    int index;
    QFileInfo *doc;
    files();
    ~files();
};

class theme {
public:
    QString itsTheme;
    QString nowTheme;
    theme();
    ~theme();
};

#endif // WORKSPACE_H
