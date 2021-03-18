/**
 * @file stadium.h
 */

#ifndef STADIUM_H
#define STADIUM_H

#include <QString>
#include <QTextStream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

/**
 * @brief The conf enum
 * @details enum representing the 2 possible conferences
 */
enum conf {Nat_FB_Conf, AM_FB_Conf, nullConf};
/**
 * @brief The divi enum
 * @details enum representing the 8 possible divisions
 */
enum divi{NFC_North, NFC_South, NFC_East, NFC_West, AFC_North, AFC_South, AFC_East, AFC_West, nullDivi};
/**
 * @brief The surf enum
 * @details enum representing the 9 possible field surface types
 */
enum surf {Bermuda, FieldTurf_Classic, FieldTurf_Rev, UBU_Sports, Ken_Blu, Hellas, Plat_Pas, Desso, nullSurf};
/**
 * @brief The roof enum
 * @details enum representing the 3 possible roof types
 */
enum roof {open, retrac, fix, nullRoof};


/**
 * @class Stadium
 * @brief Class which stores all 9 data members for every stadium
 */
class Stadium
{
public:
    /**
     * @brief Stadium
     */
    Stadium();
    /**
     * @brief ~Stadium
     */
    ~Stadium(){}
    /**
     * @brief Stadium copy constructor
     * @param stadIn
     */
    Stadium(const Stadium& stadIn);
    /**
     * @brief operator = overloader
     * @param stadIn
     */
    void operator = (const Stadium& stadIn);
    /**
     * @brief getStadium
     * @param file
     * @return
     */
    bool getStadium(std::ifstream& file);
    /**
     * @brief -addStadium member function
     * @param[in] teamIn - QString representing team name
     * @param[in] stadiumIn - QString representing stadium name
     * @param[in] seatIn - unsigned int representing seating capacity
     * @param[in] locIn - QString representing location
     * @param[in] confIn - enum representing conference
     * @param[in] divIn - enum representing division
     * @param[in] surfIn - enum representing surface type
     * @param[in] roofIn - enum representing roof type
     * @param[in] dateIn - short int representing date opened
     */
    void addStadium(QString teamIn, QString stadiumIn, unsigned int seatIn,
                    QString locIn, conf confIn, divi divIn, surf surfIn, roof roofIn, short int dateIn);
    /**
     * @brief -sendStadium member function
     * @param[in] teamIn - QString representing team name
     * @param[in] stadiumIn - QString representing stadium name
     * @param[in] seatIn - QString representing seating capacity
     * @param[in] locIn - QString representing location
     * @param[in] confIn - QString representing conference
     * @param[in] divIn - QString representing division
     * @param[in] surfIn - QString representing surface type
     * @param[in] roofIn - QString representing roof type
     * @param[in] dateIn - QString representing date opened
     */
    void sendStadium(QString& teamIn, QString& stadiumIn, QString& seatIn,
                     QString& locIn, QString& confIn, QString& divIn, QString& surfIn, QString& roofIn, QString& dateIn);
    /**
     * @brief sendTeam
     * @return
     */
    QString sendTeam() {return teamName;}
    /**
     * @brief sendStadium
     * @return
     */
    QString sendStadium() {return stadiumName;}
    /**
     * @brief sendSeat
     * @return
     */
    unsigned int sendSeat() {return seatCap;}
    /**
     * @brief sendLoc
     * @return
     */
    QString sendLoc() {return location;}
    /**
     * @brief sendConf
     * @return
     */
    QString sendConf() {return EnumToQString(conference);}
    /**
     * @brief sendDiv
     * @return
     */
    QString sendDiv() {return EnumToQString(division);}
    /**
     * @brief sendSurf
     * @return
     */
    QString sendSurf() {return EnumToQString(surfaceType);}
    /**
     * @brief sendRoof
     * @return
     */
    QString sendRoof() {return EnumToQString(roofType);}
    /**
     * @brief sendDate
     * @return
     */
    short int sendDate() {return dateOpen;}
    /**
     * @brief -overloaded EnumToQString member function
     * @param[in] teamIn - enum representing conference
     * @param[out] Conference String - returns string represented by the enum
     */
    QString EnumToQString(const conf);
    /**
     * @brief -overloaded EnumToQString member function
     * @param[in] teamIn - enum representing division
     * @param[out] Division String - returns string represented by the enum
     */
    QString EnumToQString(const divi);
    /**
     * @brief -overloaded EnumToQString member function
     * @param[in] teamIn - enum representing surface type
     * @param[out] Surface Type String - returns string represented by the enum
     */
    QString EnumToQString(const surf);
    /**
     * @brief -overloaded EnumToQString member function
     * @param[in] teamIn - enum representing roof type
     * @param[out] Roof Type String - returns string represented by the enum
     */
    QString EnumToQString(const roof);
private:
    QString teamName;       /** @var -the team name stored as a string*/
    QString stadiumName;    /** @var -the stadium name stored as a string*/
    unsigned int seatCap;   /** @var -the seating capacity stored as an unsigned int */
    QString location;       /** @var -the location of the stadium stored as a QString */
    conf conference;        /** @var -the conference represented as an enum */
    divi division;          /** @var -the division represented as an enum */
    surf surfaceType;       /** @var -the surface type represented as an enum */
    roof roofType;          /** @var -the roof type represented as an enum */
    short int dateOpen;     /** @var -the opening date of the stadium stored as a short int */
};
/*---------------------------------------------------------------------------------*/

