#include <iomanip>
#include <sstream>
#include <stdexcept>
#include "Time.h"
using namespace std;

// Constructor function to initialize private data...
// Calls member function setTime to set the variable...
// Default values are set to 0 (Se default constructor int time h)
Time::Time(int hr, int min, int sec){
    setTime(hr, min, sec);
}

Time& Time::setTime(int h, int m , int s){
    setHour(h);
    setMinute(m);
    setSecond(s);
    return *this;       //Enables cascading... by returning a pointer to the new object?
}

// Set Hour Value

Time& Time::setHour(int h) { // "Note Time& return"
    if (h >= 0 && h < 24) {
        hour = h;
    }
    else {
        throw invalid_argument("Hour must be a value between 0-23");
    }
    return *this;           // Enables cascading??? Apparently...?
}
Time& Time::setMinute(int m) { // "Note Time& return"
    if (m >= 0 && m < 60) {
        minute = m;
    }
    else {
        throw invalid_argument("Minute must be a value between 0-59");
    }
    return *this;           // Enables cascading??? Apparently...?
}

Time& Time::setSecond(int s) { // "Note Time& return"
    if (s >= 0 && s < 60) {
        second = s;
    }
    else {
        throw invalid_argument("Second must be a value between 0-59");
    }
    return *this;           // Enables cascading??? Apparently...?
}


// Get Hour Value...
unsigned int Time::getHour() const {return hour;}
// Get Minute Value...
unsigned int Time::getMinute() const {return minute;}
// Get Second Value...
unsigned int Time::getSecond() const {return second;}


//Return the time as a sting in universal time format (HH:MM:SS)
string Time::toUniversalString() const {
    ostringstream output;
    output << setfill('0') << setw(2) << getHour() << ":"
        << setw(2) << getMinute() << ":" << setw(2) << getSecond();
        return output.str();
}
// Return Time as a stinr gin standard-time format (HH:MM:SS AM or PM)
string Time::toStandardString() const {
    ostringstream output;
    output << setfill('0') << setw(2) << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
        << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2)
        << getSecond() << (hour < 12 ? " AM" : " PM"); 
    return output.str();
}

