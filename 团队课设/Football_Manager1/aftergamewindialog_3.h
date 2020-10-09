#ifndef AFTERGAMEWINDIALOG_3_H
#define AFTERGAMEWINDIALOG_3_H

#include <QDialog>

namespace Ui {
class afterGameWinDialog_3;
}

class afterGameWinDialog_3 : public QDialog
{
    Q_OBJECT

public:
    explicit afterGameWinDialog_3(QWidget *parent = 0);
    ~afterGameWinDialog_3();

private:
    Ui::afterGameWinDialog_3 *ui;
};

#endif // AFTERGAMEWINDIALOG_3_H
