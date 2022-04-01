#include "hlfunctiontoolboxwidget.h"
#include <QHBoxLayout>
#include <QFontMetrics>
#include <QPainter>
//#include <QDebug>

HLfunctionToolBoxTopItem::HLfunctionToolBoxTopItem(int index, const QString &title, QWidget *parent)
    : QWidget(parent)
{
    m_topItemIndex = index;

    setFixedHeight(40);

    QHBoxLayout *hlayout = new QHBoxLayout(this);
    hlayout->setContentsMargins(3, 0, 0, 0);
    hlayout->setSpacing(0);
    m_labelIcon = new QLabel(this);
    m_labelIcon->setPixmap(QPixmap(":/res/Images/arrow_up_normal.png"));
    m_labelTitle = new QLabel(this);
    m_labelTitle->setText(title);
    m_labelTitle->setStyleSheet("color:black");
    hlayout->addWidget(m_labelIcon);
    hlayout->addWidget(m_labelTitle);
    hlayout->addStretch();
    this->setLayout(hlayout);
}

HLfunctionToolBoxTopItem::~HLfunctionToolBoxTopItem()
{

}

void HLfunctionToolBoxTopItem::setItemExpand(bool expand)
{
    m_labelIcon->setPixmap(QPixmap(expand ? ":/res/Images/arrow_down_normal.png" :
                                            ":/res/Images/arrow_up_normal.png"));
}

bool HLfunctionToolBoxTopItem::isItemExpand() const
{
    const QPixmap &pix = *m_labelIcon->pixmap();
    return pix.cacheKey() == QPixmap(":/res/Images/arrow_down_normal.png").cacheKey();
}

void HLfunctionToolBoxTopItem::setTitle(const QString &title)
{
    m_labelTitle->setText(QFontMetrics(m_labelTitle->font()).elidedText(title, Qt::ElideRight, 200));
}

QString HLfunctionToolBoxTopItem::getTitle() const
{
    return m_labelTitle->text();
}

void HLfunctionToolBoxTopItem::mousePressEvent(QMouseEvent *event)
{
    //qDebug() << "HLfunctionToolBoxTopItem mousepress:" << m_topItemIndex << endl;
    if (event->button() == Qt::LeftButton) {
        emit mousePressAt(m_topItemIndex);
    }
}

void HLfunctionToolBoxTopItem::paintEvent(QPaintEvent *event)
{
    Q_UNUSED((event))

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    QPen pen;
    pen.setColor(QColor(0, 0, 0));
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    painter.drawLine(0, height(), width(), height());
}

HLfunctionToolBoxItemGroup::HLfunctionToolBoxItemGroup(int index, const QString &title, QWidget *parent)
{
    m_topItem = new HLfunctionToolBoxTopItem(index, title, this);
    connect(m_topItem, SIGNAL(mousePressAt(int)), parent, SLOT(onMousePressAt(int)));

    m_vlayout = new QVBoxLayout(this);
    m_vlayout->setContentsMargins(0, 0, 0, 0);
    m_vlayout->setSpacing(0);
    m_vlayout->addWidget(m_topItem);
    this->setLayout(m_vlayout);
}

HLfunctionToolBoxItemGroup::~HLfunctionToolBoxItemGroup()
{

}

QWidget *HLfunctionToolBoxItemGroup::item(int index)
{
    if (index < 0 || index >= m_itemList.count()) {
        return nullptr;
    }
    return m_itemList.at(index);
}

void HLfunctionToolBoxItemGroup::addItem(QWidget *item)
{
    m_itemList.append(item);
    m_vlayout->addWidget(item);
}

void HLfunctionToolBoxItemGroup::removeItem(QWidget *item)
{
    m_itemList.removeAll(item);
    m_vlayout->removeWidget(item);
}

void HLfunctionToolBoxItemGroup::setTitle(const QString &title)
{
    m_topItem->setTitle(title);
}

QString HLfunctionToolBoxItemGroup::getTitle() const
{
    return m_topItem->getTitle();
}

