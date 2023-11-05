//Employees class-member function definitions
#include <iostream>
#include "Employee.h"
using namespace std;

// define and inialize static data member at gloabal namespace scope
unsigned int Employee::count{0}; // Cannot include kayword static

unsigned int Employee::getCount() {return count;}

Employee::Employee(const string& first, const string& last) : firstName(first) , lastName(last) {
    ++count;
    cout << "Employee counstructor for " << firstName <<  ' ' << lastName << endl;
}
Employee::~Employee(){ 
    cout << "~Employee() called for " << firstName << lastName << "\n"<< endl;
    --count; // Decrement the static count of employess...
}
string Employee::getFirstName() const {return firstName;}
string Employee::getLastName() const {return lastName;}
