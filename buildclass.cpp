#include <buildclass.h>
#include <QTextStream>


void printstr(QString msg, QString str)
{
    QTextStream cout(stdout);
    cout  << endl << "------------------------- " + msg + "------------------------ " << endl;
    cout  << endl << str << endl;
    cout  << endl << "------------------------- /" +msg + "------------------------ " << endl;
}


// concat declarations
OutProduct buildclass(QStringList args)
{
OutProduct result;
bool makeProperties = false;
bool addRequirements = false;
QTextStream cout(stdout);
QString funcdecl = "";
QString classdecl = "";
QString option = "";
QString addclasses = "";
//cout << addclasses << endl;
QString addinterfaces = "";
QStringList interfaces;
QStringList parentClasses;
QStringList classMethods;
QStringList variables;




    if (args.size()<2) {result.copyvalues(help());}
    else
    {
    QStringListIterator it ( args );

   it.next(); // first arg is app
   it.next(); // second arg is classname

   while (it.hasNext())
    {
       option = it.next();

       if (option.contains("i:"))
       {
          interfaces =  option.split(':')[1].split(',');

       };

       if (option.contains("e:"))
       {
          parentClasses =  option.split(':').last().split(',');

       };

       if (option.compare("-w", Qt::CaseInsensitive))
       {
                                result.setMarkup("f");
       };

       if (option.compare("-p", Qt::CaseInsensitive))
       {
           makeProperties = true;
       };

       if (option.compare("-r", Qt::CaseInsensitive))
       {
           addRequirements = true;
       };

       if (option.contains("c:"))
       {
           result.childs = option.split(':').last().split(',');
       };

       if (option.contains("n:"))
       {
           result.clsnamespace = option.split(':').last();
       };

       if (option.contains("m:"))
       {
          classMethods =  option.split(':').last().split(',');
       };

       if (option.contains("v:"))
       {
         variables = option.split(':').last().split(',');
       };

       if (option.contains("u:"))
       {
         result.uses = option.split(':').last().split(',');

         if (result.uses.size()>0)
                {
                    QStringListIterator us(result.uses);
                    QString currentUse = "";
                    while (us.hasNext())
                        {
                            currentUse = us.next();
                            if (addRequirements)
                                {
                                    result.requirements.push_back(currentUse);
                                };
                        };
                };
      };
};
    result.setFilename(args.at(1) + ".php");

    if (classMethods.size()>0)
    {
         classMethods.removeDuplicates();
         QStringListIterator funcs(classMethods);
         while (funcs.hasNext())
          {
             funcdecl.append(functionwrapper(funcs.next()));
          };
           // printstr("prepare function", funcdecl);
    };
    QString lastIntf = "";
    if (interfaces.size()>0)
    {
        interfaces.removeDuplicates();

        QStringListIterator intf (interfaces);
        QString currentIntf = "";
        while (intf.hasNext())
         {

           currentIntf = intf.next();

           if (lastIntf == currentIntf) {lastIntf = intf.next(); continue;};
           if (addRequirements) {result.requirements.push_back(currentIntf);};

           addinterfaces += currentIntf + ',';
           lastIntf = currentIntf;
         };

        // cout << addinterfaces << endl;


        addinterfaces.remove(addinterfaces.size()-1, 1);
        QString temp (addinterfaces);
        addinterfaces.clear(); ;
        addinterfaces.append( " implements " + temp + " ");
        //cout << addinterfaces << endl;
    };

    QString lastPar = "";
    if (parentClasses.size()>0)
    {

        QStringListIterator cls ( parentClasses );
        QString currentClass;
        addclasses = "";

        while (cls.hasNext())
         {
           currentClass = cls.next();
           if (currentClass == lastPar) {lastPar = cls.next(); continue;}
           if (addRequirements) {result.requirements.push_back(currentClass);};

           addclasses = addclasses +currentClass+',';
           lastPar = currentClass;
         };
        addclasses.remove(addclasses.size()-1, 1);

        addclasses = " extends " + addclasses;

    };

    QString lastVar = "";

    if (variables.size()>0)
    {
       variables.removeDuplicates();
       QStringListIterator vars ( variables );
       QString cleanName = "";
       QString variable = "";
       QString varsDeclarations = "";
       QString propertiesMethods = "";
       QString scope = "public";
       while (vars.hasNext())
       {
           cleanName = vars.next();
           if (cleanName == lastVar) {lastVar = vars.next(); continue;};
           if (getFirstLetter(cleanName) == ".")
            {
               scope = "private";
               cleanName = ignoreFirstLetter(cleanName);
            };
           if (getFirstLetter(cleanName) == "#")
            {
               scope = "protected";
               cleanName = ignoreFirstLetter(cleanName);
            };
           variable = cleanName;
           variable.prepend(scope + " $");
           variable.append(";\n\r");
           varsDeclarations.append(variable);
           if (makeProperties)
           {
           propertiesMethods.append(scope + " function set"+capfirst(cleanName)+"( $p ) {$this->" + cleanName + " = $p;return $this;}\r\n");
           propertiesMethods.append(scope + " function get"+capfirst(cleanName)+"( ) {return $this->" + cleanName +";}\r\n");
           };
           lastVar = cleanName;
       };
       funcdecl.prepend(propertiesMethods);
       funcdecl.prepend(varsDeclarations);
    };
   };

    result.className = args.at(1);    
    funcdecl.prepend("function __construct(){\r\n/* parent::__construct();*/\r\n}");
    classdecl = classwrapper(result.className+addinterfaces+addclasses, funcdecl);
    if (result.clsnamespace != "")
    {
      result.setMarkup(namespacewrapper(result.clsnamespace, classdecl));
    }
    else
    {
      result.setMarkup(classdecl);
    };

    return result;
}

