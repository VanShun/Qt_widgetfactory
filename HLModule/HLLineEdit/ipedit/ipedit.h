/*********************************************************
** 描述：该模块实现了一个IP输入框
** author: hrs
** date: 2021/12/21
**
*********************************************************/
#ifndef IPEDIT_H
#define IPEDIT_H

#include <QLabel>
#include <QLineEdit>
#include <QBoxLayout>
#include "global.h"


class IpEdit : public QWidget
{
    Q_OBJECT
    HL_DECLARE_MODULE(IpEdit)
public:
    explicit IpEdit(QWidget *parent = nullptr);

    virtual ~IpEdit();

    QString text() const;

    void setText(const QString &text);

    virtual QSize sizeHint() const override;

protected:
    void initEdit(QLineEdit *edit);

    QLineEdit *nextEdit(QLineEdit *edit);

    bool isEdit(QObject *object);

    virtual void paintEvent(QPaintEvent *event) override;

    virtual bool eventFilter(QObject *object, QEvent *event) override;

protected Q_SLOTS:
    void editTextChanged(const QString &text);

private:
    QBoxLayout *m_layout;
    QLineEdit *m_input_f, *m_input_s, *m_input_t, *m_input_l;
    QLabel *m_dot_f, *m_dot_s, *m_dot_t;
};

#endif // IPEDIT_H
