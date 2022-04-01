/********************************************************************************
** Form generated from reading UI file 'toolswidgetapp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLSWIDGETAPP_H
#define UI_TOOLSWIDGETAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <hlbackgroundcontainer.h>
#include <hlfunctiontoolboxwidget.h>
#include <hlpropertycontainwidget.h>

QT_BEGIN_NAMESPACE

class Ui_ToolsWidgetApp
{
public:
    QGridLayout *gridLayout;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelIcon;
    QLabel *label_Name;
    QSpacerItem *horizontalSpacer;
    QToolButton *minimization;
    QToolButton *windowclose;
    QWidget *centerwidget;
    QGridLayout *gridLayout_2;
    HLfunctionToolBoxWidget *itemListWidget;
    QSplitter *splitter;
    HLBackgroundContainer *backgroundWidget;
    HLPropertyContainWidget *propertycontainer;

    void setupUi(QWidget *ToolsWidgetApp)
    {
        if (ToolsWidgetApp->objectName().isEmpty())
            ToolsWidgetApp->setObjectName(QString::fromUtf8("ToolsWidgetApp"));
        ToolsWidgetApp->resize(1019, 718);
        gridLayout = new QGridLayout(ToolsWidgetApp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        topWidget = new QWidget(ToolsWidgetApp);
        topWidget->setObjectName(QString::fromUtf8("topWidget"));
        topWidget->setMaximumSize(QSize(16777215, 60));
        horizontalLayout = new QHBoxLayout(topWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelIcon = new QLabel(topWidget);
        labelIcon->setObjectName(QString::fromUtf8("labelIcon"));
        labelIcon->setMinimumSize(QSize(60, 40));
        labelIcon->setStyleSheet(QString::fromUtf8(""));
        labelIcon->setPixmap(QPixmap(QString::fromUtf8(":/image/lb_app_logo")));
        labelIcon->setScaledContents(true);

        horizontalLayout->addWidget(labelIcon);

        label_Name = new QLabel(topWidget);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));

        horizontalLayout->addWidget(label_Name);

        horizontalSpacer = new QSpacerItem(750, 19, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        minimization = new QToolButton(topWidget);
        minimization->setObjectName(QString::fromUtf8("minimization"));
        minimization->setMinimumSize(QSize(40, 40));
        minimization->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(minimization);

        windowclose = new QToolButton(topWidget);
        windowclose->setObjectName(QString::fromUtf8("windowclose"));
        windowclose->setMinimumSize(QSize(40, 40));
        windowclose->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(windowclose);


        gridLayout->addWidget(topWidget, 0, 0, 1, 1);

        centerwidget = new QWidget(ToolsWidgetApp);
        centerwidget->setObjectName(QString::fromUtf8("centerwidget"));
        gridLayout_2 = new QGridLayout(centerwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        itemListWidget = new HLfunctionToolBoxWidget(centerwidget);
        itemListWidget->setObjectName(QString::fromUtf8("itemListWidget"));
        itemListWidget->setMinimumSize(QSize(280, 0));
        itemListWidget->setMaximumSize(QSize(280, 16777215));

        gridLayout_2->addWidget(itemListWidget, 0, 0, 1, 1);

        splitter = new QSplitter(centerwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        backgroundWidget = new HLBackgroundContainer(splitter);
        backgroundWidget->setObjectName(QString::fromUtf8("backgroundWidget"));
        splitter->addWidget(backgroundWidget);
        propertycontainer = new HLPropertyContainWidget(splitter);
        propertycontainer->setObjectName(QString::fromUtf8("propertycontainer"));
        propertycontainer->setMinimumSize(QSize(250, 0));
        splitter->addWidget(propertycontainer);

        gridLayout_2->addWidget(splitter, 0, 1, 1, 1);


        gridLayout->addWidget(centerwidget, 1, 0, 1, 1);


        retranslateUi(ToolsWidgetApp);

        QMetaObject::connectSlotsByName(ToolsWidgetApp);
    } // setupUi

    void retranslateUi(QWidget *ToolsWidgetApp)
    {
        ToolsWidgetApp->setWindowTitle(QApplication::translate("ToolsWidgetApp", "Form", nullptr));
        labelIcon->setText(QString());
        label_Name->setText(QApplication::translate("ToolsWidgetApp", "WidgetFactory", nullptr));
        minimization->setText(QString());
        windowclose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ToolsWidgetApp: public Ui_ToolsWidgetApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSWIDGETAPP_H
