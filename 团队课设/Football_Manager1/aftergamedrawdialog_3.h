#ifndef AFTERGAMEDRAWDIALOG_3_H
#define AFTERGAMEDRAWDIALOG_3_H

#include <QDialog>

namespace Ui {
class afterGameDrawDialog_3;
}

class afterGameDrawDialog_3 : public QDialog
{
    Q_OBJECT

public:
    explicit afterGameDrawDialog_3(QWidget *parent = 0);
    ~afterGameDrawDialog_3();

private:
    Ui::afterGameDrawDialog_3 *ui;
};

#endif // AFTERGAMEDRAWDIALOG_3_H
