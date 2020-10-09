#ifndef CHOOSEVICECAPTAINDIALOG_H
#define CHOOSEVICECAPTAINDIALOG_H

#include <QDialog>
#include <QButtonGroup>

namespace Ui {
class ChooseViceCaptainDialog;
}

class ChooseViceCaptainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseViceCaptainDialog(QWidget *parent = 0);

    QButtonGroup *playersBtnGroup;

    void setBox1(QString name);
    void setBox2(QString name);
    void setBox3(QString name);
    void setBox4(QString name);
    void setBox5(QString name);
    void setBox6(QString name);
    void setBox7(QString name);
    void setBox8(QString name);
    void setBox9(QString name);
    void setBox10(QString name);
    void setBox11(QString name);
    void setBox12(QString name);
    void setBox13(QString name);
    void setBox14(QString name);
    void setBox15(QString name);
    void setBox16(QString name);
    void setBox17(QString name);
    void setBox18(QString name);
    void setBox19(QString name);
    void setBox20(QString name);
    void setBox21(QString name);
    void setBox22(QString name);
    void setBox23(QString name);

    void reset();

    ~ChooseViceCaptainDialog();

public slots:
    QString onRadioClick();

private:
    Ui::ChooseViceCaptainDialog *ui;
};

#endif // CHOOSEVICECAPTAINDIALOG_H
