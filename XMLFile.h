#ifndef XMLFILE_H
#define XMLFILE_H
#include <iostream>
#include "Markup.h"

using namespace std;

class XMLFile {
protected:
    string name;
    CMarkup file;

public:

    XMLFile(string name);

};
#endif // XMLFILE_H
