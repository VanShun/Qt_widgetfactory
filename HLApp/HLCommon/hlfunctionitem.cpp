/*********************************************************
** 描述：控件列表，包含图标、控件名称
** author: hrs
** date: 2021/3/14
**
*********************************************************/

#include "hlfunctionitem.h"
#include <QMouseEvent>
#include <QHBoxLayout>
//#include <QDebug>

#define ITEM_ICON_SIZE  25, 25
#define ITEM_ROW_HEIGHT 30

HLFunctionItem::HLFunctionItem(int index, const QString &iconPath, const QString &text, QWidget *parent)
    :QWidget(parent)
{
    QHBoxLayout *hlayout = new QHBoxLayout(this);
    hlayout->setContentsMargins(5, 2, 2, 2);

    m_index = index;
    m_iconLabel = new QLabel(this);
    m_textLabel = new QLabel(this);
    m_textLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_iconLabel->setFixedSize(ITEM_ICON_SIZE);

    setIcon(iconPath);
    setText(text);
    hlayout->addWidget(m_iconLabel);
    hlayout->addWidget(m_textLabel);
    this->setLayout(hlayout);
    setFixedHeight(ITEM_ROW_HEIGHT);
}

HLFunctionItem::~HLFunctionItem()
{

}

void HLFunctionItem::setIcon(const QString &iconPath)
{
    m_iconLabel->setPixmap(iconPath);
}

void HLFunctionItem::setText(const QString &text)
{
    m_textLabel->setText(text);
}

void HLFunctionItem::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked(m_index);
    }
}

HLFunctionItemRow::HLFunctionItemRow(QWidget *parent)
    :QWidget(parent)
{
    m_vlayout = new QVBoxLayout(this);
    m_vlayout->setContentsMargins(0, 0, 0, 0);
    setLayout(m_vlayout);
}

HLFunctionItemRow::~HLFunctionItemRow()
{
    qDeleteAll(m_itemList);
}

void HLFunctionItemRow::addItem(const QString &iconPath, const QString &text)
{
    const int count = m_vlayout->count();
    HLFunctionItem *item = new HLFunctionItem(count, iconPath, text, this);
    connect(item, SIGNAL(clicked(int)), SIGNAL(rowClicked(int)));
    m_vlayout->addWidget(item);
    m_itemList << item;

    setFixedHeight((count + 1) * ITEM_ROW_HEIGHT);
}
