#include <outproduct.h>
#include <scriptwrapper.h>
#include <QSet>

OutProduct scriptwrapper(OutProduct p)
{
    OutProduct m;
    m.copyvalues(p);
    p.removeDuplicates();
    QString requires = "";
    QString currentRequire;

    p.requirements.removeDuplicates();

    QStringListIterator rq (p.requirements);

    requires = "";
    while (rq.hasNext())
    {
        currentRequire = rq.next();
        requires.append("require_once \""+currentRequire+".php\";\r\n");
    }

    QString adduses = "";

    if (m.uses.size()>0)
    {

        QStringListIterator us ( m.uses );
        QString currentUse;
        while (us.hasNext())
         {
           currentUse = us.next();
           adduses.append("use "+currentUse+";\r\n");
         };
    };


    m.setMarkup("\r\n<?php\r\n" + requires  + adduses + p.getMarkup() + "\r\n?>\r\n");
    m.setOptions(p.getOptions());
    m.setFilename(p.getFilename());
    return m;
}
