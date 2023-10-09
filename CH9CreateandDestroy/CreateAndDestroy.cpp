#include <iostream>
#include "CreateAndDestroy.h"
using namespace std;

// Constructor
CreateAndDestroy::CreateAndDestroy(int ID, string messageString)
    : objectID{ID}, message{messageString} {
    cout << "Object " << objectID << "   constructor runs    " << message << endl;
}

// Deconstructor 

CreateAndDestroy::~CreateAndDestroy() {
    cout << (objectID == 1 || objectID == 6 ? "\n" : "");
    cout << "object: " << objectID << "     Deconstrucor runs   " << message << endl;
}