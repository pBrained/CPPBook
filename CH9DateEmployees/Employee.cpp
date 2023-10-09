#include <iostream>
#include <sstream>
#include "Employee.h"
#include "Date.h"
using namespace std;

Employee::Employee(const string& first, const string& last, const Date &dateOfBirth, const Date &dateOfHire)
    : firstName{first},
    lastName{last},
    birthDay{dateOfBirth},
    hireDay{dateOfHire} {
    
        cout << "Employee object constructor " << firstName << ' ' << lastName << endl;
    
}

string Employee::toString() const {
    ostringstream output;
    output << lastName << "," << firstName << "  Hired:  "
        << hireDay.toString() << "  Birthday: " << birthDay.toString();
    return output.str();
}
// output Employee object to 
Employee::~Employee()  {
    cout << "Employee object decstructor: "
        << lastName << ',' << firstName << endl; 
}
