#include <functionwrapper.h>


QString functionwrapper(QString funcdecl, bool asInterface)
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

    if (asInterface)
    {
        scope = "public";
    };

    return "\t " + scope + " function "+funcdecl+"( ){ };\r\n";
}
