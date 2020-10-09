#ifndef CURRENTCOMMANDDIALOG_H
#define CURRENTCOMMANDDIALOG_H

#include <QDialog>

namespace Ui {
class currentCommandDialog;
}

class currentCommandDialog : public QDialog
{
    Q_OBJECT

public:
    explicit currentCommandDialog(QWidget *parent = 0);
    ~currentCommandDialog();

private:
    Ui::currentCommandDialog *ui;
};

#endif // CURRENTCOMMANDDIALOG_H
