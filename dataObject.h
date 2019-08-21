#ifndef VERIFY0_1_DATAOBJECT_H
#define VERIFY0_1_DATAOBJECT_H

#include "dataObjectNode.h"

class dataObject{
private:
dataNodePtr head;
size_t numData;
public:
std::string getData();

dataObject();

dataObject(const dataObject& rhs);

~dataObject();

const dataObject& operator= (const dataObject& rhs);

void addData(data obj);

size_t getNum();
};
#endif //VERIFY0_1_DATAOBJECT_H
