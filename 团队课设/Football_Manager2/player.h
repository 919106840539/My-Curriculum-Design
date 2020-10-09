#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QString>

class player : public QWidget
{
    Q_OBJECT
public:
    explicit player(QWidget *parent = nullptr);

    QString name = QString("");//球员名称
    int age;//球员年龄
    double rating;//球员能力值
    QString position;//位置
    int weeksalary;//薪资
    int is_p = 0;//1为上场，0为未上场
    int transferfee;//转会费
    bool hurt;//受伤与否

signals:

public slots:
};



#endif // PLAYER_H
