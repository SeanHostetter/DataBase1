#include "stadium.h"
#include <qchar.h>
#include <QDebug>

//Stadium class constructor
//initializes empty strings, ints to zero, and enums to their null values to throw errors if necissary
Stadium::Stadium()
{
    teamName = "";
    stadiumName = "";
    seatCap = 0;
    location = "";
    conference = nullConf;             //enum
    division = nullDivi;               //enum
    surfaceType = nullSurf;            //enum
    roofType = nullRoof;               //enum
    dateOpen = 0;
}

//Stadium class assignment constructor
//assigns values of passed in Stadium to current Stadium object
Stadium::Stadium(const Stadium& stadIn){

    teamName = stadIn.teamName;
    stadiumName = stadIn.stadiumName;
    seatCap = stadIn.seatCap;
    location = stadIn.location;
    conference = stadIn.conference;             //enum
    division = stadIn.division;               //enum
    surfaceType = stadIn.surfaceType;            //enum
    roofType = stadIn.roofType;               //enum
    dateOpen = stadIn.dateOpen;
}

//Stadium class overloaded assignment operator
//possibly unnecissary
void Stadium::operator = (const Stadium& stadIn){
    teamName = stadIn.teamName;
    stadiumName = stadIn.stadiumName;
    seatCap = stadIn.seatCap;
    location = stadIn.location;
    conference = stadIn.conference;             //enum
    division = stadIn.division;               //enum
    surfaceType = stadIn.surfaceType;            //enum
    roofType = stadIn.roofType;               //enum
    dateOpen = stadIn.dateOpen;
}

//Stadium, getStadium method
//reads tsv file to QStrings representing each data member
//converts QStrings to data type of data member and removes unnecissary characters
//fstream object passed in to read to vector
//returns false if it reads faulty data
bool Stadium::getStadium(std::ifstream& file){

    std::string tempString;

    std::getline(file, tempString, '\t');
    if(tempString == "" || tempString == "\t" || tempString == "\n")    //if there is a new line with no data, don't continue reading
        return false;

    teamName = QString::fromStdString(tempString);

    std::getline(file, tempString, '\t');
    stadiumName = QString::fromStdString(tempString);

    std::getline(file, tempString, '\t');
    tempString.erase(remove(tempString.begin(), tempString.end(), '"'), tempString.end());
    tempString.erase(remove(tempString.begin(), tempString.end(), ','), tempString.end());
    if(!std::stoi(tempString, nullptr, 10)){
        seatCap = 0;
    } else {
        seatCap = std::stoi(tempString, nullptr, 10);
    }
    std::getline(file, tempString, '\t');
    tempString.erase(remove(tempString.begin(), tempString.end(), '"'), tempString.end());
    location = QString::fromStdString(tempString);

    std::getline(file, tempString, '\t');
    switch(tempString[0]){                                            //can't use string in switch, so get defining characters
      case 'N': conference = Nat_FB_Conf; break;
      case 'A': conference = AM_FB_Conf;  break;
    }

    std::getline(file, tempString, '\t');
    switch(tempString[0]){                                            //setting division enum with nested switch
      case 'N':
        switch(tempString[4]){
          case 'N': division = NFC_North; break;
          case 'S': division = NFC_South; break;
          case 'E': division = NFC_East;  break;
          case 'W': division = NFC_West;  break;
        }
        break;
      case 'A':
        switch(tempString[4]){
          case 'N': division = AFC_North; break;
          case 'S': division = AFC_South; break;
          case 'E': division = AFC_East;  break;
          case 'W': division = AFC_West;  break;
        }
        break;
    }

    std::getline(file, tempString, '\t');
    switch(tempString[0]){
      case 'B': surfaceType = Bermuda;
        break;
      case 'F': if(tempString == "FieldTurf Classic HD"){
                  surfaceType = FieldTurf_Classic;
                } else {
                  surfaceType = FieldTurf_Rev;
                }
        break;
      case 'U': surfaceType = UBU_Sports; break;
      case 'K': surfaceType = Ken_Blu;    break;
      case 'H': surfaceType = Hellas;     break;
      case 'P': surfaceType = Plat_Pas;   break;
      case 'D': surfaceType = Desso;      break;
    }

    std::getline(file, tempString, '\t');
    switch(tempString[0]){
      case 'R': roofType = retrac; break;
      case 'O': roofType = open;   break;
      case 'F': roofType = fix;    break;
    }

    std::getline(file, tempString, '\n');
    dateOpen = std::stoi(tempString, nullptr, 10);

    return true;

}

//Stadium class addStadium method
//assigns all passed variables to data members
//possibly unnecissary
void Stadium::addStadium(QString teamIn, QString stadiumIn, unsigned int seatIn, QString locIn, conf confIn, divi divIn, surf surfIn, roof roofIn, short int dateIn){

    //assigning member variables
    teamName = teamIn;
    stadiumName = stadiumIn;
    seatCap = seatIn;
    location = locIn;
    conference = confIn;
    division = divIn;
    surfaceType = surfIn;
    roofType = roofIn;
    seatCap = seatIn;
    dateOpen = dateIn;
}

