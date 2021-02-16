#ifndef DATABASE_H
#define DATABASE_H

#include <QDialog>
#include "stadium.h"

namespace Ui {
class DataBase;
}

class DataBase : public QDialog
{
    Q_OBJECT

public:
    explicit DataBase(QWidget *parent = nullptr);
    ~DataBase();

private slots:
    void on_HelpPushButton_clicked();

    void on_SortByComboBox_activated(const QString &arg1);

    void on_tableWidget_cellActivated(int row, int column);

    void tableWidgetDisplay(std::vector<Stadium>& Stadiums);

    void on_searchLineEdit_textChanged(const QString &arg1);

    void on_AddNewPushButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DataBase *ui;
};


#endif // DATABASE_H
