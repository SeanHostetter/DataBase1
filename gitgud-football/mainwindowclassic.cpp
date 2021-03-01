#include "mainwindowclassic.h"
#include "ui_mainwindowclassic.h"
#include "addstadium.h"
#include "database.h"
#include "help.h"

extern bool login;
extern QString loginInfo[5][2];

MainWindowClassic::MainWindowClassic(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowClassic)
{
    ui->setupUi(this);
}

MainWindowClassic::~MainWindowClassic()
{
    delete ui;
}


void MainWindowClassic::on_pushButton_clicked()  //doesnt do anything
{

}

//checks to see if login data is valid iteratively
//sets login value to true, allowing user to edit table
void MainWindowClassic::on_LoginPushButton_clicked()
{
    for(int i = 0; i < 4; i++){
        if(((this->ui->UserIdLineEdit->text()) == loginInfo[i][0]) && ((this->ui->PasswordLineEdit->text()) == loginInfo[i][1])){
            login = true;
            DataBase openDataBase;
            openDataBase.setModal(true);
            openDataBase.exec();
        }
    }
}

//clears userID and password line edits
void MainWindowClassic::on_ClearPushButton_clicked()
{
    this->ui->UserIdLineEdit->setText("");
    this->ui->PasswordLineEdit->setText("");
}

//sets login value to false, blocking the user from editing the table
//opens database window
void MainWindowClassic::on_GuestLoginButton_clicked()
{
    login = false;
    DataBase openDataBase;
    openDataBase.setModal(true);
    openDataBase.exec();
}

//opens the help window
void MainWindowClassic::on_HelpPushButton_clicked()
{
    Help openHelp;
    openHelp.setModal(true);
    openHelp.exec();
}

