#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "login.h"
#include "ui_login.h"

// butonlarin ayarlamalri
void MainWindow::__init__(){

    this->setFixedSize(700, 424);
    this->move(382, 134);

    buttons.append(ui->pushButton_1);
    buttons.append(ui->pushButton_2);
    buttons.append(ui->pushButton_3);
    buttons.append(ui->pushButton_4);
    buttons.append(ui->pushButton_5);
    buttons.append(ui->pushButton_6);
    buttons.append(ui->pushButton_7);
    buttons.append(ui->pushButton_8);
    buttons.append(ui->pushButton_9);
    buttons.append(ui->pushButton_10);
    buttons.append(ui->pushButton_11);
    buttons.append(ui->pushButton_12);
    buttons.append(ui->pushButton_13);
    buttons.append(ui->pushButton_14);
    buttons.append(ui->pushButton_15);
    buttons.append(ui->pushButton_16);
    buttons.append(ui->pushButton_17);
    buttons.append(ui->pushButton_18);
    buttons.append(ui->pushButton_19);
    buttons.append(ui->pushButton_20);
    buttons.append(ui->pushButton_21);
    buttons.append(ui->pushButton_22);
    buttons.append(ui->pushButton_23);
    buttons.append(ui->pushButton_24);
    buttons.append(ui->pushButton_25);
    buttons.append(ui->pushButton_26);
    buttons.append(ui->pushButton_27);
    buttons.append(ui->pushButton_28);
    buttons.append(ui->pushButton_29);
    buttons.append(ui->pushButton_30);
    buttons.append(ui->pushButton_31);
    buttons.append(ui->pushButton_32);
    buttons.append(ui->pushButton_33);
    buttons.append(ui->pushButton_34);
    buttons.append(ui->pushButton_35);
    buttons.append(ui->pushButton_36);
    buttons.append(ui->pushButton_37);
    buttons.append(ui->pushButton_38);
    buttons.append(ui->pushButton_39);
    buttons.append(ui->pushButton_40);
    buttons.append(ui->pushButton_41);
    buttons.append(ui->pushButton_42);
    buttons.append(ui->pushButton_43);
    buttons.append(ui->pushButton_44);
    buttons.append(ui->pushButton_45);
    buttons.append(ui->pushButton_46);
    buttons.append(ui->pushButton_47);
    buttons.append(ui->pushButton_48);
    buttons.append(ui->pushButton_49);
    buttons.append(ui->pushButton_50);
    buttons.append(ui->pushButton_51);
    buttons.append(ui->pushButton_52);
    buttons.append(ui->pushButton_53);
    buttons.append(ui->pushButton_54);
    buttons.append(ui->pushButton_55);
    buttons.append(ui->pushButton_56);

    QPixmap pixmap(QString::fromStdString(path)+"/images/bomb.png");
    QIcon ButtonIcon(pixmap);
    QSize size(27, 27);

    foreach (QPushButton *temp, buttons) {

        temp->setIcon(ButtonIcon);
        temp->setStyleSheet("background-color: red");
        temp->setIconSize(size);
        connect(temp, SIGNAL(clicked()), this, SLOT(click()));
    }

    ui->label->setAlignment(Qt::AlignCenter);
    PlayButton=ui->GameStatus;

}

