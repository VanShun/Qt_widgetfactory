#include "toolswidgetapp.h"
#include "ui_toolswidgetapp.h"
#include "hlfunctionitem.h"
#include "hlwidgetproperty.h"
#include "hlbackgroundcontainer.h"
#include "batterylabelproperty.h"
#include "marqueelabelproperty.h"
#include "rgradientlabelproperty.h"
#include "scanlabelproperty.h"
#include "ipeditproperty.h"
#include "clockmeterproperty.h"
#include "temparcproperty.h"
#include "moveresizewidget.h"
#include "waterwaveprogressproperty.h"
#include "loadingprogressproperty.h"
#include "switchbuttonproperty.h"
#include "moveresizewidgetproperty.h"
#include "grabitemwidgetproperty.h"
//#include <QDebug>

ToolsWidgetApp::ToolsWidgetApp(QWidget *parent) :
    MoveResizeWidget(parent),
    ui(new Ui::ToolsWidgetApp)
{
    ui->setupUi(this);

    createButtonModule();
    createLableModule();
    createProgressModule();
    createLineEditModule();
    createMeterModule();
    createWidgetModule();

    ui->minimization->setCursor(QCursor(Qt::PointingHandCursor));
    connect(ui->minimization, SIGNAL(clicked()), this, SLOT(showMinimized()));

    ui->windowclose->setCursor(QCursor(Qt::PointingHandCursor));
    connect(ui->windowclose, SIGNAL(clicked()), this, SLOT(close()));

    initStyleSheet();
}

ToolsWidgetApp::~ToolsWidgetApp()
{
    delete ui;
}

void ToolsWidgetApp::initStyleSheet()
{
    ui->labelIcon->setStyleSheet("border-image: url(:/res/Images/hualian.png);");
    ui->minimization->setStyleSheet("border-image: url(:/res/Images/btn_min.png);");
    ui->windowclose->setStyleSheet("border-image: url(:/res/Images/btn_close.png);");
}

void ToolsWidgetApp::buttonModuleChanged(int index)
{
    HLWidgetProperty *w = nullptr;
    switch (index) {
        case 0:
            w = new SwitchButtonProperty;
            break;
        case 1:
            //w = new LoadingProgressProperty;
            break;
        default:
            break;
    }

    if (!w) return;

    ui->backgroundWidget->addItem(w->getWidget());
    ui->propertycontainer->addItem(w);
    w->init();
}

void ToolsWidgetApp::labelModuleChanged(int index)
{
    HLWidgetProperty *w = nullptr;
    switch (index) {
        case 0:
            w = new BatteryLabelProperty;
            break;
        case 1:
            w = new MarqueeLabelProperty;
            break;
        case 2:
            w = new RGradientLabelProperty;
            break;
        case 3:
            w = new ScanLabelProperty;
            break;
        default:
            break;
    }

    if (!w) return;

    ui->backgroundWidget->addItem(w->getWidget());
    ui->propertycontainer->addItem(w);
    w->init();
}

void ToolsWidgetApp::progressModuleChanged(int index)
{
    HLWidgetProperty *w = nullptr;
    switch (index) {
        case 0:
            w = new WaterWaveProgressProperty;
            break;
        case 1:
            w = new LoadingProgressProperty;
            break;
        default:
            break;
    }

    if (!w) return;

    ui->backgroundWidget->addItem(w->getWidget());
    ui->propertycontainer->addItem(w);
    w->init();
}

void ToolsWidgetApp::lineEditModuleChanged(int index)
{
    HLWidgetProperty *w = nullptr;
    switch (index) {
        case 0:
            w = new IpEditProperty;
            break;
        default:
            break;
    }

    if (!w) return;

    ui->backgroundWidget->addItem(w->getWidget());
    ui->propertycontainer->addItem(w);
    w->init();
}

void ToolsWidgetApp::meterModuleChanged(int index)
{
    HLWidgetProperty *w = nullptr;
    switch (index) {
        case 0:
            w = new ClockMeterProperty;
            break;
        case 1:
            w = new TempArcProperty;
            break;
        default:
            break;
    }

    if (!w) return;

    ui->backgroundWidget->addItem(w->getWidget());
    ui->propertycontainer->addItem(w);
    w->init();
}

