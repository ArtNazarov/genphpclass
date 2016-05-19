#include <outproduct.h>
#include <iofuncs.h>
#include <functionwrapper.h>
#include <buildclass.h>
#include <makeclass.h>
#include <QCoreApplication>

int main (int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    if (argc >= 2)
    {
    makeClass(getargs(&app));
    }
    else
    {
        outresult(help());
    }
}