// oyunun dondugu main fonksiyon
void MainWindow::__playGame__(){


    int i,x, z=3, count=-1;

    QPixmap pixmap_0(QString::fromStdString(path)+"/images/bomb.png");
    QIcon ButtonIcon_0(pixmap_0);


    QPixmap pixmap_1(QString::fromStdString(path)+"/images/pizza.png");
    QIcon ButtonIcon_1(pixmap_1);
    QSize size(30, 30);

    while(1){

        if(PlayButton->text()!="Finish the game"){
            break;
        }

        count+=1;
        x=rand()%57;
        j=x;
        i=0;

        foreach (QPushButton *temp, buttons) {

            if(i==x){

                temp->setIcon(ButtonIcon_1);
                temp->setIconSize(size);
                temp->setStyleSheet("background-color: blue");
                tempButton=temp;

                usleep(10000000/z);
                temp->setIcon(ButtonIcon_0);
                temp->setStyleSheet("background-color: red");

                break;
            }

            i++;
        }

        if(count==3){
            z=6;
        }

        else if(count==8){
            z=7;
        }

        else if(count==12){
            z=9;
        }

        else if(count==20){
            z=10;
        }

        else if(count==30){
            z=12;
        }

        else if(count==50){
            z=16;
        }
    }

    // oyun bitince kullanicinin skorlari alinir
    QSqlQuery query;
    query.prepare("SELECT * FROM score WHERE id = ?");
    query.bindValue(0, ID);
    query.exec();
    int score[7];

    while (query.next()) {
        score[0]=query.value(1).toInt();
        score[1]=query.value(2).toInt();
        score[2]=query.value(3).toInt();
        score[3]=query.value(4).toInt();
        score[4]=query.value(5).toInt();
        score[5]=query.value(6).toInt();
        score[6]=query.value(7).toInt();
    }

    // en yuksek skor ise guncelleme yapilir ve tablo bir adim kaydirilir.
    if(score[0]<=skor){

        query.prepare("UPDATE score SET highest = ? WHERE ID = ?");
        query.bindValue(0, skor);
        query.bindValue(1, ID);
        query.exec();

        for(int k=0; k<6;k++){

            query.prepare("UPDATE score SET score"+QString::number(k)+" = ? WHERE ID = ?");
            query.bindValue(0, score[k]);
            query.bindValue(1, ID);
            query.exec();

        }

    }

    // ikinci skordan yüksek ise guncelleme yapilir ve tablo bir adim kaydirilir.
    else if(score[1]<=skor){

        query.prepare("UPDATE score SET score0 = ? WHERE ID = ?");
        query.bindValue(0, skor);
        query.bindValue(1, ID);
        query.exec();

        for(int k=1; k<6;k++){

            query.prepare("UPDATE score SET score"+QString::number(k)+" = ? WHERE ID = ?");
            query.bindValue(0, score[k]);
            query.bindValue(1, ID);
            query.exec();

        }

    }

    // ucuncu skordan yüksek ise guncelleme yapilir ve tablo bir adim kaydirilir.
    else if(score[2]<=skor){

        query.prepare("UPDATE score SET score1 = ? WHERE ID = ?");
        query.bindValue(0, skor);
        query.bindValue(1, ID);
        query.exec();

        for(int k=2; k<6;k++){

            query.prepare("UPDATE score SET score"+QString::number(k)+" = ? WHERE ID = ?");
            query.bindValue(0, score[k]);
            query.bindValue(1, ID);
            query.exec();

        }

    }

    // dorduncu skordan yüksek ise guncelleme yapilir ve tablo bir adim kaydirilir.
    else if(score[3]<=skor){

        query.prepare("UPDATE score SET score2 = ? WHERE ID = ?");
        query.bindValue(0, skor);
        query.bindValue(1, ID);
        query.exec();

        for(int k=3; k<6;k++){

            query.prepare("UPDATE score SET score"+QString::number(k)+" = ? WHERE ID = ?");
            query.bindValue(0, score[k]);
            query.bindValue(1, ID);
            query.exec();

        }

    }

    // besinci skordan yüksek ise guncelleme yapilir ve tablo bir adim kaydirilir.
    else if(score[4]<=skor){

        query.prepare("UPDATE score SET score3 = ? WHERE ID = ?");
        query.bindValue(0, skor);
        query.bindValue(1, ID);
        query.exec();

        for(int k=4; k<6;k++){

            query.prepare("UPDATE score SET score"+QString::number(k)+" = ? WHERE ID = ?");
            query.bindValue(0, score[k]);
            query.bindValue(1, ID);
            query.exec();

        }

    }

    // altinci skordan yüksek ise guncelleme yapilir ve tablo bir adim kaydirilir.
    else if(score[5]<=skor){

        query.prepare("UPDATE score SET score4 = ? WHERE ID = ?");
        query.bindValue(0, skor);
        query.bindValue(1, ID);
        query.exec();

        query.prepare("UPDATE score SET score5 = ? WHERE ID = ?");
        query.bindValue(0, score[5]);
        query.bindValue(1, ID);
        query.exec();

    }

    // yedinci skordan yüksek ise guncelleme yapilir ve tablo bir adim kaydirilir.
    else if(score[6]<=skor){

        query.prepare("UPDATE score SET score5 = ? WHERE ID = ?");
        query.bindValue(0, skor);
        query.bindValue(1, ID);
        query.exec();

    }

    skor=0;
    return;

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    __init__();
}

