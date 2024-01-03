#include <iostream>
#include "Date.h"
using namespace std;

int main(){
    Date d1{12, 27, 2010};
    Date d2;   // Should use the default constructor to be January 1 1900;
    
    cout << "d1 is " << d1 << "d2 is " << d2 << endl;
    cout << "d1 + 7 is " << (d1 += 7);

    d2.setDate(2, 28, 2008);
    cout << "\n\n d2 is now" << d2;
    cout << "\n+d2 is " << ++d2 << "leap year allows the 29th";
    Date d3{7,13,2010};

    cout << "\n\nTesting the prefix increment operator";
    cout << "\n d3 is " << d3;
    cout << "\n ++d3 is " << ++d3;
    cout << "\n d3 is" << d3 << endl;

    cout << "\n\nTesting the post incrmement opperator";
    cout << "\n d3 is " << d3;
    cout << "\n d3++ is "<< d3++;
    cout << "\n d3 is" << d3; 

}   