//
// Created by druss on 7/1/2019.
//

#include "tableManager.h"
tableManager::tableManager() {

}

std::string tableManager::findEntry(std::string str) {
    std::map<std::string, dataObject>::iterator it;
    for (it = table.begin(); it != table.end(); ++it){
        if (it->first == str) {
            std::string data = it->second.getData();
            return data;
        }
    }
    return "";
}

void tableManager::newEntry(std::string str, data data) {
    table[str].addData(data);
}

void tableManager::exportToFile() {
    std::ofstream myfile("data.txt");
    std::map<std::string, dataObject>::iterator it;
    if (myfile.is_open()) {
        for (it = table.begin(); it != table.end(); ++it){
            myfile << it->first + "\n";
            myfile << it->second.getData() + "\n";
        }
    }
    else{
        std::cout << "Could not open file data.txt" << std::endl;
    }
    myfile.close();
}