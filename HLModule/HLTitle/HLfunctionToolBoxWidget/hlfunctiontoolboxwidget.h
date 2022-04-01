#ifndef HLFUNCTIONTOOLBOXWIDGET_H
#define HLFUNCTIONTOOLBOXWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QScrollArea>
#include "global.h"

/*
*HLfunctionToolBoxTopItem管理一组Item的标题头(第一个item)，点击可以展开、收起该组Item
*/
class HLfunctionToolBoxTopItem : public QWidget
{
    Q_OBJECT
    HL_DECLARE_MODULE(HLfunctionToolBoxTopItem)
public:
    explicit HLfunctionToolBoxTopItem(int index, const QString &title, QWidget *parent = nullptr);
    ~HLfunctionToolBoxTopItem();

    inline void setItemIndex(int index) {m_topItemIndex = index;}
    inline int getItemIndex() {return m_topItemIndex;}
    void setItemExpand(bool expand);
    bool isItemExpand() const;
    void setTitle(const QString &title);
    QString getTitle() const;

signals:
    void mousePressAt(int index);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

    int m_topItemIndex;
    QLabel *m_labelIcon, *m_labelTitle;
};


/*
*HLfunctionToolBoxItemGroup 用于管理一组Item，包含标题头和具体的Item
*/
class HLfunctionToolBoxItemGroup : public QWidget
{
    Q_OBJECT
    HL_DECLARE_MODULE(HLfunctionToolBoxItemGroup)
public:
    explicit HLfunctionToolBoxItemGroup(int index, const QString &title, QWidget *parent = nullptr);
    ~HLfunctionToolBoxItemGroup();
    QWidget *item(int index);
    void addItem(QWidget *item);
    void removeItem(QWidget *item);

    void setTitle(const QString &title);
    QString getTitle() const;

    void setItemExpand(bool expand);
    bool isItemExpand() const;

    int itemCount() const;

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;

    QVBoxLayout *m_vlayout;
    QList<QWidget *> m_itemList;
    HLfunctionToolBoxTopItem *m_topItem;
};

/*
* HLfunctionToolBoxUnionItem结构体用于管理item及其index对应关系
*/
typedef  struct HLfunctionToolBoxUnionItem
{
    int m_itemGroupIndex;
    HLfunctionToolBoxItemGroup *m_itemGroup;

    HLfunctionToolBoxUnionItem() {
        m_itemGroupIndex = -1;
        m_itemGroup = nullptr;
    }
} HLfunctionToolBoxUnionItem;

/*
* HLfunctionToolBoxWidget是最终完整的控件，使用了一个滑块区域QScrollArea来管理
* item列表
*/
class HLfunctionToolBoxWidget : public QWidget
{
    Q_OBJECT
    HL_DECLARE_MODULE(HLfunctionToolBoxWidget)

public:
    explicit HLfunctionToolBoxWidget(QWidget *parent = nullptr);
    ~HLfunctionToolBoxWidget();

    virtual QSize sizeHint() const override;

    void addItem(QWidget *item, const QString &title);
    void removeItem(QWidget *item);

    void setTitle(QWidget *item, const QString &title);
    QString getTitle(QWidget *item) const;

    int currentIndex() const;
    int itemCount() const;

public slots:
    void onMousePressAt(int index);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;

    int mapIndex(int index);

    int m_currentIndex, m_itemIndexCnt;
    QVBoxLayout *m_itemVlayout;
    QScrollArea *m_scrollArea;
    QWidget *m_contentsWidget;
    QList<HLfunctionToolBoxUnionItem> m_unionItemList;
};
#endif // HLFUNCTIONTOOLBOXWIDGET_H
