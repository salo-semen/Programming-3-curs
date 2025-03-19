#include "Realty.h"

Realty::Realty(std::string o, Date d, int p) : owner{o}, dateOfRegistration{d}, price{p} {}

std::string Realty::getOwner() const {
    return owner;
}

Date Realty::getDateOfRegistration() const {
    return dateOfRegistration;
}

int Realty::getPrice() const {
    return price;
}

void Realty::setOwner(std::string o) {
    owner = o;
}

void Realty::setDateOfRegistration(Date d) {
    dateOfRegistration = d;
}

void Realty::setPrice(int p) {
    price = p;
}

void Realty::printAll() {
    std::cout << "Owner: " << owner << std::endl;
    dateOfRegistration.print();
    std::cout << "Price: " << price << std::endl;
}

std::string Realty::getAll() {
    return (owner + " " + dateOfRegistration.getAll() + " " + std::to_string(price));
}