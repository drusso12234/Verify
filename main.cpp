#include "tableManager.h"
void importFromFile(tableManager& table);
int main() {
    tableManager table;
    importFromFile(table);
    bool reallyDone = false;
    while (!reallyDone){
        std::cout << "Welcome to Verify v0.1\nEnter e to enter data or q to search data or c to quit" << std::endl;
        char choice;
        std::string tag;
        data userData;
        bool done = false;
        std::cin >> choice;
        switch (choice){
            case 'e' :
                while (!done){
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Please enter the tag, then press enter." << std::endl;
                    std::cout << "format is: noun:relation:noun - spaces are fine" << std::endl;
                    std::getline(std::cin, tag);
                    std::cout << "Now enter the articleID, pValue, and note. Press enter after each one" << std::endl;
                    std::getline(std::cin, userData.articleID);
                    //std::cout << "Now enter the pValue" << std::endl;
                    std::getline(std::cin, userData.pValue);
                    //std::cout << "Now enter the note" << std::endl;
                    std::getline(std::cin, userData.note);
                    std::cout << "If everything you just entered is correct, press y and enter, "
                                 "otherwise press n and enter, or press q to quit" << std::endl;
                    std::cin >> choice;
                    if (choice == 'n') {
                        std::cout << "The process will now start over" << std::endl;
                    }
                    if (choice == 'y'){
                        table.newEntry(tag, userData);
                        std::cout << "Would you like to enter more data? y for yes n for no" << std::endl;
                        std::cin >> choice;
                        if (choice != 'y') {
                            done = true;
                            break;
                        }
                    }
                    if (choice == 'q') {
                        done = true;
                        break;
                    }
                }
                break;
            case 'q':
                while (!done){
                    std::cout << "Enter the tag you wish to search for" << std::endl;
                    std::cin >> tag;
                    std::cout << table.findEntry(tag) << std::endl;
                    std::cout << "Do you want to search again? y for yes, n for no" << std::endl;
                    std::cin >> choice;
                    if (choice == 'n'){
                        done = true;
                        break;
                    }
                    std::cout << "starting over" << std::endl;
                }
                break;
            case 'c':
                reallyDone = true;
        }
    }
    table.exportToFile();
}

void importFromFile(tableManager& table){
    std::string line;
    std::string tag;
    data userData;
    std::ifstream myfile("testData.txt");
    size_t counter = 0;
    size_t numDataFields = 3; //data fields plus one for tag
    if (myfile.is_open()) {
        getline(myfile, line);
        tag = line;
        while (getline(myfile, line)) {
            if (line != "") {
                if (counter % numDataFields == 0) {
                    userData.articleID = line;
                }
                if (counter % numDataFields == 1) {
                    userData.pValue = line;
                }
                if (counter % numDataFields == 2) {
                    userData.note = line;
                    //move this to last if when adding more data
                    table.newEntry(tag, userData);
                }
                counter++;
            }
            else {
                counter = 0;
                getline(myfile, line);
                tag = line;
            }
        }
    }
    else {
        std::cout << "Unable to open saved data - "
                "please check for data.txt file in this folder" << std::endl;
    }
    myfile.close();
}

