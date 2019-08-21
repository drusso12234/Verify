#ifndef VERIFY0_1_DATAOBJECTNODE_H
#define VERIFY0_1_DATAOBJECTNODE_H

#include "data.h"

struct dataObjectNode{
    dataObjectNode* next;
    data data;
};

typedef dataObjectNode* dataNodePtr;

#endif //VERIFY0_1_DATAOBJECTNODE_H
