#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>

#define HL_MODULE_EXPORT Q_DECL_EXPORT
/*
* 定义类方法：返回模块名称
*/
#define HL_DECLARE_MODULE(class)            \
public:                                     \
    inline static QString getClassName()    \
    {                                       \
        return #class;                      \
    }                                       \

#endif // GLOBAL_H
