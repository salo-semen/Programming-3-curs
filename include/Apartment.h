#ifndef APARTMENT_H
#define APARTMENT_H

#include "Realty.h"

class Apartment : public Realty {
public:
    Apartment(std::string o, Date d, int p, std::string h, int n);
    Apartment() = default;
    void setHouse(std::string h);
    void setNumber(int n);
    void printAll() override;
    void read(std::istringstream &iss) override;
    std::string getAll() override;
private:
    std::string house_;
    int number_;
};

#endif // APARTMENT_H