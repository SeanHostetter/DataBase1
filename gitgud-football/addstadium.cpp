#include "addstadium.h"
#include "database.h"
#include "ui_addstadium.h"
#include <QSpinBox>

extern std::vector<Stadium> Stadiums;

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
    Stadiums.push_back(newStadium);
    this->close();
}
