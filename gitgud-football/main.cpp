#include "mainwindowclassic.h"
#include "stadium.h"
#include <QApplication>
#include <iostream>
#include <vector>
#include <globals.h>


std::vector<Stadium> Stadiums;
QString loginInfo[5][2] = {{"Seanz", "pass1"} , {"Ranz", "pass2"} , {"Grantz", "pass3"} , {"Zachz", "pass4"} , {"Alexz", "pass5"}};

bool login = false;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    popVector(Stadiums);

    MainWindowClassic w;
    w.show();
    return a.exec();
}
