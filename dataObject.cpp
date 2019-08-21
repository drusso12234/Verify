//
// Created by druss on 5/15/2019.
//

#include "dataObject.h"

dataObject::dataObject() : head(nullptr), numData(0){

}

dataObject::dataObject(const dataObject& rhs) :
        numData(rhs.numData),
        head(nullptr)
{
    if (rhs.head != nullptr){
        head = new dataObjectNode;
        head->data = rhs.head->data;
        head->next = nullptr;
        dataNodePtr newPtr = head;
        for (dataNodePtr cur = rhs.head->next; cur != nullptr; cur = cur->next){
            newPtr->next = new dataObjectNode;
            newPtr = newPtr->next;
            newPtr->data = cur->data;
            newPtr->next = nullptr;
        }
    }
}

// Assignment operator
const dataObject& dataObject::operator= (const dataObject& rhs)
{
    if (this != &rhs) {
        dataObject tmp(rhs); //Why does this automatically delete itself?
        std::swap(numData, tmp.numData);
        std::swap(head, tmp.head);
    }
    return *this;
}


// Destructor
dataObject::~dataObject()
{
    dataNodePtr current = head;
    while(current != nullptr) {
        dataNodePtr next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

void dataObject::addData(data obj) {
    if (head == nullptr) {
        head = new dataObjectNode;
        head ->next = nullptr;
        head->data = obj;
    }
    else {
        dataNodePtr cur = head;
        while (cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = new dataObjectNode;
        cur = cur->next;
        cur->next = nullptr;
        cur->data = obj;
        //delete cur
    }
    ++numData;
}

size_t dataObject::getNum() {
    return numData;
}

std::string dataObject::getData() {
    std::string returnData = "";
    for (dataNodePtr cur = head; cur != nullptr; cur = cur->next) {
        returnData += cur->data.articleID + "\n";
        returnData += cur->data.pValue + "\n";
        returnData += cur->data.note + "\n";
    }
    return returnData;
}

