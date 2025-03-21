#ifndef FILEMODEL_H
#define FILEMODEL_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Realty.h"
#include "Apartment.h"
#include "VillageHouse.h"

class FileModel {
public:
    FileModel() {};
    FileModel(std::string nameFile) {init(nameFile);};
    ~FileModel();
    void removeSelectedRow(int selectedRow);
    void addNewRow();
    std::vector<Realty*>& getAllRealy() {return allRealty;};

private:
    std::vector<Realty*> allRealty;
    void init(std::string nameFile);
};

#endif // FILEMODEL_H