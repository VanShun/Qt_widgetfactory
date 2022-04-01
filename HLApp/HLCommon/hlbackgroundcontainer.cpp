/*********************************************************
** 描述：HLBackgroundContainerItem 该类作为具体的自定义控件的直接容器
** HLBackgroundContainer 作为整体的背景，包含关系为HLBackgroundContainer
** > HLBackgroundContainerItem > iTem
** author: hrs
** date: 2021/3/14
**
*********************************************************/


#include "hlbackgroundcontainer.h"
#include <QPainter>
//#include <QDebug>

#define ITEM_SPACE      20       //边距

HLBackgroundContainerItem::HLBackgroundContainerItem(QWidget *parent)
    :HLGrabItemWidget(parent)
    ,m_widget(nullptr)
{
    m_vlayout = new QVBoxLayout(this);
    m_vlayout->setContentsMargins(0, 0, 0, 0);
    setLayout(m_vlayout);
}

HLBackgroundContainerItem::~HLBackgroundContainerItem()
{
    if (m_widget) delete m_widget;
}

void HLBackgroundContainerItem::addItem(QWidget *item)
{
    if (m_widget) delete m_widget;  //删除已有的m_widget
    m_widget = item;
    //m_widget->setParent(this);
    //m_widget->show();
    m_vlayout->addWidget(m_widget, 0, Qt::AlignCenter);

    /* 适应添加的item大小动态调整背景控件尺寸 */
    const QSize &sizehint = m_widget->size();
    const int width = this->width();
    const int height = this->height();
    //qDebug() << sizehint << width << height << endl;

    if (sizehint.width() > width) {
        this->setFixedWidth(sizehint.width() + ITEM_SPACE);
    }
    if (sizehint.height() > height) {
        this->setFixedHeight(sizehint.height() + ITEM_SPACE);
    }
}

#if 0
void HLBackgroundContainerItem::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    m_borderMarker.clear();
    m_borderMarker.push_back(QPoint(0, 0));
    m_borderMarker.push_back(QPoint(width(), 0));
    m_borderMarker.push_back(QPoint(0, height()));
    m_borderMarker.push_back(QPoint(width(), height()));

    m_borderMarker.push_back(QPoint(0, (height() >> 1)));
    m_borderMarker.push_back(QPoint(width(), (height() >> 1)));
    m_borderMarker.push_back(QPoint((width() >> 1), 0));
    m_borderMarker.push_back(QPoint((width() >> 1), height()));
}

void HLBackgroundContainerItem::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    QPen pen(QColor(255, 0, 0));
    pen.setWidth(10);
    painter.setPen(pen);
    painter.drawPoints(m_borderMarker);
}
#endif
HLBackgroundContainer::HLBackgroundContainer(QWidget *parent) : QWidget(parent)
{
    m_containerItem = new HLBackgroundContainerItem(this);
    m_containerItem->setVisible(false);
}

HLBackgroundContainer::~HLBackgroundContainer()
{
    delete m_containerItem;
}

void HLBackgroundContainer::addItem(QWidget *item)
{
    m_containerItem->setVisible(true);
    m_containerItem->setGeometry(QRect(100, 170, 300, 300));
    m_containerItem->addItem(item);
    //qDebug() << "additem " << endl;
}

