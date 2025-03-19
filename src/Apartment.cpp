#include "Apartment.h"
#include <iostream>
#include <sstream>

Apartment::Apartment(std::string o, Date d, int p, std::string h, int n)
    : Realty{o, d, p}, house_{h}, number_{n} {}

void Apartment::setHouse(std::string h) {
    house_ = h;
}

void Apartment::setNumber(int n) {
    number_ = n;
}

void Apartment::printAll() {
    std::cout << "Type: Apartment\n";
    Realty::printAll();
    std::cout << "House: " << house_ << std::endl << "Number: " << number_ << std::endl << std::endl;
}

void Apartment::read(std::istringstream &iss) {
    iss >> owner >> dateOfRegistration;
    iss >> price >> house_ >> number_;
}
std::string Apartment::getAll() {
    return ("Apartment " + Realty::getAll() + " " + house_ + " " + std::to_string(number_));
}