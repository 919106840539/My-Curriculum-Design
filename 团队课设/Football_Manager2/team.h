#ifndef TEAM_H
#define TEAM_H

#include <QWidget>
#include <QString>

class team : public QWidget
{
    Q_OBJECT
public:
    explicit team(QWidget *parent = nullptr);

    QString name;//球队名称
    int rank=0;//球队排名
    struct member;//未定义

signals:

public slots:
};

#endif // TEAM_H
