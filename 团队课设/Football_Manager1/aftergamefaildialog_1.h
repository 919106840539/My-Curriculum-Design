#ifndef AFTERGAMEFAILDIALOG_1_H
#define AFTERGAMEFAILDIALOG_1_H

#include <QDialog>

namespace Ui {
class afterGameFailDialog_1;
}

class afterGameFailDialog_1 : public QDialog
{
    Q_OBJECT

public:
    explicit afterGameFailDialog_1(QWidget *parent = 0);
    ~afterGameFailDialog_1();

private:
    Ui::afterGameFailDialog_1 *ui;
};

#endif // AFTERGAMEFAILDIALOG_1_H
