#include <iofuncs.h>

void writetofile(QString filename, QString text)
{
    if (filename=="") return;
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {

        QTextStream stream(&file);

        stream << text;

        file.close();
    }
}

// get arguments from user input
QStringList getargs(QCoreApplication* app)
{
    QTextStream cout(stdout);
    QStringList arglst = app->arguments();
    return arglst;
}

void outresult(OutProduct p)
{
    if (p.getOptions() != "f")
        {
         writetofile(p.getFilename(), p.getMarkup());
        };
    QTextStream cout(stdout);
    cout << p.getMarkup() << endl;
}

