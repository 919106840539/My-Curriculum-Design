#ifndef AFTERGAMEFAILDIALOG_3_H
#define AFTERGAMEFAILDIALOG_3_H

#include <QDialog>

namespace Ui {
class afterGameFailDialog_3;
}

class afterGameFailDialog_3 : public QDialog
{
    Q_OBJECT

public:
    explicit afterGameFailDialog_3(QWidget *parent = 0);
    ~afterGameFailDialog_3();

private:
    Ui::afterGameFailDialog_3 *ui;
};

#endif // AFTERGAMEFAILDIALOG_3_H
