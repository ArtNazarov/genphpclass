#ifndef BUILDCLASS_H
#define BUILDCLASS_H

#include <QTextStream>
#include <QCoreApplication>
#include <QStringList>
#include <QStringListIterator>
#include <QFile>
#include <QTextStream>
#include <outproduct.h>
#include <QStringList>
#include <functionwrapper.h>
#include <scriptwrapper.h>
#include <outproduct.h>
#include <classwrapper.h>
#include <namespacewrapper.h>
#include <help.h>

OutProduct help();
OutProduct buildclass(QStringList args);

#endif // BUILDCLASS_H
