#include <iostream>
#include "Employee.h"
using namespace std;

int main(){
     cout << "The number of employees before the instantiation of any object is " 
        << Employee::getCount() << endl;



    // The following scope creates and destproys employee objects before main terminates 
    {
        Employee e1{"Susan", "Baker"};
        Employee e2{"Robert", "Butler"};

        //two objects now exist so we test the static set data member count with static member function getCount()
        cout << "The number of employess after the objects are instantiated is" 
            << Employee::getCount() << endl;
        cout << "\n\nEmployee 1: " << e1.getFirstName() << e1.getLastName()
            << "\nEmployee 2: " << e2.getFirstName() << e2.getLastName() << "\n\n";
    }


    cout << "Number of employes after all objects are deleted is " << Employee::getCount;      

}

