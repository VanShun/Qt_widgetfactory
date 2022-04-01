/*********************************************************
** 描述：APP主体，包含ui， ui中包含控件列表、控件陈列容器、属性陈列容器等
** author: hrs
** date: 2021/3/14
**
*********************************************************/

#ifndef TOOLSWIDGETAPP_H
#define TOOLSWIDGETAPP_H

#include <QWidget>
#include "moveresizewidget.h"

namespace Ui {
class ToolsWidgetApp;
}

class ToolsWidgetApp : public MoveResizeWidget
{
    Q_OBJECT

public:
    explicit ToolsWidgetApp(QWidget *parent = nullptr);
    ~ToolsWidgetApp();

    void initStyleSheet();

private Q_SLOTS:
    void buttonModuleChanged(int index);
    void labelModuleChanged(int index);
    void progressModuleChanged(int index);
    void lineEditModuleChanged(int index);
    void meterModuleChanged(int index);
    void widgetModuleChanged(int index);

private:
    void createButtonModule();
    void createLableModule();
    void createProgressModule();
    void createLineEditModule();
    void createMeterModule();
    void createWidgetModule();

private:
    Ui::ToolsWidgetApp *ui;
};

#endif // TOOLSWIDGETAPP_H
