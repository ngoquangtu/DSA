#include "maingui.h"
#include "ui_maingui.h"

mainGUI::mainGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainGUI)
{
    ui->setupUi(this);
}

mainGUI::~mainGUI()
{
    delete ui;
}
