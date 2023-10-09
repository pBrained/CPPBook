/*
------------------------------------------Templates Array and Vector--------------------------------


Data Structres

    Arrays:
        - " Fixed size containing elements of the same type"

    Vectors:
        - " Dynamic size containing elements of the same type"

    Both are C++ standard library templates.


    Now we learn how tro search arrays for a specific element and put their data in a specific order.


To refer to a element in a array we include a positon number also known as a subscript or index

First element is subscript 0(zero) also known as the zeroth element.

this is why the elements of array c are pronounced "c sub zero" e.g c[0]

c[a + b] += 2  adds 2 to element c[11] if a is = to 6 and b is = to 5

the name of the entiree arraw is c
the array knows its own size and we can find this out by calling size.

we refer to elements as their array name and subscript number so as to not get confused 
and cause off by one erroers

the brackets that enclose a subscript are acutally a opperator that has the same pecedence 
as parathensis used to call a function.

Opperators, Associativity, Type

:: (), left to right, primary
() [] ++ == static_cast<type>(opperand), left to right, postfix 
++ -- + = !, right to left, unary (prefix)
* / %, left to right, multiplicitive
+ - , left to right, additive 
<< >> , left to right, insertion / extraction
< <= > >= , lkeft to right, relational
== != , left to right, equality
&& , left to right, logical AND 
|| , left to right, logical OR
?: , right to left, conditional
= += -= *= /= %= , left to right, assignment
(comma) , left to right, comma
 
Declaring an array

array < type, arraySize > arrayName;
array < int, 12> c; // c is an array of twelve int value

*/
/*
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

int main() {
    array <int, 5> n;
// The incrementation of i happens at the end of each run of the loop whether or not you use pre or post increment
    for(size_t i{0}; i < n.size(); ++i){
        n[i] = 0;
    }
    cout << "Element" << setw(10) << "Value" << endl;
    for(size_t j{0}; j < n.size(); ++j){
        cout << setw(7) << j << setw(10) << n[j] << endl;
    }

// size_t is a unsigned interger type recomended for any variable that represents 
// an array's sze and or an arrays subscipts.
// size_t is defined is in the header <cstddef>  which is included in many other headers
// so if you compile a program that uses size_t and it returns undefined then inculde <cstddef>
}

arrays can be initialized with an initializer list
*/
/*
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

int main(){
    array<int, 5> n{37,32,4,34,56};
    cout << "Element" << setw(10) << "Value" << endl;
    for(size_t i{0}; i < n.size(); i++){
        cout << setw(7) << i << setw(10) << n[i] << endl;
    }
}


                declare empty array
                array<int,5> n{}; initialize all elements of array n to 0
*/

//int main(){
//    const size_t arraySize{5}; Making the array size is recomended because a eddieted constant will return 
// a error and we will remove magic numbers.
//}

/*
#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>
using namespace std;
                        // Die Rolling program using array instead of switch

int main() {
    // use the default random-number generatoion engine to produce uniformely
    // distributed psuedorandom int values from 1 to 6
    default_random_engine engine(static_cast<unsigned int> (time(0)));
    uniform_int_distribution<unsigned int> randomInt(1, 6);

    const size_t arraySize{7};
    array<unsigned int, arraySize> frequency{};
    
    for (unsigned int roll{1}; roll <= 60'000'000; ++ roll) {
        ++frequency[randomInt(engine)];
    }
    
    cout << "Face" << setw(13) << "Frequency" << endl;

    for (size_t face{1}; face < frequency.size(); ++face){
        cout << setw(4) << face << setw(13) << frequency[face] << endl;
    }
}
*/

// When you write programs that read and edit the bounds of a array you create security flaws
// Reading from an out of bounds element can cause a program to crass or even appear to execute properly
// and Writing to a qout of bounds element, is a buffer overflow 
// refering to out of bounds elements is a logic error not syntax errore

