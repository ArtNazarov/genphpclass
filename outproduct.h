#ifndef OUTPRODUCT_H
#define OUTPRODUCT_H

#include <QString>
#include <QStringList>

class OutProduct
{
    public:
        QString markup; // result of applying templates to args
        QString options; // f if need to write such file
        QString filename; // filename === classname
        QStringList requirements;
        QStringList childs;
        QStringList uses;
        QStringList parents;
        QString clsnamespace;
        QString className;
        void Product();
        void copyvalues(OutProduct p);

        QString getClassName();
        QString getOptions();
        QString getMarkup();
        QString getFilename();
        QString getNameSpace();
        QStringList getParents();
        QStringList getRequirements();
        QStringList getUses();
        QStringList getChilds();

        void setClassName(QString name);        
        void setRequirments(QStringList r);
        void setUses(QStringList u);        
        void setChilds(QStringList l);
        void setRequirements(QStringList r);
        void setOptions(QString o);
        void setMarkup(QString m);        
        void setFilename(QString n);
        void setNameSpace(QString ns);        
        void setParents(QStringList pr);

        void removeDuplicates();
};

#endif // OUTPRODUCT_H
