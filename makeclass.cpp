#include <makeclass.h>
#include <outproduct.h>
#include <QTextStream>
#include <QStringList>
#include <QStringListIterator>
#include <QTextStream>
#include <QCoreApplication>
#include <QFile>




void makeClass(QStringList args)
{
    QStringListIterator it(args);
    OutProduct MyClass;




    MyClass.copyvalues(scriptwrapper(buildclass(args)));
    MyClass.removeDuplicates();



    QTextStream cout(stdout);

    cout << "// CLASSNAME:" << MyClass.className << endl;
    cout << "// Count of variables:" << MyClass.getVariables().size() << endl;
    cout << "// Count of methods:" << MyClass.getMethods().size() << endl;
    cout << "// Count of child:" << MyClass.getChilds().size() << endl;
    cout << "// Count of requirments:" << MyClass.getRequirements().size() << endl;
    cout << "// arguments: ";

    it.toFront();

    while (it.hasNext())
    {
      cout << it.next() << " ";
    };
    cout << endl;




    outresult(MyClass);



    if (MyClass.childs.size()>0)
    {
        QStringList args;
        QStringListIterator cld (MyClass.childs);
        while (cld.hasNext())
        {
                args.clear();
                args.append("app");
                args.append(cld.next());
                args.append("e:"+MyClass.className);

                args.append("m:"+MyClass.getMethods().join(','));

                args.append("-w");
                if (MyClass.clsnamespace != "")
                    (args.append("n:"+MyClass.clsnamespace)); // ???



                makeClass(args);
        }
    };



}
