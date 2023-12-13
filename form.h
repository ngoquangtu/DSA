#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "bst.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:


    void on_insertButton_clicked();

    void on_searchButton_clicked();

    void on_remove_clicked();

    void on_saveButton_clicked();

    void on_findButton_clicked();


private:
    Ui::Form *ui;
    BST *bst;
};

#endif // FORM_H
