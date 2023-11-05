#include <string>

//Time class definition
//Member functions defined in Time.cpp

#ifndef TIME_H
#define TIME_H


class Time {
    public:
        explicit Time(int = 0, int = 0, int = 0);   // Default Constructor
        Time& setTime(int, int, int);               // setting the variables...
        Time& setHour(int);                         // setting the variables...
        Time& setMinute(int);                       // setting the variables...    
        Time& setSecond(int);                       // setting the variables...        
    

    unsigned int getHour() const;    
    unsigned int getMinute() const;
    unsigned int getSecond() const;    

    std::string toUniversalString() const;
    std::string toStandardString() const;

    private:
    unsigned int hour{0};
    unsigned int minute{0};    
    unsigned int second{0};
};
#endif