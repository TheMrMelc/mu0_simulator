#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("Quitter");

    QPixmap schema_mu0=QPixmap(":/new/prefix1/mu0"); // chargement de l'image
    // get label dimensions
    int w = ui->label_4->width();
    int h = ui->label_4->height();

    // set a scaled pixmap to a w x h window keeping its aspect ratio
    ui->label_4->setPixmap(schema_mu0.scaled(w,h,Qt::KeepAspectRatio));
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

void MainWindow::on_actionTest_triggered()
{
    test = new Test(this);
    test->show();
}

void MainWindow::on_actionAide_triggered()
{
    aide = new Aide(this);
    aide->show();
}