/*
---------------------------------------Static Arrays-------------------------------------------------------

        We can apply static to a local array declaration so that its not created and initialized
        Each time the programs calls the function and is not destroyed each thime the function
        terminates. this can imporve preformance especially when using larger arrays.
    
    local variables are sometiumes called automatic variables because thir automatically destroyed 
    when the function finishes executing 

    The seccond time the function is called, the static array contains the modified values stored 
    durring the first function call.
*/
/*
#include <iostream>
#include <array>
using namespace std;

void staticArrayInit();
void automaticArrayInit();
const size_t arraySize{3};

int main () {
    cout << "First call to each function: \n";
    staticArrayInit();
    automaticArrayInit();

    cout << "\n\nSecoond call to each function:\n";
    staticArrayInit();
    automaticArrayInit();
    cout << endl;
}

void staticArrayInit(void) {

    static array<int, arraySize> array1;

    cout << "\nValues on entering staticArrayInit:";

    for (size_t i{0};  i < array1.size(); ++i) {
        cout << "\narray1[" << i <<  "] = " << array1[i] <<  " ";
    }

    cout << "\n\nValues on exiting staticArrayInit:";

    for(size_t j{0}; j < array1.size(); ++j) {
        cout << "\narray1[" << j <<  "] = " << (array1[j] += 5) <<  " ";
    }
}
void automaticArrayInit(void) {

    array<int, arraySize> array2{1,2,3};

    cout << "\nValues on entering staticArrayInit:";

    for (size_t i{0};  i < array2.size(); ++i) {
        cout << "\narray2[" << i <<  "] = " << array2[i] <<  " ";
    }

    cout << "\n\nValues on exiting staticArrayInit:";

    for(size_t j{0}; j < array2.size(); ++j) {
        cout << "\narray2[" << j <<  "] = " << (array2[j]+=5) <<  " ";
    }
}
*/

/*
----------------------------------Range Based Looping Array--------------------------------------------

    Range based for statement allows you to loop through an array without a counter
 
-------------------------------------------------------------------------------------------------
*/
/*
#include <iostream>
#include <array>
using namespace std;

int main() {

    array<int, 5> items{1, 2, 3, 4, 5};
    cout << "Items before modification: ";
    for(int number: items) { // Reads like for each iteration assign the next of items to
        cout << number << " ";// Int Variable item then execute the bodys loop
    }

    for (int& itemRef : items) {    // Reference is alias for another variable in memory in
        itemRef *= 2;               // This case we reference one of the arrays elements
    }                               // We use a int refrence, because items contains int
                                    // AND we want to modify each elements value
    cout << "\nitems after modification: ";
    for (int item: items) {
        cout << item << " " ;
    }
    cout << endl;
}
*/
// Testing the gradebook.h  

/*
#include <array>
#include "GradeBook.h"
using namespace std;

int main() {
    const array<int, GradeBook::students> grades {
        89,98,67,45,89,98,34,67,87,96};
    string courseName{"CS101 Introduction to C++ Programing"};

    GradeBook myGradeBook(courseName, grades);
    myGradeBook.displayMessage();
    myGradeBook.processGrades();
}
*/

