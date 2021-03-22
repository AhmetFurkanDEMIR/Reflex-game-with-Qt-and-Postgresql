#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::Register *ui;
};


#endif // REGISTER_H
