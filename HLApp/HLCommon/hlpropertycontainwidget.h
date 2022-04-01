/*********************************************************
** 描述：HLPropertyContainWidget作为属性浏览器property browser的容器
** author: hrs
** date: 2021/3/14
**
*********************************************************/

#ifndef HLPROPERTYCONTAINWIDGET_H
#define HLPROPERTYCONTAINWIDGET_H

#include <QWidget>

class HLPropertyContainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HLPropertyContainWidget(QWidget *parent = nullptr);
    ~HLPropertyContainWidget();

    void addItem(QWidget *item);
private:
    QWidget *m_item;
};

#endif // HLPROPERTYCONTAINWIDGET_H
