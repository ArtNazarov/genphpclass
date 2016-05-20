#include <functionwrapper.h>
#include <QStringListIterator>


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


    QStringList formal_variables;
    QStringList declaration;
    QString methodname = funcdecl;




    QString vars = "";


    if (funcdecl.contains('@'))
    {
         formal_variables = funcdecl.split('@')[1].split('-');
         methodname = funcdecl.split('@')[0];
         QStringListIterator fv (formal_variables);
         while (fv.hasNext())
         {
             declaration.append('$'+fv.next());
         };
         vars = declaration.join(',');
    };

    return "\t " + scope + " function "+methodname+"( " + vars + " ){ };\r\n";
}
