#ifndef BEFOREGAME2DIALOG_H
#define BEFOREGAME2DIALOG_H

#include <QDialog>

namespace Ui {
class BeforeGame2Dialog;
}

class BeforeGame2Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit BeforeGame2Dialog(QWidget *parent = 0);
    ~BeforeGame2Dialog();

private:
    Ui::BeforeGame2Dialog *ui;
};

#endif // BEFOREGAME2DIALOG_H
