#include <help.h>

OutProduct help()
{
    OutProduct result;

    result.markup = "/* Use\n\r ./genphpclass yourClassName [v:v1,v2] [m:f1,f2] [i:interface1,interface2] [e:parentClass,parentClass2] [-w] [-p]";
    result.markup.append("\r\n Use v:v1,v2 to declare variables $v1, $v2");
    result.markup.append("\r\n Use m:f1,f2 to declare methods $v1, $v2");
    result.markup.append("\r\n Use e:parentClass1,parentClass2 to inherit behaviour from parent classes");
    result.markup.append("\r\n Use i:interface1,interface2 to declare implementation of interfaces");
    result.markup.append("\r\n Use c:childClass1,childClass2 to make code of child classes");
    result.markup.append("\r\n Use u: to add directives 'use'");
    result.markup.append("\r\n Use n: to wrap class into namespace");
    result.markup.append("\r\n Use -p to declare settings and getters");
    result.markup.append("\r\n Use -w to write file named yourClassName.php");
    result.markup.append("\r\n Use -r to add requirements by names passed in i: and e: keys");
    result.markup.append("\r\n Use prefix # to generate protected functions or variables, for example: v:#protectedVariable");
    result.markup.append("\r\n Use prefix . to generate private functions or variable, for example: m:.privateFunc");
    result.markup.append("\r\n */");
    result.filename = "";
    result.options = "";
    return result;
}
