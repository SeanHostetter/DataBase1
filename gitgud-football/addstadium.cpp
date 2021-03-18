/**
 * @file addstadium.cpp
 */

#include "addstadium.h"
#include "database.h"
#include "ui_addstadium.h"
#include <QSpinBox>

extern std::vector<Stadium> Stadiums;
extern std::vector<Stadium> currentStadiums;
extern unsigned int totSeatCap;
extern bool expandList;

/**
 * @brief AddStadium::AddStadium
 * @details AddStadium constructor
 * @param parent
 */
AddStadium::AddStadium(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStadium)
{
    ui->setupUi(this);
}

AddStadium::~AddStadium()
{
    delete ui;
}

/**
 * @brief AddStadium::on_pushButton_clicked
 * @details adds the information from the form into a new stadium and concatanates it
 *          onto current stadium vector, then closes itself
 */
void AddStadium::on_pushButton_clicked()
{
    Stadium newStadium;
    QString teamIn = this->ui->TeamNameLineEdit->text();
    QString stadiumIn = this->ui->StadiumNameLineEdit->text();
    unsigned int seatIn = this->ui->SeatCapSpinBox->value();
    QString locIn = this->ui->LocationlineEdit->text();
    conf confIn = conf(this->ui->ConfCpmboBox->currentIndex());
    divi divIn = divi(this->ui->DivComboBox->currentIndex());
    surf surfIn = surf(this->ui->SurfComboBox->currentIndex());
    roof roofIn = roof(this->ui->RoofComboBox->currentIndex());
    short int dateIn = this->ui->DateSpinBox->value();
    newStadium.addStadium(teamIn, stadiumIn, seatIn, locIn, confIn, divIn, surfIn, roofIn, dateIn);
    totSeatCap += newStadium.sendSeat();
    Stadiums.push_back(newStadium);
    this->close();
}

/**
 * @brief AddStadium::on_addFromFileButton_clicked
 * @details calls the popVector function again but with the expandList bool flipped, meaning it populates
 *          with the "Expansion" section too
 */
void AddStadium::on_addFromFileButton_clicked()
{
    expandList = true;
    popVector(currentStadiums);
    this->close();
}
