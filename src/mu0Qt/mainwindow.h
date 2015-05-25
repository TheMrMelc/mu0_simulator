#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "apprendre.h"
#include "test.h"
#include "aide.h"

namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = 0);
   //Note : explicit empeche une conversion du constructeur par
   //le compilateur qui pourrait entrainer des bugs "invisibles"
   ~MainWindow();

private:
    Ui::MainWindowClass *ui;
    Apprendre *apprendre;
    Test *test;
    Aide *aide;

private slots:
    void on_pushButton_clicked();
    void on_actionAide_triggered();
    void on_actionTester_triggered();
    void on_actionApprendre_triggered();
};

#endif // MAINWINDOW_H