/*
-------------------------------------------------------------------------------------------------------------------------------
                                                            
                                                    Sorting Arrays

-------------------------------------------------------------------------------------------------------------------------------

            "Sorting data by placing it into accending or decending order is one of the most 
                    impotant computing functions"


sort: 
    is used to arrange the elements ain a array in accending order

binary_search:
    is used to dermine whether or not a value is in a Array 


            When looking for a key value in a array we search

*/
/*

#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    const size_t arraySize{7};
    array<string, arraySize> colors {"red", "yellow", "green", "blue", "purple"};

    cout << "\n\n\nUnsorted array: ";
    for(string color : colors) {
        cout << color << " ";
    }
    cout << "\n";

    sort(colors.begin(), colors.end());

    cout << "Sorted array: ";
    for(string color : colors) {
        cout << color << " ";
    }

    cout << "\n";

    bool found{binary_search(colors.begin(), colors.end(), "blue")};
    cout << "\nblue " << (found ? "was " : "was not ") << "there " << endl;

    found = binary_search(colors.begin(), colors.end(),"cyan");
    cout << "\ncyan " << (found ? "was ": "was not ") << "there " << endl;

}
*/
/*
#include <iostream>
#include <array>
using namespace std;

const size_t rows{2};
const size_t columns{3};
void printArray(const array<array<int, columns>, rows>&);
void printArray2(const array<array<int, columns>, rows>&);
void printArray3(const array<array<int, columns>, rows>&);
int sumArray(const array<array<int, columns>, rows>&);
int main () {

    array<array<int, columns>, rows> array1{1, 2, 3, 4, 5, 6};
    array<array<int, columns>, rows> array2{1, 2, 3, 4, 5};
    
    cout << "Values in array1 by row are:" << endl;
    printArray(array1);
     
    cout << "Values in printarray2 by row are:" << endl;
    printArray2(array2);

    cout << "Values in printArray3(array2) are: " << endl;
    printArray3(array2);

    cout << "Sum of values in Array 2 is : " << sumArray(array2) << endl;
}
void printArray(const array<array<int, columns>, rows>& a) {
    for(auto const& row : a) {
        for(auto const& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}
void printArray2(const array<array<int, columns>, rows>& b) {
    for(size_t row{0}; row < b.size(); ++row) {
        for (size_t column{0}; column < b[row].size(); ++column) {
            cout << b[row][column] << ' ';
        }

        cout << endl;
    }
}
void printArray3(const array<array<int, columns>, rows>& c) {
    for(auto row : c) {
        for(auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}
int sumArray(const array<array<int, columns>, rows>& d) {
    int total{0};
    for(auto row : d){
        for(auto elements : row){
            total += elements;
        }
    }
    return total;
}
*/
/*
    The different ways to itterate.

    Auto keyword
    for(auto row : a) {
        for (auto column : row) {
            total += column;
        }
    }
    for(int i{0}; i < row.size(); i++) {}
    for(int row : rows) {}
    for(auto rows: row)
*/
/*
#include <array>
#include "GradeBook.h"
using namespace std;

int main() {
    array<array<int, GradeBook::tests>, GradeBook::students> grades
    {
        {{87, 96, 70},
        {68, 87, 90},
        {94, 100, 90},
        {100, 81, 82},
        {83, 65, 85},
        {78, 87, 65},
        {85, 75, 83},
        {91, 94, 100},
        {76, 72, 84},
        {87, 93, 73}}
    };          

        GradeBook myGradeBook("CS101 Introduct6ion to C++ programing", grades);
        myGradeBook.displayMessage();
        myGradeBook.processGrades();
    
}
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
using namespace std;

void outputVector(const vector<int>&);
void inputVector(vector<int>&);

int main(){
    vector<int> intergers1(7);      // 7 element vector
    vector<int> intergers2(10);    // 10 element vector

    cout << "Size of vector intergers1 is " << intergers1.size()
        << "\nvector after initialization:";
        outputVector(intergers1);

    cout << "Size of vector intergers2 is " << intergers2.size()
        << "\nvector after initialization:";
        outputVector(intergers2);

    cout << "\n Enter 17 intergers: " << endl;
    inputVector(intergers1);
    inputVector(intergers2);

    cout << "\n After input the vectors contain:\n"
        << "intergers1:";
    outputVector(intergers1);
    cout << "intergers2:"; 
    outputVector(intergers2);

    cout << "\nEvaluating: intergers1 != intergers2" << endl;

    if(intergers1 != intergers2){
        cout << "intergers1 and intergers2 are not equal." << endl;
    }

    vector<int> intergers3{intergers1};

    cout << "output size of vector intergers3 is " << intergers3.size()
        << "\nvector after initialization: ";
    outputVector(intergers3);
    
    // Using overload assignment opperator (=)
    cout << "\nAssigining intergers2 to intergers1:" << endl;
    intergers1 = intergers2;

    cout << "intergers1: ";
    outputVector(intergers1);
    cout << "intergers2: ";
    outputVector(intergers2);

    cout << "\nEvaluating intergers1 == intergers2" << endl;

    if(intergers1 == intergers2){
        cout << "intergers1 and intergers2 are equal" << endl;
    }
    
    cout << "\nintergers1[5] is " << intergers1[5];

    cout << "\n\nAssigning 1000 to intergers1[5]" << endl;
    intergers1[5] = 1000;
    cout << "intergers1: ";
    outputVector(intergers1);

    try{
        cout << "\nAttempt to display intergers1.at(15)" << endl;
        cout << intergers1.at(15) << endl;
    }
    catch(out_of_range& ex){
        cerr << "An exception occured: " << ex.what() << endl;
    }

    cout << "\nCurrent intergers3 size is: " << intergers3.size() << endl;
    intergers3.push_back(1000); // add 1000 ton the end f the vector
    cout << "New intergers3 size is: " << intergers3.size() << endl;
    cout << "intergers3 now contains: ";
    outputVector(intergers3);
}
void outputVector(const vector<int>& items){
    for(int item : items){
        cout << item << " ";
    }
    cout << endl;
}

void inputVector(vector<int>& items) {
    for(int& item : items) {
        cin >> item;
    }
}

