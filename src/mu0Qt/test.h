#ifndef TEST_H
#define TEST_H

#include <QDialog>

namespace Ui {
    class Test;
}

class Test : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Test)
public:
    explicit Test(QWidget *parent = 0);
    //Note : explicit empeche une conversion de constructeur
    //par le compilateur qui pourrait entrainer des bugs invisibles
    virtual ~Test();

private:
    Ui::Test *ui;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // TEST_H
