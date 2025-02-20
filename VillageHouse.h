#ifndef VILLAGEHOUSE_H
#define VILLAGEHOUSE_H

#include "Realty.h"

class VillageHouse : public Realty {
public:
    VillageHouse(std::string o, Date d, int p, std::string v, int n);

    void printAll();
private:
    std::string village_;
    int number_;
};

#endif // VILLAGEHOUSE_H