/*********************************************************
** 描述：该模块实现了一个扫描显示控件
** author: hrs
** date: 2021/12/21
**
*********************************************************/

#ifndef TTKSCANLABEL_H
#define TTKSCANLABEL_H


#include <QWidget>
#include "global.h"

class  ScanLabel : public QWidget
{
    Q_OBJECT
    HL_DECLARE_MODULE(ScanLabel)
public:
    explicit ScanLabel(QWidget *parent = nullptr);

    virtual ~ScanLabel();

    void setImage(const QPixmap &image);

    void setImageRadius(int imageRadius);

    void setImageBorderWidth(int imageBorderWidth);

    void setImageBorderColor(const QColor &imageBorderColor);

    void setScanRadius(int scanRadius);

    void setScanColor(const QColor &scanColor);

    virtual QSize sizeHint() const override;

protected Q_SLOTS:
    void updateRender();

protected:
    virtual void paintEvent(QPaintEvent *event) override;

    void drawScan(QPainter *painter);

    void drawImage(QPainter *painter);

private:
    QPixmap m_image;
    int m_imageRadius,m_imageBorderWidth, m_scanRadius, m_scanDeg;
    QColor m_imageBorderColor, m_scanColor;
    QTimer *m_circleTimer;
};

#endif // TTKSCANLABEL_H
