#ifndef BEFOREGAME4DIALOG_H
#define BEFOREGAME4DIALOG_H

#include <QDialog>

namespace Ui {
class BeforeGame4Dialog;
}

class BeforeGame4Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit BeforeGame4Dialog(QWidget *parent = 0);
    ~BeforeGame4Dialog();

private:
    Ui::BeforeGame4Dialog *ui;
};

#endif // BEFOREGAME4DIALOG_H
