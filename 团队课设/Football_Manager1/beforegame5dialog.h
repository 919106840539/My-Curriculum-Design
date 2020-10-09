#ifndef BEFOREGAME5DIALOG_H
#define BEFOREGAME5DIALOG_H

#include <QDialog>

namespace Ui {
class BeforeGame5Dialog;
}

class BeforeGame5Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit BeforeGame5Dialog(QWidget *parent = 0);
    ~BeforeGame5Dialog();

private:
    Ui::BeforeGame5Dialog *ui;
};

#endif // BEFOREGAME5DIALOG_H
