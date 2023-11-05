#include <iostream>
#include "PhoneNumber.h"
using namespace std;

int main() {
    PhoneNumber phone;
    cout << "Enter the phone numberb in the form (555)555-5555: " << endl;

    cin >> phone;

    cout << "The phone number was: \n";

    cout << phone << endl;

    
}
