#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Realty.h"
#include "Apartment.h"
#include "VillageHouse.h"

int main() {
    std::vector<Realty*> allRealty;

    std::string line;
    std::ifstream in("1.txt");
    if (in.is_open()) {
        while (std::getline(in, line)) {
            std::istringstream iss(line);
            std::string word;
            iss >> word;
            if (word == "Apartment") {
                std::string owner, house;
                int day, month, year, price, number;
                iss >> owner >> day >> month >> year >> price >> house >> number;
                Realty* ob = new Apartment(owner, {day, month, year}, price, house, number);
                allRealty.push_back(ob);
            } else if (word == "VillageHouse") {
                std::string owner, village;
                int day, month, year, price, number;
                iss >> owner >> day >> month >> year >> price >> village >> number;
                Realty* ob = new VillageHouse(owner, {day, month, year}, price, village, number);
                allRealty.push_back(ob);
            } 
        }
    }

    for (auto& it : allRealty) {
        it->printAll();
    }

    for (auto& it : allRealty) {
        delete it;
    }
}