#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Realty.h"
#include "Apartment.h"
#include "VillageHouse.h"
#include <QApplication>
#include <QWidget>

int main() {
    std::vector<Realty*> allRealty;

    std::string line;
    std::ifstream in("1.txt");
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
    }

    for (auto& it : allRealty) {
        it->printAll();
    }

    for (auto& it : allRealty) {
        delete it;
    }
}