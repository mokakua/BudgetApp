#include "XmlFileManager.h"

void XmlFileManager::createFile(string fileName) {
    CMarkup dataXml;
    dataXml.AddElem("DATA");
    dataXml.IntoElem();
    dataXml.AddElem("Transaction");
    dataXml.AddChildElem("userId","1");
    dataXml.AddChildElem("info","Shopping");
    dataXml.AddChildElem("date","2000-01-01");
    dataXml.AddChildElem("value","156.50");
    dataXml.AddElem("Transaction");
    dataXml.AddChildElem("userId","1");
    dataXml.AddChildElem("info","Salary");
    dataXml.AddChildElem("date","2015-13-06");
    dataXml.AddChildElem("value","2500.00");
    dataXml.AddElem("Transaction");
    dataXml.AddChildElem("userId","1");
    dataXml.AddChildElem("info","Pub with friends");
    dataXml.AddChildElem("date","2021-31-03");
    dataXml.AddChildElem("value","199.99");
    dataXml.OutOfElem();
    dataXml.Save(fileName);
}

bool XmlFileManager::openFile(CMarkup* file, string fileName) {
    if (file->Load(fileName)) {
        return true;
    } else {
        cout << "Loading file: error." <<endl;
        return false;
    }
}