void HLfunctionToolBoxItemGroup::setItemExpand(bool expand)
{
    m_topItem->setItemExpand(expand);
    for (QWidget *w : qAsConst(m_itemList)) {
        w->setVisible(expand);
    }
}

bool HLfunctionToolBoxItemGroup::isItemExpand() const
{
    //if (!m_itemList.isEmpty()) {
    //    return m_itemList.first()->isVisible();
    //}
    //return false;
    return m_topItem->isItemExpand();
}

int HLfunctionToolBoxItemGroup::itemCount() const
{
    return m_itemList.count();
}

void HLfunctionToolBoxItemGroup::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
}

HLfunctionToolBoxWidget::HLfunctionToolBoxWidget(QWidget *parent)
    :QWidget(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);

    m_currentIndex = -1;
    m_itemIndexCnt = 0;

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    m_contentsWidget = new QWidget(this);
    m_itemVlayout = new QVBoxLayout(m_contentsWidget);
    m_itemVlayout->setContentsMargins(0, 0, 0, 0);
    m_itemVlayout->setSpacing(0);
    m_contentsWidget->setLayout(m_itemVlayout);

    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setFrameShape(QFrame::NoFrame);
    m_scrollArea->setFrameShadow(QFrame::Plain);
    m_scrollArea->setAlignment(Qt::AlignLeft);
    m_scrollArea->setWidget(m_contentsWidget);

    mainLayout->addWidget(m_scrollArea);
    this->setLayout(mainLayout);
}

HLfunctionToolBoxWidget::~HLfunctionToolBoxWidget()
{
    while (!m_unionItemList.isEmpty()) {
        delete m_unionItemList.takeLast().m_itemGroup;
    }
}

QSize HLfunctionToolBoxWidget::sizeHint() const
{
    return QSize(100, 180);
}

void HLfunctionToolBoxWidget::addItem(QWidget *item, const QString &title)
{
    int count = m_itemVlayout->count();
    if(count > 1) {
        m_itemVlayout->removeItem(m_itemVlayout->itemAt(count - 1));
        //添加item时把前一个item的布局空间去掉
    }

    /* 将之前的item组折叠起来 */
    for (HLfunctionToolBoxUnionItem unionItem : qAsConst(m_unionItemList)) {
        unionItem.m_itemGroup->setItemExpand(false);
    }
    HLfunctionToolBoxItemGroup *itemGroup = new HLfunctionToolBoxItemGroup(m_itemIndexCnt, title, this);
    itemGroup->addItem(item);
    itemGroup->setItemExpand(true);

    HLfunctionToolBoxUnionItem newUnionItem;
    newUnionItem.m_itemGroup = itemGroup;
    newUnionItem.m_itemGroupIndex = m_itemIndexCnt++;
    m_unionItemList.append(newUnionItem);
    m_currentIndex = m_unionItemList.count() - 1;

    m_itemVlayout->addWidget(itemGroup);
    m_itemVlayout->addStretch(5);
}

void HLfunctionToolBoxWidget::removeItem(QWidget *item)
{

}

void HLfunctionToolBoxWidget::setTitle(QWidget *item, const QString &title)
{

}

QString HLfunctionToolBoxWidget::getTitle(QWidget *item) const
{

}

int HLfunctionToolBoxWidget::currentIndex() const
{

}

int HLfunctionToolBoxWidget::itemCount() const
{

}

void HLfunctionToolBoxWidget::onMousePressAt(int index)
{
    m_currentIndex = mapIndex(index);
    //qDebug() << "onMousePressAt" << index << m_currentIndex << endl;

    bool expand = !m_unionItemList.at(m_currentIndex).m_itemGroup->isItemExpand();
    m_unionItemList.at(m_currentIndex).m_itemGroup->setItemExpand(expand);
}

void HLfunctionToolBoxWidget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
}

int HLfunctionToolBoxWidget::mapIndex(int index)
{
    int id = -1;
    int count = m_unionItemList.count();
    for (int i = 0; i < count; ++i) {
        if (m_unionItemList.at(i).m_itemGroupIndex == index) {
            id = i;
            break;
        }
    }
    return id;
}
