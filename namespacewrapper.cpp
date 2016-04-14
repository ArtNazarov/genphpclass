#include <namespacewrapper.h>

QString namespacewrapper(QString ns, QString wrap)
{
    return  "namespace "+ns+"{\r\n"+wrap+"\r\n}";
}

