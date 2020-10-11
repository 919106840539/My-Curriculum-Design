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
    int is_display = 0;//1为展示，0为未展示
    int transferfee;//转会费
    bool hurt;//受伤与否

    player& operator =(const player& p)
    {
        this->name = p.name;
        this->age = p.age;
        this->rating = p.rating;
        this->position = p.position;
        this->weeksalary = p.weeksalary;
        this->is_p = p.is_p;
        this->is_display = p.is_display;
        this->transferfee = p.transferfee;
        this->hurt = p.hurt;
    }

signals:

public slots:
};



#endif // PLAYER_H
