/*********************************************************
** 描述：该模块实现了一个通用开关按钮
** author: hrs
** date: 2021/12/21
**
*********************************************************/
#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include <QPushButton>
#include "global.h"

class Switchbutton : public QPushButton
{
    Q_OBJECT
    HL_DECLARE_MODULE(Switchbutton)
public:
    explicit Switchbutton(QWidget *parent = 0);

    //获取当前选中状态
    bool GetCheck() const {return isCheck;}

    //设置当前选中状态
    void SetCheck(bool isCheck);

private:
    bool isCheck;
    QString styleOn;
    QString styleOff;

private slots:
    void ChangeOnOff();
};

#endif // SWITCHBUTTON_H
