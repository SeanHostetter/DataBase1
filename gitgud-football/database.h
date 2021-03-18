/**
 * @file database.h
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <QDialog>
#include "stadium.h"

/**
 *@namespace Ui
 *@brief namespace declaring a DataBase object
 */
namespace Ui {
class DataBase;
}

/**
 * @class DataBase
 * @brief class representing database window
 */
class DataBase : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief DataBase
     * @details class representing the DataBase window
     * @param parent
     */
    explicit DataBase(QWidget *parent = nullptr);
    ~DataBase();

private slots:
    /**
     * @brief on_HelpPushButton_clicked
     * @details opens the help window
     */
    void on_HelpPushButton_clicked();
    /**
     * @brief tableWidgetDisplay
     * @details populates and displays the data table with the vector of stadium objects passed in
     * @param Stadiums
     */
    void tableWidgetDisplay(std::vector<Stadium>& Stadiums);
    /**
     * @brief on_searchLineEdit_textChanged
     * @details calls the searchStadiums function and passes the updated Stadiums vector into the
     *          tableWidgetDispalay member function
     * @param arg1
     */
    void on_searchLineEdit_textChanged(const QString &arg1);
    /**
     * @brief on_AddNewPushButton_clicked
     * @details opens the "add new stadium" window
     */
    void on_AddNewPushButton_clicked();
    /**
     * @brief on_pushButton_2_clicked
     * @details saves the current table of stadiums to the csv file and exists the database window
     */
    void on_pushButton_2_clicked();
    /**
     * @brief on_SortByComboBox_currentIndexChanged
     * @details passes the current search box string into the searchStadiums function, returns the
     *          vector of matching Stadium objects, and passes that vector into the tableWidgetDisplay member function
     * @param index
     */
    void on_SortByComboBox_currentIndexChanged(int index);

private:
    Ui::DataBase *ui; /** @brief -variable assiciated with the database window ui*/
};


#endif // DATABASE_H
