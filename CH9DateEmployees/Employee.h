#include <string>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h"        // Include Date class definition

class Employee {
    public:
        Employee(const std::string&, const std::string&, const Date&, const Date&);
        std::string toString() const;
        ~Employee();
    private:
        std::string firstName;
        std::string lastName;
        const Date birthDay;
        const Date hireDay;
};

#endif 