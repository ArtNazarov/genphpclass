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
    QStringList comments;
    QString methodname = funcdecl;




    QString vars = "";
    QStringList comments_for_vars;
    QString v;


    if (funcdecl.contains('@'))
    {
         formal_variables = funcdecl.split('@')[1].split('-');
         methodname = funcdecl.split('@')[0];

         QStringListIterator fv (formal_variables);
         while (fv.hasNext())
         {
             v = fv.next();
             declaration.append('$'+v);
             comments_for_vars.append("* @param $"+v);
         };
         vars = declaration.join(',');

    };
    comments.append("/**");
    comments.append("*");
    comments.append("* Autocomment for "+methodname);
    comments.append(comments_for_vars.join("\r\n"));
    comments.append("*\r\n");
    comments.append("*/\r\n");
    QString w = ";";
    if (!asInterface)
    {
        w = "{ }";
    };




    return comments.join("\r\n")+"\t " + scope + " function "+methodname+"( " + vars + " )"+ w + ";\r\n";
}
