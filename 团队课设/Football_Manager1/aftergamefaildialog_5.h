#ifndef AFTERGAMEFAILDIALOG_5_H
#define AFTERGAMEFAILDIALOG_5_H

#include <QDialog>

namespace Ui {
class afterGameFailDialog_5;
}

class afterGameFailDialog_5 : public QDialog
{
    Q_OBJECT

public:
    explicit afterGameFailDialog_5(QWidget *parent = 0);
    ~afterGameFailDialog_5();

private:
    Ui::afterGameFailDialog_5 *ui;
};

#endif // AFTERGAMEFAILDIALOG_5_H
