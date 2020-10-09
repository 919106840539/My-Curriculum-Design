#ifndef AFTERGAMEDRAWDIALOG_2_H
#define AFTERGAMEDRAWDIALOG_2_H

#include <QDialog>

namespace Ui {
class afterGameDrawDialog_2;
}

class afterGameDrawDialog_2 : public QDialog
{
    Q_OBJECT

public:
    explicit afterGameDrawDialog_2(QWidget *parent = 0);
    ~afterGameDrawDialog_2();

private:
    Ui::afterGameDrawDialog_2 *ui;
};

#endif // AFTERGAMEDRAWDIALOG_2_H
