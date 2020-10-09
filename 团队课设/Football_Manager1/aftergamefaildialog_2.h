#ifndef AFTERGAMEFAILDIALOG_2_H
#define AFTERGAMEFAILDIALOG_2_H

#include <QDialog>

namespace Ui {
class afterGameFailDialog_2;
}

class afterGameFailDialog_2 : public QDialog
{
    Q_OBJECT

public:
    explicit afterGameFailDialog_2(QWidget *parent = 0);
    ~afterGameFailDialog_2();

private:
    Ui::afterGameFailDialog_2 *ui;
};

#endif // AFTERGAMEFAILDIALOG_2_H
