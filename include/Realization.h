#ifndef REALIZATION_H
#define REALIZATION_H

#include <iostream>
#include <vector>
#include <QTableWidget>
#include <fstream>
#include "Realty.h"
#include "Apartment.h"
#include "VillageHouse.h"

class Realization {
public:
    Realization() {};
    Realization(std::string nameFile) {init(nameFile);};
    ~Realization();
    QTableWidget* createTable();
    void removeSelectedRow(QTableWidget* table);
    void addNewRow(QTableWidget* table);

private:
    std::vector<Realty*> allRealty;
    void init(std::string nameFile);
};

#endif // REALIZATION_H