#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "register.h"
#include "ui_register.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}

// giris yapma buttonu
void Login::on_pushButton_clicked()
{

    // sql username query
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = ?");
    query.bindValue(0, ui->lineEdit->text());
    query.exec();

    QString password, username;
    while (query.next()){

        ID = query.value(0).toInt();
        username = query.value(1).toString();
        password = query.value(2).toString();
    }

    QString temp=ui->lineEdit_2->text();

    // kullanici adi hatali ise girer
    if(username==""){

        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");

        QMessageBox messageBox;
        messageBox.critical(0,"Error","Incorrect username");
    }

    else{

        // sifreler uyusuyor ise girer
        if(QString(QCryptographicHash::hash(temp.toUtf8(),QCryptographicHash::Sha256).toHex()) == password){

            QMessageBox messageBox;
            messageBox.information(0,"Successful","Login successful, good games");

            // sifre dogru ise oyun ekrani olusturulur ve ekrana yansitilir.
            if(flag==0){

                ui->lineEdit->setText("");
                ui->lineEdit_2->setText("");

                hide();
                main_game = new MainWindow(this);
                main_game->show();

                flag+=5;

            }

            // sifre dogru ise oyun ekrani yansitilir.
            else{

                ui->lineEdit->setText("");
                ui->lineEdit_2->setText("");

                hide();
                main_game->show();
            }


        }

        // sifre hatali ise
        else{

            ui->lineEdit->setText("");
            ui->lineEdit_2->setText("");

            QMessageBox messageBox;
            messageBox.critical(0,"Error","Incorrect password");
        }

    }

}

// kayit ekrani olusturulur
void Login::on_pushButton_2_clicked()
{

    hide();
    Register *dialog = new Register(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose, true);
    dialog->show();

}

// sifre line edit
void Login::on_checkBox_stateChanged(int arg1)
{
    if(arg1==2){
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    }

    else{
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }

}
