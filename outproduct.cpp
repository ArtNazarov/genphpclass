#include "outproduct.h"
#include "commonfuncs.h"

void OutProduct::Product()
    {
        this->markup = "";
        this->options = "";
        this->filename = "";
        this->className = "";
        this->clsnamespace = "";
        this->requirements.clear();
        this->childs.clear();
        this->parents.clear();
    }

void OutProduct::removeDuplicates()
{    
    this->parents.removeDuplicates();
    this->childs.removeDuplicates();
    this->requirements.removeDuplicates();
}


void OutProduct::copyvalues(OutProduct p)
    {
        this->setChilds(p.getChilds());
        this->setFilename(p.getFilename());
        this->setMarkup(p.getMarkup());
        this->setRequirements(p.getRequirements());
        this->setOptions(p.getOptions());
        this->setClassName(p.getClassName());
        this->setUses(p.getUses());
        this->setNameSpace(p.getNameSpace());
    }

QString OutProduct::getClassName()
    {
        return this->className;
    }

void OutProduct::setClassName(QString name)
    {
        this->className = name;
    }

QStringList OutProduct::getRequirements()
    {
        return this->requirements;
    }

void OutProduct::setRequirments(QStringList r)
    {
        this->requirements = r;
    }

void OutProduct::setUses(QStringList u)
    {
        this->uses.clear();
        QStringListIterator i(u);
        while (i.hasNext())
            {
        this->uses.append(i.next());
            };
    }

QStringList OutProduct::getUses()
    {
        return this->uses;
    }

void OutProduct::setChilds(QStringList l)
    {
        this->childs.clear();
        QStringListIterator i(l);
        while (i.hasNext())
        {
            this->childs.append(i.next());
        };
    }


void OutProduct::setParents(QStringList pr)
    {
        this->parents.clear();
        QStringListIterator i(pr);
        while (i.hasNext())
        {
            this->parents.append(i.next());
        };
    }

QStringList OutProduct::getParents()
{
    return this->parents;
}

QStringList OutProduct::getChilds()
{
    return this->childs;
}

void OutProduct::setRequirements(QStringList r)
    {
        this->requirements.clear();
        QStringListIterator i(r);
        while (i.hasNext())
        {
            this->requirements.append(i.next());
        };
    }

void OutProduct::setOptions(QString o)
    {
        this->options = o;
    }

void OutProduct::setMarkup(QString m)
    {
        this->markup = m;
    }

QString OutProduct::getOptions()
    {
        return this->options;
    }

QString OutProduct::getMarkup()
    {
        return this->markup;
    }

void OutProduct::setFilename(QString n)
    {
        this->filename = n;
    }

QString OutProduct::getFilename()
    {
        return this->filename;
    }

void OutProduct::setNameSpace(QString n)
    {
        this->clsnamespace = n;
    }

QString OutProduct::getNameSpace()
    {
        return this->clsnamespace;
    }

