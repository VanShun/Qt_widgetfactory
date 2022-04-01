/*********************************************************
** 描述：该模块实现了一个IP输入框
** author: hrs
** date: 2021/12/21
**
*********************************************************/
#include "ipedit.h"

#include <QPainter>
#include <QApplication>
#include <QKeyEvent>
#include <QClipboard>
#include <QRegExpValidator>
#include <QStyleOptionButton>

IpEdit::IpEdit(QWidget *parent)
    : QWidget(parent)
{
    m_layout = new QHBoxLayout(this);
    m_layout->setSpacing(3);
    m_layout->setContentsMargins(2, 0, 2, 0);

    m_input_f = new QLineEdit(this);
    m_input_s = new QLineEdit(this);
    m_input_t = new QLineEdit(this);
    m_input_l = new QLineEdit(this);

    initEdit(m_input_f);
    initEdit(m_input_s);
    initEdit(m_input_t);
    initEdit(m_input_l);

    m_dot_f = new QLabel(".", this);
    m_dot_s = new QLabel(".", this);
    m_dot_t = new QLabel(".", this);

    m_layout->addWidget(m_input_f, 1);
    m_layout->addWidget(m_dot_f);
    m_layout->addWidget(m_input_s, 1);
    m_layout->addWidget(m_dot_s);
    m_layout->addWidget(m_input_t, 1);
    m_layout->addWidget(m_dot_t);
    m_layout->addWidget(m_input_l, 1);

    //setFixedSize(165, 25);
    setText("255.255.255.255");  //init value;
}

IpEdit::~IpEdit()
{

}

void IpEdit::initEdit(QLineEdit *edit)
{
    edit->setFrame(false);
    edit->setAlignment(Qt::AlignCenter);
    edit->installEventFilter(this);

    const QString regx("^(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)$");

    QRegExpValidator *validator = new QRegExpValidator(QRegExp(regx), this);
    edit->setValidator(validator);

    connect(edit, SIGNAL(textChanged(QString)), SLOT(editTextChanged(QString)));
}

QLineEdit *IpEdit::nextEdit(QLineEdit *edit)
{
    if (edit == m_input_f) {
        return m_input_s;
    } else if (edit == m_input_s) {
        return m_input_t;
    } else if (edit == m_input_t) {
        return m_input_l;
    } else {
        return nullptr;
    }
}

bool IpEdit::isEdit(QObject *object)
{
    return (object == m_input_f || object == m_input_s ||
            object == m_input_t || object == m_input_l);
}

QString IpEdit::text() const
{
    const QString &text_f = m_input_f->text().isEmpty() ? "0" : m_input_f->text();
    const QString &text_s = m_input_s->text().isEmpty() ? "0" : m_input_s->text();
    const QString &text_t = m_input_t->text().isEmpty() ? "0" : m_input_t->text();
    const QString &text_l = m_input_l->text().isEmpty() ? "0" : m_input_l->text();
    return QString("%1.%2.%3.%4").arg(text_f, text_s, text_t, text_l);
}

void IpEdit::setText(const QString &text)
{
    const QString pattern("^((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)$");

    QRegExp regx(pattern);
    if (!regx.exactMatch(text)) {
        return;
    }

    const QStringList &value = text.split(".");
    m_input_f->setText(value.at(0));
    m_input_s->setText(value.at(1));
    m_input_t->setText(value.at(2));
    m_input_l->setText(value.at(3));
    update();
}

QSize IpEdit::sizeHint() const
{
    return QSize(165, 25);
}

void IpEdit::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QStyleOptionFrame option;
    option.initFrom(this);
    option.lineWidth = 1;
    style()->drawPrimitive(QStyle::PE_PanelLineEdit, &option, &painter, this);
    //QWidget::paintEvent(event);
}

bool IpEdit::eventFilter(QObject *object, QEvent *event)
{
    if (isEdit(object)) {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Period) {
                QLineEdit *next = nextEdit(qobject_cast<QLineEdit*>(object));
                if(next) {
                    next->setFocus();
                    next->selectAll();
                }
            } else if (keyEvent->matches(QKeySequence::Paste)) {
                const QString &clip = QApplication::clipboard()->text(QClipboard::Clipboard);
                if (clip.split(".").size() == 4) {
                    setText(clip);
                    return true;
                }
            }
        }
    }

    return QWidget::eventFilter(object, event);
}

void IpEdit::editTextChanged(const QString& text)
{
    QLineEdit* curEdit = qobject_cast<QLineEdit*>(sender());
    if (text.size() == 3) {   //输入三个数字，如255后，自动跳到下一个输入框
        QLineEdit* next = nextEdit(curEdit);
        if (next) {
            next->setFocus();
            next->selectAll();
        }
    }
}
