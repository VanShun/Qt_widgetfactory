/*********************************************************
** 描述：控件列表，包含图标、控件名称
** author: hrs
** date: 2021/3/14
**
*********************************************************/


#ifndef HLFUNCTIONITEM_H
#define HLFUNCTIONITEM_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

/*
* HLFunctionItem 用于管理一个item，包含其图标、文本、索引等。
*/
class HLFunctionItem : public QWidget
{
    Q_OBJECT
public:
    explicit HLFunctionItem(int index, const QString &iconPath, const QString &text, QWidget *parent = nullptr);
    ~HLFunctionItem();

    void setIcon(const QString &iconPath);
    void setText(const QString &text);

Q_SIGNALS:
    void clicked(int index);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;

private:
    int m_index;
    QLabel *m_iconLabel, *m_textLabel;
};


class HLFunctionItemRow : public QWidget
{
    Q_OBJECT
public:
    explicit HLFunctionItemRow(QWidget *parent = nullptr);
    ~HLFunctionItemRow();

    void addItem(const QString &iconPath, const QString &text);

Q_SIGNALS:
    void rowClicked(int index);

private:
    QList<HLFunctionItem *>m_itemList;
    QVBoxLayout *m_vlayout;
};
#endif // HLFUNCTIONITEM_H
