/*********************************************************
** 描述：该模块实现了一个开关按钮
** author: hrs
** date: 2021/12/21
**
*********************************************************/
#include "switchbutton.h"

Switchbutton::Switchbutton(QWidget *parent)
    : QPushButton(parent)
{
    setCursor(QCursor(Qt::PointingHandCursor));
    isCheck = false;

    styleOn = "border-image: url(:res/Images/btncheckon.png); border: 0px;";
    styleOff = "border-image: url(:res/Images/btncheckoff.png); border: 0px;";

    setFixedSize(80,30);            //不允许变化大小
    //resize(80, 30);
    //setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setStyleSheet(styleOff);
    connect(this, SIGNAL(clicked()), this, SLOT(ChangeOnOff()));
    this->setAutoFillBackground(true);
    //this->setFlat(true);
}

void Switchbutton::ChangeOnOff()
{
    if (isCheck) {
        setStyleSheet(styleOff);
        isCheck = false;
    } else {
        setStyleSheet(styleOn);
        isCheck = true;
    }
}

//设置当前选中状态
void Switchbutton::SetCheck(bool isCheck)
{
    if (this->isCheck != isCheck) {
        this->isCheck = !isCheck;
        ChangeOnOff();
    }
}

