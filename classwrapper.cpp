#include "QString"
#include <classwrapper.h>

// template for class SomeThing { }
QString classwrapper(QString myclass, QString constr, QString vrs, QString wrap, bool asInterface)
{    
    QString uclass = "class " + myclass;
    if (myclass.at(0)=='*') {uclass = "final class " + myclass.mid(1);};

    if (asInterface)
    {
        uclass = "interface " + myclass;
        vrs = "";
        constr = "";
    };
    QString comm;
    comm.append("/**\r\n");
    comm.append("* \r\n");
    comm.append("* Autocomment for "+uclass+"\r\n");
    comm.append("* \r\n");
    comm.append("*/ \r\n");
    return comm+uclass + "{\r\n\r\n"+vrs+"\r\n"+constr+"\r\n"+"\r\n"+wrap+"}";
}
