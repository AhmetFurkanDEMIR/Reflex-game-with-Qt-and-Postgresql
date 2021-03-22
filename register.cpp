#include "register.h"
#include "ui_register.h"

#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

Register::~Register()
{
    delete ui;
}

// login ekranina geri gelme
void Register::on_pushButton_2_clicked()
{
    hide();
    login_main->show();
}

// kayit islemi
void Register::on_pushButton_clicked()
{

    QSqlQuery query;
    QString temp;

    // kullanici adinin unic olup olmama kontrolu
    query.prepare("SELECT * FROM users WHERE username = ?");
    query.bindValue(0, ui->lineEdit->text());
    query.exec();

    while (query.next()){

        temp=query.value(1).toString();
    }

    qDebug("%s",qPrintable(temp));

    // kullanici adi var ise hata verir
    if(temp!=""){

        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");

        QMessageBox messageBox;
        messageBox.critical(0,"Error","This username belongs to someone else, please enter a unique username.");

        on_pushButton_2_clicked();

    }

    // yok ise kayit eklenir.
    else{

        // "users" tabloya kullanici ekleme islemi
        query.prepare("INSERT INTO users(username, password) "
                          "VALUES (?, ?)");

        query.bindValue(0, ui->lineEdit->text());
        temp = ui->lineEdit_2->text();
        query.bindValue(1, QString(QCryptographicHash::hash(temp.toUtf8(),QCryptographicHash::Sha256).toHex()));
        query.exec();

        // "score" tabloya kullanici ekleme islemi
        query.prepare("INSERT INTO score (highest, score0, score1, score2, score3, score4, score5) "
                              "VALUES (?, ?, ?, ?, ?, ?, ?)");

        query.bindValue(0, 0);
        query.bindValue(1, 0);
        query.bindValue(2, 0);
        query.bindValue(3, 0);
        query.bindValue(4, 0);
        query.bindValue(5, 0);
        query.bindValue(6, 0);
        query.exec();

        QMessageBox messageBox;
        messageBox.information(0,"Register","Registration successful");

        on_pushButton_2_clicked();
    }

}

// sifre line edit
void Register::on_checkBox_stateChanged(int arg1)
{
    if(arg1==2){
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    }

    else{
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }
}
