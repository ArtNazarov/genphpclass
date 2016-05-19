#include <commonfuncs.h>

QString getFirstLetter(QString str)
{
    return str.left(1);
}

QString ignoreFirstLetter(QString str)
{
    return str.mid(1);
}

QString capfirst(QString str)
{
    return getFirstLetter(str).toUpper()+ignoreFirstLetter(str);
}
