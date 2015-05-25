#include "test.h"
#include "ui_test.h"
#include <QString>
#include <QFile>
#include <QTextStream>

Test::Test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
    //Affichage du schema de cablage quand µP inactif
    ui->label->setPixmap(QPixmap(":/new/prefix1/mu01"));

    ui->pushButton->setText("Quitter"); //pour fermer le simulateur
    ui->pushButton_2->setText("Exécuter");

    //Partie gauche de la fenetre, pour le deroulement des instructions
    ui->label_2->setText("Saisir Instruction");
    ui->label_3->setText("Mon code saisi");

    //-----------Remplissage du cadre d'instructions saisies--------
    int n = 50;
    for(int i = 0; i<n ; i++)
    {
        ui->listWidget->addItem(QString::number(i) + "instruction");
    }
    //--------Objectif purement demonstratif ===> A SUPPRIMER ENSUITE
}

Test::~Test()
{
    delete ui;
}

void Apprendre::on_pushButton_clicked()
{
    QApplication::exit();
}

void Apprendre::on_pushButton_2_clicked()
{
}