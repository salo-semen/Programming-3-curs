#ifndef APARTMENT_H
#define APARTMENT_H

#include "Realty.h"

class Apartment : public Realty {
public:
    Apartment(std::string o, Date d, int p, std::string h, int n);
    void setHouse(std::string h);
    void setNumber(int n);
    void printAll() override;
private:
    std::string house_;
    int number_;
};

#endif // APARTMENT_H