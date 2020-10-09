#ifndef REDCARDDIALOG_H
#define REDCARDDIALOG_H

#include <QDialog>

namespace Ui {
class redCardDialog;
}

class redCardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit redCardDialog(QWidget *parent = 0);
    void setname(QString name);
    ~redCardDialog();

private:
    Ui::redCardDialog *ui;
};

#endif // REDCARDDIALOG_H
