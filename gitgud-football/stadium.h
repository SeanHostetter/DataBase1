#ifndef STADIUM_H
#define STADIUM_H

#include <QString>
#include <QTextStream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

enum conf {Nat_FB_Conf, AM_FB_Conf, nullConf};
enum divi{NFC_North, NFC_South, NFC_East, NFC_West, AFC_North, AFC_South, AFC_East, AFC_West, nullDivi};
enum surf {Bermuda, FieldTurf_Classic, FieldTurf_Rev, UBU_Sports, Ken_Blu, Hellas, Plat_Pas, Desso, nullSurf};
enum roof {open, retrac, fix, nullRoof};



//class stadium
//object that holds values from NFL Information database
//some values are enums to tighten error handling and user ease of use
class Stadium
{
public:
    Stadium();
    ~Stadium(){}
    Stadium(const Stadium& stadIn);
    void operator = (const Stadium& stadIn);
    bool getStadium(std::ifstream& file);
    void addStadium(QString teamIn, QString stadiumIn, unsigned int seatIn, QString locIn, conf confIn, divi divIn, surf surfIn, roof roofIn, short int dateIn);
    void sendStadium(QString& teamIn, QString& stadiumIn, QString& seatIn, QString& locIn, QString& confIn, QString& divIn, QString& surfIn, QString& roofIn, QString& dateIn);
    QString EnumToQString(const conf);
    QString EnumToQString(const divi);
    QString EnumToQString(const surf);
    QString EnumToQString(const roof);
private:
    QString teamName;
    QString stadiumName;
    unsigned int seatCap;
    QString location;
    conf conference;             //enum
    divi division;               //enum
    surf surfaceType;            //enum
    roof roofType;               //enum
    short int dateOpen;
};

void popVector(std::vector<Stadium>& list);
bool searchStadiums(Stadium StadSearch, const QString &arg1);



#endif // STADIUM_H
