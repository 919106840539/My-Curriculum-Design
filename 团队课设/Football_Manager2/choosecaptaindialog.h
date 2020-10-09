#ifndef CHOOSECAPTAINDIALOG_H
#define CHOOSECAPTAINDIALOG_H

#include <QDialog>
#include <QButtonGroup>

namespace Ui {
class ChooseCaptainDialog;
}

class ChooseCaptainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseCaptainDialog(QWidget *parent = 0);

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



    ~ChooseCaptainDialog();

public slots:
    QString onRadioClick();

signals:

private:
    Ui::ChooseCaptainDialog *ui;
};

#endif // CHOOSECAPTAINDIALOG_H
