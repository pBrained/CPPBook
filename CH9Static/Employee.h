#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
class Employee{ 
    public:
         Employee(const std::string&, const std::string&);  // Constructor
         ~Employee(); // Deconstructor 
         std::string getFirstName() const;
         std::string getLastName() const;


        // Static member function
        static unsigned int getCount();        // return the number of objects
    private:
        std::string firstName;
        std::string lastName;

        // Static data
        static unsigned int count;              // Number of objects instansiated..

};

#endif