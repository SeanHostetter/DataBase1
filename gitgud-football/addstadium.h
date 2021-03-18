/**
 * @file addstadium.h
 */

#ifndef ADDSTADIUM_H
#define ADDSTADIUM_H

#include "stadium.h"
#include <vector>
#include <QDialog>

/**
 *@namespace Ui
 *@brief namespace declaring a AddStadium object
 */
namespace Ui {

class AddStadium;
}

/**
 * @class AddStadium
 * @brief class representing the "add stadium" window
 */
class AddStadium : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief AddStadium constructor
     * @param parent
     */
    explicit AddStadium(QWidget *parent = nullptr);
    ~AddStadium();

private slots:
    /**
     * @brief on_pushButton_clicked
     * @details submits the information in form to a new stadium object, and adds it to the vector
     */
    void on_pushButton_clicked();
    /**
     * @brief on_addFromFileButton_clicked
     * @details adds the entries after "Expansion" in csv file to the Stadiums vector
     */
    void on_addFromFileButton_clicked();

private:
    Ui::AddStadium *ui; /** @brief -variable assiciated with the help window ui*/
};

#endif // ADDSTADIUM_H
