#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "PushButton.cpp"
#include "QList"
#include "QPushButton"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <thread>
#include <ctime>
#include <unistd.h>
#include <QMessageBox>
#include "dialog.h"
#include <QSqlDatabase>
#include <QtSql>
#include <QCryptographicHash>

extern int ID;
extern QString username;

extern std::string path;
extern QString ScoreString;
extern QList<QPushButton*> buttons;
extern QPushButton *tempButton;
extern QPushButton *PlayButton;
extern int skor;
extern int j;
extern int flag;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void click();
    void on_GameStatus_clicked();

    void on_ScoreHistory_clicked();

    void on_prev_clicked();

private:
    Ui::MainWindow *ui;

    void __init__();
    static void __playGame__();
    static void effect(QPushButton *button, QIcon ButtonIcon, QSize size);

};

extern MainWindow *main_game;

#endif // MAINWINDOW_H
