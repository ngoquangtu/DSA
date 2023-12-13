#include "form.h"
#include "ui_form.h"
#include <QListWidget>
#include <QListWidgetItem>

string fileIndex="index.txt";
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    bst = new BST;
    bst->loadFromFile(fileIndex);
    ui->setupUi(this);
}
Form::~Form()
{
    delete bst;
}

void Form::on_insertButton_clicked()
{
    QString key = ui->insertEdit_key->text();
    QString value = ui->insertEdit_data->text();
    if(!key.isEmpty() && !value.isEmpty())
    {
        bst->insert(key.toStdString(), value.toStdString());
        ui->label_insert->setStyleSheet("QLabel { color : green; }");
        ui->label_insert->setText("Succesfull Insert!!!");
        bst->saveToFile(fileIndex);
    }
    else
    {
        ui->label_insert->setStyleSheet("QLabel { color : red; }");
        ui->label_insert->setText("Failed Insert!!!");
    }
    ui->insertEdit_key->clear();
    ui->insertEdit_data->clear();
    bst->loadFromFile(fileIndex);
}


void Form::on_searchButton_clicked()
{
    bst->loadFromFile(fileIndex);
    QString key = ui->searchEdit->text();

    string result = bst->search(key.toStdString());

    ui->label_search->setText(QString::fromStdString(result));

}


void Form::on_remove_clicked()
{
    QString key = ui->removeEdit->text();
    bst->remove(key.toStdString());
    ui->removeEdit->clear();
    bst->saveToFile(fileIndex);
    bst->loadFromFile(fileIndex);

}


void Form::on_saveButton_clicked()
{
    bst->saveToFile(fileIndex);
    ui->label_savefile->setStyleSheet("QLabel { color : green; }");
    ui->label_savefile->setText("Save file succesfully!!!");

}


void Form::on_findButton_clicked()
{
    bst->loadFromFile(fileIndex);
    QString userInput = ui->findEdit->text();
    string searchString = userInput.toStdString();
    vector<string> duplicates = bst->findDuplicates(searchString);
    QListWidget *listWidget = ui->listWidget;
    listWidget->clear();
    if (!duplicates.empty()) {
        for (const string& duplicate : duplicates) {
            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(duplicate));
            listWidget->addItem(item);
        }
    } else {
        listWidget->addItem("File has not found or has no duplicates");
    }
}


