#include "Date.h"

Date::Date(int day, int mounth, int year) {
    if (year >= 1900 && year <= 2025 && mounth >= 0 && mounth <= 12 && day >= 1 && day <= 31) {
        year_ = year;
        mounth_ = mounth;
        day_ = day;
    } else {
        std::cout << "Error, bad date" << std::endl;
    }
}

void Date::print() {
    std::cout << "Date: " << day_ << "." << mounth_ << "." << year_ << std::endl;
}