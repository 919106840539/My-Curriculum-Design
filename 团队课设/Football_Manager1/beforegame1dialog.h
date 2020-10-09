#ifndef BEFOREGAME1DIALOG_H
#define BEFOREGAME1DIALOG_H

#include <QDialog>

namespace Ui {
class BeforeGame1Dialog;
}

class BeforeGame1Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit BeforeGame1Dialog(QWidget *parent = 0);
    ~BeforeGame1Dialog();

private:
    Ui::BeforeGame1Dialog *ui;
};

#endif // BEFOREGAME1DIALOG_H
