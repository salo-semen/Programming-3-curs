#ifndef REALTY_H
#define REALTY_H

#include "Date.h"


class Realty {
public:
    Realty(std::string o, Date d, int p);
    Realty() = default;
    virtual ~Realty() = default;

    std::string getOwner() const;
    Date getDateOfRegistration() const;
    int getPrice() const;

    void setOwner(std::string o);
    void setDateOfRegistration(Date d);
    void setPrice(int p);

    virtual void printAll();
    virtual void read(std::istringstream &iss) = 0;
    
protected:   
    std::string owner;
    Date dateOfRegistration;
    int price;
};

#endif // REALTY_H