/**
 * @brief popVector
 * @details populates a vectore of stadium objects with the csv file
 * @param list
 */
void popVector(std::vector<Stadium>& list);


/**
 * @brief searchStadiums
 * @details -searches through the stadium vector for fields that match the passed
 * string and populate a new vector thats passed to the table display function
*/
bool searchStadiums(Stadium StadSearch, const QString &arg1);

/**
 * @brief sortStadiums
 * @details creates new vector of objects sorted by the passed in field
 * @param StadSort
 * @param field
 */
void sortStadiums(std::vector<Stadium> &StadSort, int field);

/**
 * @brief sortName
 * @details called by the sortStadiums function, sorts by team name
 * @param std::vector<Stadium> &StadSort
 */
void sortName(std::vector<Stadium> &StadSort);
/**
 * @brief sortStad
 * @details called by the sortStadiums function, sorts by stadium name
 * @param std::vector<Stadium> &StadSort
 */
void sortStad(std::vector<Stadium> &StadSort);
/**
 * @brief sortSeat
 * @details called by the sortStadiums function, sorts by seat capacity
 * @param std::vector<Stadium> &StadSort
 */
void sortSeat(std::vector<Stadium> &StadSort);
/**
 * @brief sortLoc
 * @details called by the sortStadiums function, sorts by location
 * @param std::vector<Stadium> &StadSort
 */
void sortLoc(std::vector<Stadium> &StadSort);
/**
 * @brief sortConf
 * @details called by the sortStadiums function, sorts by conferance
 * @param std::vector<Stadium> &StadSort
 */
void sortConf(std::vector<Stadium> &StadSort);
/**
 * @brief sortDiv
 * @details called by the sortStadiums function, sorts by division
 * @param std::vector<Stadium> &StadSort
 */
void sortDiv(std::vector<Stadium> &StadSort);
/**
 * @brief sortSurf
 * @details called by the sortStadiums function, sorts by surface type
 * @param std::vector<Stadium> &StadSort
 */
void sortSurf(std::vector<Stadium> &StadSort);
/**
 * @brief sortRoof
 * @details called by the sortStadiums function, sorts by roof type
 * @param std::vector<Stadium> &StadSort
 */
void sortRoof(std::vector<Stadium> &StadSort);
/**
 * @brief sortDate
 * @details called by the sortStadiums function, sorts by date debuted
 * @param std::vector<Stadium> &StadSort
 */
void sortDate(std::vector<Stadium> &StadSort);

#endif // STADIUM_H
