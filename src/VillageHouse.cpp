#include "VillageHouse.h"
#include <sstream>

VillageHouse::VillageHouse(std::string o, Date d, int p, std::string v, int n)
    : Realty{o, d, p}, village_{v}, number_{n} {}

void VillageHouse::printAll() {
    std::cout << "Type: Village house\n";
    Realty::printAll();
    std::cout << "Village: " << village_ << std::endl << "Number: " << number_ << std::endl << std::endl;
}

void VillageHouse::read(std::istringstream &iss) {
    iss >> owner >> dateOfRegistration;
    iss >> price >> village_ >> number_;
}