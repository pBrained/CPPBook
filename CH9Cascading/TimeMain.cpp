
#include <iostream>
#include "Time.h"
using namespace std;

int main() {
    Time t; // Create the time object...
    t.setHour(18).setMinute(45).setSecond(12);      //Cascaded function calls....

    cout << "Universial time: " << t.toUniversalString() << "\n Standard time: " << t.toStandardString();

    cout << "\n\n New Standard Time" << t.setTime(20,20,20).toStandardString();
}