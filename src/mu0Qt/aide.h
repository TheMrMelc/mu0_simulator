#ifndef AIDE_H
#define AIDE_H

#include <QDialog>

namespace Ui {
    class Aide;
}

class Aide : public QDialog {
    Q_OBJECT
public:
    explicit Aide(QWidget *parent = 0);
    virtual ~Aide();

private:
    Ui::Aide *ui;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // AIDE_H
