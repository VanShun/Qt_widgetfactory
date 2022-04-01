/*********************************************************
** 描述：HLBackgroundContainerItem 该类作为具体的自定义控件的直接容器
** HLBackgroundContainer 作为整体的背景，包含关系为HLBackgroundContainer
** > HLBackgroundContainerItem > iTem
** author: hrs
** date: 2021/3/14
**
*********************************************************/

#ifndef HLBACKGROUNDCONTAINER_H
#define HLBACKGROUNDCONTAINER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPolygon>
#include "moveresizewidget.h"
#include "hlgrabitemwidget.h"

class HLBackgroundContainerItem : public HLGrabItemWidget
{
    Q_OBJECT
public:
    explicit HLBackgroundContainerItem(QWidget *parent = nullptr);
    ~HLBackgroundContainerItem();

    void addItem(QWidget *item);

    //virtual void resizeEvent(QResizeEvent *event) override;

protected:
    //virtual void paintEvent(QPaintEvent *event) override;

    QVBoxLayout *m_vlayout;
    QWidget *m_widget;
    QPolygon m_borderMarker;
};

class HLBackgroundContainer : public QWidget
{
    Q_OBJECT
public:
    explicit HLBackgroundContainer(QWidget *parent = nullptr);
    ~HLBackgroundContainer();

    void addItem(QWidget *item);

private:
    HLBackgroundContainerItem *m_containerItem;
};

#endif // HLBACKGROUNDCONTAINER_H
