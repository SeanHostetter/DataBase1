#ifndef ADDSTADIUM_H
#define ADDSTADIUM_H

#include "stadium.h"
#include <vector>
#include <QDialog>

namespace Ui {
class AddStadium;
}

class AddStadium : public QDialog
{
    Q_OBJECT

public:
    explicit AddStadium(QWidget *parent = nullptr);
    ~AddStadium();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddStadium *ui;
};

#endif // ADDSTADIUM_H
