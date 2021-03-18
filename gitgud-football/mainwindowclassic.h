/**
 * @file mainwindowclassic.h
 */

#ifndef MAINWINDOWCLASSIC_H
#define MAINWINDOWCLASSIC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
/**
 * @namespace Ui
 * @brief namespace declaring a MainWindowClassic object
 */
namespace Ui { class MainWindowClassic; }
QT_END_NAMESPACE

/**
 * @class MainWindowClassic
 * @brief Class representing the login page for the program
 */
class MainWindowClassic : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindowClassic
     * @details login page constructor
     * @param QWidget *parent
     */
    MainWindowClassic(QWidget *parent = nullptr);
    ~MainWindowClassic();

private slots:
    /**
     * @brief on_LoginPushButton_clicked
     * @details checks if login credentials are correct, if they are it sends you to the database screen
     */
    void on_LoginPushButton_clicked();

    /**
     * @brief on_ClearPushButton_clicked
     * @details clears the login credentials
     */
    void on_ClearPushButton_clicked();

    /**
     * @brief on_GuestLoginButton_clicked
     * @details sends the user to the database screen without editing credentials
     */
    void on_GuestLoginButton_clicked();

    /**
     * @brief on_HelpPushButton_clicked
     * @details sends the user to the help screen
     */
    void on_HelpPushButton_clicked();

private:
    Ui::MainWindowClassic *ui; /** @brief -variable assiciated with the login window ui*/
};
#endif // MAINWINDOWCLASSIC_H
