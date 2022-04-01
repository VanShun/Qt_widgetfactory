/*********************************************************
** 描述：HLPropertyContainWidget作为属性浏览器property browser的容器
** author: hrs
** date: 2021/3/14
**
*********************************************************/


#include "hlpropertycontainwidget.h"
#include <QHBoxLayout>

HLPropertyContainWidget::HLPropertyContainWidget(QWidget *parent)
    : QWidget(parent)
    ,m_item(nullptr)
{
    QHBoxLayout *hlayout = new QHBoxLayout(this);
    hlayout->setContentsMargins(0, 0, 0, 0);
    setLayout(hlayout);
}

HLPropertyContainWidget::~HLPropertyContainWidget()
{
    if (m_item) delete m_item;
}

void HLPropertyContainWidget::addItem(QWidget *item)
{
    if (m_item) delete m_item;
    m_item = item;
    layout()->addWidget(m_item);
}
