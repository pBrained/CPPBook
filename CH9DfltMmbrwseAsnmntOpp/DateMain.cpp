#include <iostream>
#include "Date.h"
using namespace std;

int main() {
    Date date1{7,4,2004};  
    Date date2; // Date 2 defaults to, 1/1/2000

    cout << "date1 = " << date1.toString()
        << "\ndate2 = " << date2.toString() << "\n\n";
    
    date2 = date1;  // default memberwise assignment.

    cout << "After default memberwise assignement, date2 = "
    << date2.toString() << endl;
}
