#ifndef MAINWINDOWCLASSIC_H
#define MAINWINDOWCLASSIC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowClassic; }
QT_END_NAMESPACE

class MainWindowClassic : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowClassic(QWidget *parent = nullptr);
    ~MainWindowClassic();

private slots:
    void on_pushButton_clicked();

    void on_LoginPushButton_clicked();

    void on_ClearPushButton_clicked();

    void on_GuestLoginButton_clicked();

    void on_HelpPushButton_clicked();

    void loadingGL();

private:
    Ui::MainWindowClassic *ui;
};
#endif // MAINWINDOWCLASSIC_H
