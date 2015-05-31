#ifndef APPRENDRE_H
#define APPRENDRE_H

#include <QDialog>

namespace Ui {
    class Apprendre;
}

class Apprendre : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Apprendre)
public:
    explicit Apprendre(QWidget *parent = 0);
    virtual ~Apprendre();

private:
    Ui::Apprendre *ui;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};

#endif // APPRENDRE_H
