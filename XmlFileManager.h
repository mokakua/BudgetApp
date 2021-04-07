#ifndef XMLFILEMANAGER_H
#define XMLFILEMANAGER_H
#include <iostream>
#include "Markup.h"

using namespace std;

class XmlFileManager {

public:
    XmlFileManager() {};
    ~XmlFileManager() {};

    void createFile(string fileName);
    bool openFile(CMarkup* file, string fileName);
};
#endif // XMLFILEMANAGER_H
