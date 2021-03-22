#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->textBrowser->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->textBrowser->setText(ScoreString);
    ui->textBrowser->selectAll();
    ui->textBrowser->setAlignment(Qt::AlignCenter);
    ui->textBrowser->setFontPointSize(20);

    QTextCursor cursor = ui->textBrowser->textCursor();
    cursor.movePosition( QTextCursor::End );
    ui->textBrowser->setTextCursor( cursor );

}

Dialog::~Dialog()
{
    delete ui;
}