void ToolsWidgetApp::widgetModuleChanged(int index)
{
    HLWidgetProperty *w = nullptr;
    switch (index) {
        case 0:
            w = new GrabItemWidgetProperty;
            break;
        case 1:
            w = new MoveResizeWidgetProperty;
            break;
        default:
            break;
    }

    if (!w) return;

    ui->backgroundWidget->addItem(w->getWidget());
    ui->propertycontainer->addItem(w);
    w->init();
}

void ToolsWidgetApp::createButtonModule()
{
    HLFunctionItemRow *widget = new HLFunctionItemRow(ui->itemListWidget);
    widget->addItem(":/res/Images/button.png", "SwitchButton");

    widget->setObjectName("buttonRow");
    widget->setStyleSheet("#buttonRow{background-color:rgba(255, 160, 0, 50)}");

    connect(widget, SIGNAL(rowClicked(int)), SLOT(buttonModuleChanged(int)));
    ui->itemListWidget->addItem(widget, "Button");
}

void ToolsWidgetApp::createLableModule()
{
    HLFunctionItemRow *widget = new HLFunctionItemRow(ui->itemListWidget);
    widget->addItem(":/res/Images/label.png", "batteryLabel");
    widget->addItem(":/res/Images/label.png", "marqueeLabel");
    widget->addItem(":/res/Images/label.png", "rgradientLabel");
    widget->addItem(":/res/Images/label.png", "scanLabel");

    widget->setObjectName("labelRow");
    widget->setStyleSheet("#labelRow{background-color:rgba(0, 255, 200, 50)}");

    connect(widget, SIGNAL(rowClicked(int)), SLOT(labelModuleChanged(int)));
    ui->itemListWidget->addItem(widget, "Label");
}

void ToolsWidgetApp::createProgressModule()
{
    HLFunctionItemRow *widget = new HLFunctionItemRow(ui->itemListWidget);
    widget->addItem(":/res/Images/progress.png", "WaterWaveProgress");
    widget->addItem(":/res/Images/progress.png", "LoadingProgress");

    widget->setObjectName("progressRow");
    widget->setStyleSheet("#progressRow{background-color:rgba(255, 0, 160, 50)}");
    connect(widget, SIGNAL(rowClicked(int)), SLOT(progressModuleChanged(int)));
    ui->itemListWidget->addItem(widget, "Progress");
}

void ToolsWidgetApp::createLineEditModule()
{
    HLFunctionItemRow *widget = new HLFunctionItemRow(ui->itemListWidget);
    widget->addItem(":/res/Images/lineedit.png", "ipEdit");

    widget->setObjectName("lineeditRow");
    widget->setStyleSheet("#lineeditRow{background-color:rgba(160, 0, 50, 50)}");
    connect(widget, SIGNAL(rowClicked(int)), SLOT(lineEditModuleChanged(int)));
    ui->itemListWidget->addItem(widget, "LineEdit");
}

void ToolsWidgetApp::createMeterModule()
{
    HLFunctionItemRow *widget = new HLFunctionItemRow(ui->itemListWidget);
    widget->addItem(":/res/Images/meter.png", "ClockMeter");
    widget->addItem(":/res/Images/meter.png", "TempArc");

    widget->setObjectName("meterRow");
    widget->setStyleSheet("#meterRow{background-color:rgba(0, 0, 255, 50)}");
    connect(widget, SIGNAL(rowClicked(int)), SLOT(meterModuleChanged(int)));
    ui->itemListWidget->addItem(widget, "Meter");
}

void ToolsWidgetApp::createWidgetModule()
{
    HLFunctionItemRow *widget = new HLFunctionItemRow(ui->itemListWidget);
    widget->addItem(":/res/Images/widget.png", "HLGrabItemWidget");
    widget->addItem(":/res/Images/widget.png", "HLMoveResizeWidget");

    widget->setObjectName("widgetRow");
    widget->setStyleSheet("#widgetRow{background-color:rgba(29, 163, 159, 50)}");
    connect(widget, SIGNAL(rowClicked(int)), SLOT(widgetModuleChanged(int)));
    ui->itemListWidget->addItem(widget, "widget");
}


