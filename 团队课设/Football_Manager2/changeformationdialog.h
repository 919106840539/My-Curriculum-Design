#ifndef CHANGEFORMATIONDIALOG_H
#define CHANGEFORMATIONDIALOG_H

#include <QDialog>

namespace Ui {
class changeFormationDialog;
}

class changeFormationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit changeFormationDialog(QWidget *parent = 0);
    ~changeFormationDialog();

private:
    Ui::changeFormationDialog *ui;
};

#endif // CHANGEFORMATIONDIALOG_H
