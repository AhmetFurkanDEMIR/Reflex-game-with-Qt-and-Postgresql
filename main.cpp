#include "mainwindow.h"
#include "login.h"
#include <QApplication>

int ID;
QString username;

std::string path;
QString ScoreString;
QList<QPushButton*> buttons;
QPushButton *tempButton;
QPushButton *PlayButton;
int skor=0;
int j;

MainWindow *main_game;
int flag=0;

Login *login_main;


int main(int argc, char *argv[])
{

    // database connect

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setPort(5432);
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("1881");
    bool ok = db.open();

    if(!ok){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Database connection error");
        exit(0);
    }

    QSqlQuery query;

    // Users table init
    query.exec("CREATE TABLE IF NOT EXISTS users (id SERIAL PRIMARY KEY, username VARCHAR(100), password VARCHAR(100));");

    // game scor table init
    query.exec("CREATE TABLE IF NOT EXISTS score (id SERIAL PRIMARY KEY, highest INT, score0 INT, score1 INT, score2 INT, score3 INT, score4 INT, score5 INT);");

    QApplication a(argc, argv);

    // dosyalar eksik ise s3 den indirilir
    FILE *file;
    path=get_current_dir_name();
    std::string path_temp=path+"/images/bomb.png";

    if (file = fopen(path_temp.c_str(), "r")) {
            fclose(file);
        }
    else {
            QString temp="mkdir "+QString::fromStdString(path)+"/images/";
            system(qPrintable(temp));

            temp="wget -P "+QString::fromStdString(path)+"/images/ "+"https://ahmetfurkandemir.s3.amazonaws.com/ReflexGame/bomb.png";
            system(qPrintable(temp));

    }

    path_temp=path+"/images/bomb_effect.png";

    if (file = fopen(path_temp.c_str(), "r")) {
            fclose(file);
        }
    else {

            QString temp="wget -P "+QString::fromStdString(path)+"/images/ "+"https://ahmetfurkandemir.s3.amazonaws.com/ReflexGame/bomb_effect.png";
            system(qPrintable(temp));

    }

    path_temp=path+"/images/eat_pizza.png";

    if (file = fopen(path_temp.c_str(), "r")) {
            fclose(file);
        }
    else {

            QString temp="wget -P "+QString::fromStdString(path)+"/images/ "+"https://ahmetfurkandemir.s3.amazonaws.com/ReflexGame/eat_pizza.png";
            system(qPrintable(temp));

    }

    path_temp=path+"/images/pizza.png";

    if (file = fopen(path_temp.c_str(), "r")) {
            fclose(file);
        }
    else {

            QString temp="wget -P "+QString::fromStdString(path)+"/images/ "+"https://ahmetfurkandemir.s3.amazonaws.com/ReflexGame/pizza.png";
            system(qPrintable(temp));

    }


    // login ekranı sunulur
    Login w;
    login_main=&w;
    w.show();
    return a.exec();
}
