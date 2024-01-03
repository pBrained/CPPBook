#ifndef DATE_H
#define DATE_H

#include <array>
#include <iostream>

class Date{
    friend std::ostream& operator<<(std::ostream&, const Date&);
public:
    Date(int m = 1, int d = 1, int y = 1900);
    void setDate(int, int, int);
    Date& operator++();             // Prefix incremement operator
    Date operator++(int);           // Postfix increment operator
    Date& operator+=(unsigned int);  // add days modify object
    static bool leapYear(int);      // is year a leap year
    bool endOfMonth(int) const;
private:
    unsigned int month;
    unsigned int day;
    unsigned int year;

    static const std::array <unsigned int, 13> days;// days per month
    void helpIncrement();//utility function for incrementing day

};

#endif