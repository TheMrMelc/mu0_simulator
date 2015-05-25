#include "apprendre.h"
#include "ui_apprendre.h"

#include <QString>
#include <QFile>
#include <QTextStream>

Apprendre::Apprendre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Apprendre)
{
    ui->setupUi(this);
    //Affichage du schema de cablage quand µP inactif
    ui->label->setPixmap(QPixmap(":/new/prefix1/mu01"));

    ui->pushButton->setText("Quitter"); //pour fermer le simulateur

    ui->pushButton_2->setText("Exécuter");
    ui->pushButton_3->setText("Sauvegarder");    //copie de la liste des instructions choisies pour reutilisation ulterieure
    ui->pushButton_4->setText("Restaurer Code Saisi");

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

Apprendre::~Apprendre()
{
    delete ui;
}

void Apprendre::on_pushButton_clicked()
{
    QApplication::exit();
}

void Apprendre::on_pushButton_2_clicked()
{
    /*
    Affichage du cablage effectue pour l'instruction en cours
    */

    if("LDA") ui->label->setPixmap(QPixmap(":/new/prefix1/lda"));

    //Schémas des autres instructions à créer
}


void Apprendre::on_pushButton_3_clicked()
{
    /*
    Exportation de la liste d'instructions saisies par l'utilisateur
    sous format brut (.txt)
    */
    QString str = ui->lineEdit->text();
    QString filename = "sauvegarde.txt";

    //Note : il faudrait pouvoir faire plusieurs sauvegardes

    QFile file(filename);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    out << str << endl;
    file.close();
}

void Apprendre::on_pushButton_4_clicked()
{
    /*
    Restauration/Importation d'une ancienne liste d'instructions
    sous format brut (.txt)
    */

    QString filename1 = "sauvegarde.txt";
    //Note : quand plusieurs sauvegardes seront possibles,
    //l'utilisateur devra pouvoir choisir laquelle il veut restaurer

    QFile file1(filename1);
    file1.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file1);
    QString str1 = in.readLine();
    ui->lineEdit_2->setText(str1);
    file1.close();
}