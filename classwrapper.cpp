#include "QString"
#include <classwrapper.h>

// template for class SomeThing { }
QString classwrapper(QString myclass, QString wrap)
{
    QString uclass = "class " + myclass;
    if (myclass.at(0)=='*') {uclass = "final class " + myclass.mid(1);};
    return uclass + "{\r\n"+wrap+"}";
}
