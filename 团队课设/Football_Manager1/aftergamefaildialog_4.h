#ifndef AFTERGAMEFAILDIALOG_4_H
#define AFTERGAMEFAILDIALOG_4_H

#include <QDialog>

namespace Ui {
class afterGameFailDialog_4;
}

class afterGameFailDialog_4 : public QDialog
{
    Q_OBJECT

public:
    explicit afterGameFailDialog_4(QWidget *parent = 0);
    ~afterGameFailDialog_4();

private:
    Ui::afterGameFailDialog_4 *ui;
};

#endif // AFTERGAMEFAILDIALOG_4_H
