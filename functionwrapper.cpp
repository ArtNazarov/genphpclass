#include <functionwrapper.h>


QString functionwrapper(QString funcdecl)
{
    QString scope = "public";

    if (getFirstLetter(funcdecl)  == ".")
           {
            scope = "private";
            funcdecl = ignoreFirstLetter(funcdecl);
           };

    if (getFirstLetter(funcdecl)  == "#")
           {
            scope = "protected";
            funcdecl = ignoreFirstLetter(funcdecl);
           };

    return "\t " + scope + " function "+funcdecl+"( ){ };\r\n";
}
