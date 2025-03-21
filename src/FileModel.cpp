#include "FileModel.h"

FileModel::~FileModel() {
    for (auto& it : allRealty) {
        delete it;
    }
};

void FileModel::removeSelectedRow(int selectedRow) {
    if (allRealty.size() >= selectedRow)
        allRealty.erase(allRealty.begin() + selectedRow);
}

void FileModel::addNewRow() {
    Realty* r;
    allRealty.push_back(r);
}

void FileModel::init(std::string nameFile) {
    std::string line;
    std::ifstream in(nameFile);
    if (in.is_open()) {
        while (std::getline(in, line)) {
            std::istringstream iss(line);
            Realty* ob;
            std::string word;
            iss >> word;
            if (word == "Apartment") {
                ob = new Apartment;
                ob->read(iss);
            } else if (word == "VillageHouse") {
                ob = new VillageHouse;
                ob->read(iss);
            } 
            if (ob != nullptr)
                allRealty.push_back(ob);
        }
    } else {
        std::cout << "File is not exist";
    }
}