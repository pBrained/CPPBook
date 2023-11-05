#include <iostream>
using namespace std;

class Test{
    public:
        explicit Test(int);
        void Print() const;
    private:
        int x{0};
    };

    Test::Test(int value) : x{value} {} // Initialize x to value...
    

    // Now we print x uing the imlicit and expicit this pointers....
    // the perenthesis around the *this are required

    void Test::Print() const {
        cout << "\nx: \t\t" << x;
        //implicityl use the this poitner to access x
        cout << "\nthis->x: \t" << this-> x;
        //explicitly use the this pointer and arrow opperator to access the member x
        cout << "\n(this*).x: \t" << (*this).x;
    }

    int main(){
        Test TestObject{12};
        TestObject.Print();
    }