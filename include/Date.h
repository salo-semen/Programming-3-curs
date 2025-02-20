#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
public:
    Date(int day, int mounth, int year);
    Date() {};
    ~Date() {};
    void print();

private:
    int year_;
    int mounth_;
    int day_;
};

#endif // DATE_H