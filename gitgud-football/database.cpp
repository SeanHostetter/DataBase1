#include "database.h"
#include "ui_database.h"
#include "database.h"
#include "help.h"
#include "stadium.h"
#include "addstadium.h"

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMainWindow>
#include <fstream>
#include <QStandardItem>
#include <QLineEdit>
//#include "globals.h"

extern std::vector<Stadium> Stadiums;
extern bool login;

DataBase::DataBase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataBase)
{
    ui->setupUi(this);
    tableWidgetDisplay(Stadiums);

    //if user is not logged in, they don't have the ability to edit the table
    if(login){
        this->ui->AddNewPushButton->setEnabled(true);
        this->ui->pushButton_2->setEnabled(true);
    }else{
        this->ui->AddNewPushButton->setEnabled(false);
        this->ui->pushButton_2->setEnabled(false);
    }
}

DataBase::~DataBase()
{
    delete ui;
}

void DataBase::on_HelpPushButton_clicked()
{
    Help openHelp;
    openHelp.setModal(true);
    openHelp.exec();
}

//sort function implemented based on returned value of combo box
//needs implementation
void DataBase::on_SortByComboBox_activated(const QString &arg1)
{

}

//displays and formats table in database window
//populates table from vector of stadium objects which is passed in
void DataBase::tableWidgetDisplay(std::vector<Stadium>& StadList){

    QString teamIn;
    QString stadiumIn;
    QString seatIn;
    QString locIn;
    QString confIn;
    QString divIn;
    QString surfIn;
    QString roofIn;
    QString dateIn;
    QTableWidgetItem* item;

    QTableWidget* table;
    table = this->ui->tableWidget;

    if(!login)            //table not editable if you are not logged in
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    table->setRowCount(StadList.size());   //matches number of rows in list of Stadium Objects
    table->setColumnCount(9);          //9 colums, 1 for each Stadium member

    QStringList hLabels;
    hLabels << "Team Name" << "Stadium Name" << "Seating Capacity" << "Location" << "Conference" << "Division" << "Surface Type" << "Stadium Roof Type" << "Date Opened";
    table->setHorizontalHeaderLabels(hLabels);

    for(int i = 0; i < table->rowCount(); i++){
        StadList[i].sendStadium(teamIn, stadiumIn, seatIn, locIn, confIn, divIn, surfIn, roofIn, dateIn);
        for(int j = 0; j < table->columnCount(); j++){
            item = new QTableWidgetItem;
            switch(j){
                case 0: item->setText(teamIn);    break;
                case 1: item->setText(stadiumIn); break;
                case 2: item->setText(seatIn);    break;
                case 3: item->setText(locIn);     break;
                case 4: item->setText(confIn);    break;
                case 5: item->setText(divIn);     break;
                case 6: item->setText(surfIn);    break;
                case 7: item->setText(roofIn);    break;
                case 8: item->setText(dateIn);    break;
            }
            table->setItem(i, j, item);
        }
    }
    //sets each row of table to alternate colors
    table->setAlternatingRowColors(true);

    //stretching each column to equal to fit or a fixed value depending on needed size
    table->horizontalHeader()->resizeSection(0, 170);
    table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    table->horizontalHeader()->resizeSection(3, 190);
    table->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    table->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);
    table->horizontalHeader()->resizeSection(7, 150);
}

//every time seach bar line edit is changed, this is called
//calls searchStadiums function, assigns every matching object to new vector
//calls tableWidgetDisplay function with passed in stadium object vector to update the table live
void DataBase::on_searchLineEdit_textChanged(const QString &arg1)
{
    std::vector<Stadium> searchList;
    for(unsigned long long i = 0; i < Stadiums.size(); i++){
        if(searchStadiums(Stadiums[i], arg1)){
            searchList.push_back(Stadiums[i]);
        }
    }
    tableWidgetDisplay(searchList);
}

//opens the addStadium window
//after window is closed, it passes in the update stadium vector to the table display function
void DataBase::on_AddNewPushButton_clicked()
{
    AddStadium openAddStadium;
    openAddStadium.setModal(true);
    openAddStadium.exec();
    tableWidgetDisplay(Stadiums);
}

//save table
//the user may want to save the update table, this is called and reads stadium object vector back into tsv file
//closes database window
void DataBase::on_pushButton_2_clicked()
{
    QString teamIn;
    QString stadiumIn;
    QString seatIn;
    QString locIn;
    QString confIn;
    QString divIn;
    QString surfIn;
    QString roofIn;
    QString dateIn;

    std::ofstream file;
    file.open("NFL Information.tsv");

    for(unsigned long long int i = 0; i < Stadiums.size(); i++){
        Stadiums[i].sendStadium(teamIn, stadiumIn, seatIn, locIn, confIn, divIn, surfIn, roofIn, dateIn);
        file << teamIn.QString::toStdString() << "\t"
             << stadiumIn.QString::toStdString() << "\t"
             << "\"" << seatIn.QString::toStdString() << "\"" << "\t"
             << "\"" << locIn.QString::toStdString() << "\"" << "\t"
             << confIn.QString::toStdString() << "\t"
             << divIn.QString::toStdString() << "\t"
             << surfIn.QString::toStdString() << "\t"
             << roofIn.QString::toStdString() << "\t"
             << dateIn.QString::toStdString();
        if(i != (Stadiums.size() - 1))
             file << "\n";
    }
    this->close();
}