//Stadium sendStadium method
//converts data members to QString and assigns them to passed in variables
//uses overloaded EnumToQString functions to convert enum values to what they represent
void Stadium::sendStadium(QString& teamIn, QString& stadiumIn, QString& seatIn, QString& locIn, QString& confIn, QString& divIn, QString& surfIn, QString& roofIn, QString& dateIn){
    teamIn = teamName;
    stadiumIn = stadiumName;
    seatIn = QString::number(seatCap);
    if(seatIn.length() > 3){                            //appends comma back to seating capacity member variable
        seatIn.insert(seatIn.length()-3, QString(","));
    }
    locIn = location;
    confIn = EnumToQString(conference);             //enum
    divIn = EnumToQString(division);                //enum
    surfIn = EnumToQString(surfaceType);            //enum
    roofIn = EnumToQString(roofType);               //enum
    dateIn = QString::number(dateOpen);
}

//Stadium class overloaded EnumToQString function
//passes in conf enum representing conference
//returns the string which the enum represents
QString Stadium::EnumToQString(const conf confIn){
    switch(confIn){
      case Nat_FB_Conf: return "National Football Conference"; break;
      case AM_FB_Conf:  return "American Football Conference"; break;
      case nullConf:    return "Error";                        break;
      default:          return "Error";                        break;
    }
    return "error";
}

//Stadium class overloaded EnumToQString function
//passes in divi enum representing division
//returns the string which the enum represents
QString Stadium::EnumToQString(const divi divIn){
    switch(divIn){
      case NFC_North: return "NFC NORTH"; break;
      case NFC_South: return "NFC South"; break;
      case NFC_East:  return "NFC East";  break;
      case NFC_West:  return "NFC West";  break;
      case AFC_North: return "AFC North"; break;
      case AFC_South: return "AFC South"; break;
      case AFC_East:  return "AFC East";  break;
      case AFC_West:  return "AFC West";  break;
      case nullDivi:  return "Error";     break;
      default:        return "Error";     break;
    }
    return "error";
}

//Stadium class overloaded EnumToQString function
//passes in surf enum representing surface type
//returns the string which the enum represents
QString Stadium::EnumToQString(const surf surfIn){
    switch(surfIn){
      case Bermuda:           return "Bermuda Grass";                               break;
      case FieldTurf_Classic: return "FieldTurf Classic HD";                        break;
      case FieldTurf_Rev:     return "FieldTurf Revolution";                        break;
      case UBU_Sports:        return "UBU Sports Speed Series S5-M Synthetic Turf"; break;
      case Ken_Blu:           return "Kentucky Bluegrass";                          break;
      case Hellas:            return "Hellas Matrix Turf";                          break;
      case Plat_Pas:          return "Platinum TE Paspalum";                        break;
      case Desso:             return "Desso GrassMaster";                           break;
      case nullSurf:          return "Error";                                       break;
      default:                return "Error";                                       break;
    }
    return "error";
}

//Stadium class overloaded EnumToQString function
//passes in roof enum representing roof type
//returns the string which the enum represents
QString Stadium::EnumToQString(const roof roofIn){
    switch(roofIn){
      case open:     return "Open";        break;
      case retrac:   return "Retractable"; break;
      case fix:      return "Fixed";       break;
      case nullRoof: return "Error";       break;
      default:       return "Error";       break;
    }
    return "error";
}

//popVector function
//function for creating list of stadium objects
//vector of stadium objects populated by tsv file
//calls getStadium function iteratively
//loop ends when file at its end or reaches invalid data
void popVector(std::vector<Stadium>& list){

    int i = 0;
    Stadium newStadium;

    std::ifstream file;
    file.open("NFL Information.tsv");  //tf? you need to copy txt file into build folder

    if(!file){
        file.close();
        std::cout << "\nerror! can't open file!\n";
    } else {
        while(!file.eof()){
            if(!newStadium.getStadium(file))
                break;
            list.push_back(newStadium);
            i++;
        }
        file.close();
    }
}

//function that searches for passed in string in passed in stadium object
//returns true if search string matches any member data
bool searchStadiums(Stadium StadSearch, const QString &arg1){
    QString teamIn;
    QString stadiumIn;
    QString seatIn;
    QString locIn;
    QString confIn;
    QString divIn;
    QString surfIn;
    QString roofIn;
    QString dateIn;

    StadSearch.sendStadium(teamIn, stadiumIn, seatIn, locIn, confIn, divIn, surfIn, roofIn, dateIn);
    if(teamIn.contains(arg1, Qt::CaseInsensitive) || stadiumIn.contains(arg1, Qt::CaseInsensitive) || seatIn.contains(arg1, Qt::CaseInsensitive)
                       || locIn.contains(arg1, Qt::CaseInsensitive) || confIn.contains(arg1, Qt::CaseInsensitive) || divIn.contains(arg1, Qt::CaseInsensitive)
                       || surfIn.contains(arg1, Qt::CaseInsensitive) || roofIn.contains(arg1, Qt::CaseInsensitive) || dateIn.contains(arg1, Qt::CaseInsensitive) )
        return true;
    else
        return false;
}
