#ifndef MAINGUI_H
#define MAINGUI_H

#include <QMainWindow>

namespace Ui {
class mainGUI;
}

class mainGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainGUI(QWidget *parent = nullptr);
    ~mainGUI();

private:
    Ui::mainGUI *ui;
};

#endif // MAINGUI_H
