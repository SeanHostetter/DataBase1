/**
 * @file help.h
 */

#ifndef HELP_H
#define HELP_H

#include <QDialog>

/**
 * @namespace Ui
 * @brief namespace declaring a Help object
 */
namespace Ui {

class Help;

}

/**
 * @class Help
 * @brief Class for the help window
 */
class Help : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Help
     * @param parent
     */
    explicit Help(QWidget *parent = nullptr);
    ~Help();

private:

    Ui::Help *ui; /** @brief -variable assiciated with the help window ui*/

};

#endif // HELP_H
