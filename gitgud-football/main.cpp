/**
 * @file main.cpp
 */

#include "mainwindowclassic.h"
#include "stadium.h"
#include <QApplication>
#include <iostream>
#include <vector>
#include <globals.h>
#include <QFile>


std::vector<Stadium> Stadiums;                      /** @var - Stadiums - stores the initial populates vector of stadiums*/
std::vector<Stadium> currentStadiums = Stadiums;    /** @var - currentStadiums - stores the current populatated vector of stadiums*/
QString loginInfo[5][2] = {{"Seanz", "pass1"} , {"Ranz", "pass2"} , {"Grantz", "pass3"} , {"Zachz", "pass4"} , {"Alexz", "pass5"}}; /** @var - loginInfo - stores user login information*/
unsigned int totSeatCap = 0;                        /** @var - totSeatCap - total nfl seating capacity*/
bool expansion = false;                             /** @var - expansion - bool representing whether the "Expansion" portion of tsv has been read*/
bool expandList = false;                            /** @var - expandList - bool representing whether we want to read the "Expansion" portion of the tsv*/
bool login = false;                                 /** @var - bool representing whether or not the user has login credentials- */

QString style = "MaterialDark";        //AMOLED, Aqua, ConsoleStyle, DeepBox, ElegantDark, ExcelOffice, Geoo, MacOS, ManjaroMix, MaterialDark, Medize, NeonButtons, Obit, Ubuntu

int main(int argc, char *argv[])
{
    //myapp->stylesheet = Obit.qss
    QApplication a(argc, argv);

    QString styleName = style + ".qss";
    QFile File(styleName);
      File.open(QFile::ReadOnly);
      QString StyleSheet = QLatin1String(File.readAll());
    a.setStyleSheet(StyleSheet);


    MainWindowClassic w;
    w.show();
    return a.exec();
}
