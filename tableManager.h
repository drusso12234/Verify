#ifndef VERIFY0_1_TABLEMANAGER_H
#define VERIFY0_1_TABLEMANAGER_H

#include "dataObject.h"
#include <map>
#include <iostream>
#include <fstream>

class tableManager {
private:
    std::map<std::string, dataObject> table;
public:
    tableManager();

    void newEntry(std::string str, data data);

    std::string findEntry(std::string str);

    void exportToFile();
};


#endif //VERIFY0_1_TABLEMANAGER_H