MainWindow::~MainWindow()
{
    delete ui;

}

// butona effect ekleme
void MainWindow::effect(QPushButton *button, QIcon ButtonIcon, QSize size){

    sleep(1);

    button->setIcon(ButtonIcon);
    button->setIconSize(size);

}

// tklanılan butona gore efect ve puan verecek.
void MainWindow::click(){

    if(PlayButton->text()!="Finish the game"){
        return;
    }

    QObject* button = QObject::sender();
    int i=0;

    foreach(QPushButton *temp, buttons){
        if(button==temp){

            if(i==j){

                skor+=1;

                QPixmap pixmap(QString::fromStdString(path)+"/images/eat_pizza.png");
                QIcon ButtonIcon(pixmap);
                QSize size(30, 30);

                tempButton->setIcon(ButtonIcon);
                tempButton->setIconSize(size);
                tempButton->setStyleSheet("background-color: green");
            }

            else{
                skor-=1;

                QPixmap pixmap(QString::fromStdString(path)+"/images/bomb_effect.png");
                QIcon ButtonIcon(pixmap);
                QSize size(35, 35);

                temp->setIcon(ButtonIcon);
                temp->setIconSize(size);

                QPixmap pixmap_0(QString::fromStdString(path)+"/images/bomb.png");
                QIcon ButtonIcon_0(pixmap_0);
                QSize size_0(27, 27);

                std::thread effect0(effect, temp, ButtonIcon_0, size_0);
                effect0.detach();

            }
        }
        i+=1;
    }

    QString tmp = "Score: "+QString::number(skor);
    ui->label->setText(tmp);

}

// oyunu baslatma ve durdurma
void MainWindow::on_GameStatus_clicked()
{
    if(ui->GameStatus->text()=="Start the game"){

        ui->GameStatus->setText("Finish the game");
        std::thread playgGame(__playGame__);
        playgGame.detach();

    }

    else{

        ui->GameStatus->setText("Start the game");

        QString tmp = "Score: "+QString::number(0);
        ui->label->setText(tmp);

        QMessageBox messageBox;
        messageBox.information(0,"Score","Your score in this game: "+QString::number(skor));

        close();
        main_game->show();
    }
}

// skor gecmisini goruntuluyen pencere
void MainWindow::on_ScoreHistory_clicked()
{

    if(ui->GameStatus->text()!="Start the game"){
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM score WHERE id = ?");
    query.bindValue(0, ID);
    query.exec();
    ScoreString="";

    while (query.next()) {

        ScoreString+="Highest Score: "+QString::number(query.value(1).toInt())+"\n";
        ScoreString+="\nPast Scores\n ----------------\n";
        ScoreString+="Score 1 -> "+QString::number(query.value(2).toInt())+"\n";
        ScoreString+="Score 2 -> "+QString::number(query.value(3).toInt())+"\n";
        ScoreString+="Score 3 -> "+QString::number(query.value(4).toInt())+"\n";
        ScoreString+="Score 4 -> "+QString::number(query.value(5).toInt())+"\n";
        ScoreString+="Score 5 -> "+QString::number(query.value(6).toInt())+"\n";
        ScoreString+="Score 6 -> "+QString::number(query.value(7).toInt())+"\n";
    }

    Dialog *dialog = new Dialog(this);
    dialog->show();

}

// login ekranina donme
void MainWindow::on_prev_clicked()
{

    if(ui->GameStatus->text()!="Start the game"){
        return;
    }

    this->close();
    login_main->show();
}
