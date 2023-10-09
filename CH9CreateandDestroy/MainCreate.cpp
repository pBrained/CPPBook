#include <iostream>
#include "CreateandDestroy.h"
using namespace std;


CreateAndDestroy first(1, "(global before main)");  // Global object
void create();

int main()  {
    cout << "\nMain Function: execution begins" << endl;
    CreateAndDestroy second(2, "local object inside main");
    static CreateAndDestroy third{3, "local static object inside main"};

    create();   // Call function to create objects

    cout << "\nMain function: execution resumes" << endl;
    CreateAndDestroy fourth(4, "local in main");
    cout << "\nMain function: exectuion ends" << endl;
}

void create() {
    cout << "\nCreate function: execution begins" << endl;
    CreateAndDestroy fifth(5, "(local in create)");
    static CreateAndDestroy sixth(6, "local static in create");
    CreateAndDestroy seventh{7, "(local in create)"};
    cout << "\nCreate function: execution ends";
}
