#include "QString"
#include <classwrapper.h>

// template for class SomeThing { }
QString classwrapper(QString myclass, QString wrap)
{
    return "class "+myclass+ "{\r\n"+wrap+"}";
}
