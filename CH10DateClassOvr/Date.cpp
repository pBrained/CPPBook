#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

// Initialize the static member; one class wise copy
const array<unsigned int, 13> Date::days{       
    0,31,28,31,30,31,30,31,31,30,31,30,31};


// Date constructor
Date::Date(int month, int day, int year) {
    setDate(month, day, year);
}

void Date::setDate(int mm, int dd, int yy) {
    if(mm >= 1 && mm <= 12){
        month = mm;
    }
    else{
        throw invalid_argument("Month must be 1 - 12");
    }
    if(yy >= 1900 && yy <= 2100){
        year = yy;
    }
    else{
        throw invalid_argument("year must be 1900-2100");
    }
    if((mm == 2 && leapYear(year) && dd >= 1 && dd <= 29) || (dd >= 1 && dd <= days[mm])){
        day = dd;
    }
    else {
        throw invalid_argument{"day is out of range for the curent month and year"};
    }
}

// Overloaded prefix incrmemnt opreator 
Date& Date::operator++() {
    helpIncrement();
    return *this;   
}
Date Date::operator++(int) {
    Date temp {*this};
    helpIncrement();
    return temp;
}

Date& Date::operator+=(unsigned int additionalDays) {
    for(unsigned int i = 0; i < additionalDays; ++i){
        helpIncrement();
    }
    return *this; // enables cascading
}
// if the year is a leap year; return true; other wise return false

bool Date::leapYear(int testYear) {
    return (testYear % 400 == 0 ||
    (testYear % 100 != 0 && testYear % 4 == 0));
}
bool Date::endOfMonth(int testDay)  const {
    if (month == 2 && leapYear(year)) {
        return testDay == 29;
    }
    else {
        return testDay == days[month];
    }
}

void Date::helpIncrement() {
    if(!endOfMonth(day)) {
        ++day; // increment day
    }else {
        if(month < 12) {
            ++month;
            day = 1;
        }else{
            ++year;
            month;
            day = 1;
        }
    }
}

ostream& operator <<(ostream& output, const Date& d) {
    static string monthName[13] {
        "", "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "August", "Sep", "Oct", "Nov", "Dec"};
    
    output << monthName[d.month] <<  ' ' << d.day << ", " << d.year;
    return output;
}



















