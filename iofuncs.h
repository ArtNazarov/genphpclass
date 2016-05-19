#ifndef IOFUNCS
#define IOFUNCS


#include <QCoreApplication>
#include <QString>
#include <QStringListIterator>
#include <outproduct.h>
#include <QFile>
#include <QTextStream>

void writetofile(QString filename, QString text);
QStringList getargs(QCoreApplication* app);
void outresult(OutProduct p);

#endif // IOFUNCS

