#ifndef BEFOREGAME3DIALOG_H
#define BEFOREGAME3DIALOG_H

#include <QDialog>

namespace Ui {
class BeforeGame3Dialog;
}

class BeforeGame3Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit BeforeGame3Dialog(QWidget *parent = 0);
    ~BeforeGame3Dialog();

private:
    Ui::BeforeGame3Dialog *ui;
};

#endif // BEFOREGAME3DIALOG_H
