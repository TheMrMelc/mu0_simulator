#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("Quitter");
    ui->label_4->setPixmap(QPixmap(":/new/prefix1/mu0"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QApplication::exit();
}

void MainWindow::on_actionApprendre_triggered()
{
    apprendre = new Apprendre(this);
    apprendre->show();
}

void MainWindow::on_actionTester_triggered()
{
    test = new Test(this);
    test->show();
}

void MainWindow::on_actionAide_triggered()
{
    aide = new Aide(this);
    aide->show();
}
