#include <iostream>
#include "Time.h"
using namespace std;

int main() {
    Time t;

    // initialize hourRef with the reference returned by badSetHour
    unsigned int& hourRef{t.badSetHour(20)};// Statements in main should not have access to private data members.
    cout << "Valid hour before modification: " << hourRef;
    hourRef = 30;   // use hourRef to set invalid value in Time object t
    cout << "\nInvalid hour after modification: " << t.getHour();
    

    // Dangerous function call that returns a reference can be used as a lvalue!!!
    t.badSetHour(12) = 74;      // assigining another invalid value to hour
    
    cout << "\n\n***************************\n"
    << "POOR PROGRAMMING PRATICE!!!\n"
    << "t.badSetHour(12) as an lvalue, invalid hour: "
    << t.getHour()
    << "\n***********************************" << endl;
}

