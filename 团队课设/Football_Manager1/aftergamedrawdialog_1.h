#ifndef AFTERGAMEDRAWDIALOG_1_H
#define AFTERGAMEDRAWDIALOG_1_H

#include <QDialog>

namespace Ui {
class afterGameDrawDialog_1;
}

class afterGameDrawDialog_1 : public QDialog
{
    Q_OBJECT

public:
    explicit afterGameDrawDialog_1(QWidget *parent = 0);
    ~afterGameDrawDialog_1();

private:
    Ui::afterGameDrawDialog_1 *ui;
};

#endif // AFTERGAMEDRAWDIALOG_1_H
