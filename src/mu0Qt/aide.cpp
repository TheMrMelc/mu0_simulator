#include "aide.h"
#include "ui_aide.h"

Aide::Aide(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aide)
{
    ui->setupUi(this);
    ui->pushButton->setText("Module d'apprentissage");
    ui->pushButton_2->setText("Tester ses connaissances"); 
    ui->pushButton_3->setText("Quitter");
}

Aide::~Aide()
{
    delete ui;
}

void Aide::on_pushButton_3_clicked()
{
    QApplication::exit();
}