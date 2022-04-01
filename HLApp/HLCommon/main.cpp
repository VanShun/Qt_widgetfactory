#include <QApplication>
#include <QTextCodec>
#include "toolswidgetapp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    ToolsWidgetApp w;
    w.show();
    return a.exec();
}
