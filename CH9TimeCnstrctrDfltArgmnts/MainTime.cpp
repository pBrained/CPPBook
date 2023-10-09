#include <iostream>
#include <stdexcept>
#include "Time.h"
using namespace std;

void displayTime(const string& message, const Time& time) {
    cout << message << "\nUniversal time: " << time.toUniversalString()
        << "\nStandard Time: \t" << time.toStandardString() << "\n\n";
}

int main() {
    Time t1;                // All arguments defaulted
    Time t2{2};             // Hour specified, minute and second defaulted
    Time t3{2,3};           // Hour and minute specified, second defaulted
    Time t4{3,4,5};         // Hour, Minute, and Second defaulted.

    cout << "Constructed with: \n\n";
    displayTime("tl arguments defauted", t1);
    displayTime("t2: Hour specified, minute and second defaulted", t2);
    displayTime("t3: Hour and minute specified, second defaulted", t3);
    displayTime("t4: Hour, Minute, and Second defaulted.", t4);

    try{
        Time t5{27 ,74, 99};
    }
    catch (invalid_argument& e) {
        cerr << "Exception while initalizeing t5: " << e.what() << endl;
    }
}