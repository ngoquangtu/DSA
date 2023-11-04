#include "login.h"
#include "ui_login.h"
#include"form.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_login_Button_clicked()
{
    QString username;
    QString password;
    username = ui->lineEdit_account->text();
    password = ui->lineEdit_password->text();

    if (username == "root" && password == "root")
    {
        ui->label_annouce->setText("Login Succesfull!!!");
        this->hide();

//        mainGUI *maingui = new mainGUI(this);
//        maingui->show();
        Form *form = new Form();
        form->show();
    }
    else
    {
        ui->label_annouce->setStyleSheet("QLabel { color : red; }");
        ui->label_annouce->setText("Information incorrect.Please retry!!!");
        ui->lineEdit_account->clear();
        ui->lineEdit_password->clear();
    }
}

