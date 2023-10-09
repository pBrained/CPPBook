/*                                         
---------------------------------------------------------------------------------------------------------------------


                                                    Pointers 

---------------------------------------------------------------------------------------------------------------------


        "Pointers enable pass by refrence like the & but they also can be used to create
            and manipulate dynamic datastructures that can grow and shrink"

            "They mused be used correctly and responsibly"


    
    Pointer Variables:
        Contains a Memory Address

    Mamory Address:
        Contains a specific value

    Becuase of this pointers are known as indirect references, where as a variable name is a direct reference, to a value.



UML Diagrams:
    Most diagrams refer to a pointer as a arrow from the variable that contains a adress,
    to the local variable located at that adress ion memory.
            the location of pointer is x23232                             the location of count is x998989898989 == to pointer 
    Variable count pointer{x98989898} -------------------------> variable count{7}



Declaration:
    int* countPtr, count;
        
        Just like every other data type
        countPtr is a pointer to int.
        and count is a int.



Pointers should be initalized to {nullptr};

int y{5};
int* ypoint{nullptr};
ypoint = &y; asssign the address of y to ypoint

when * appears in a declaration it is not a operator rater it is a it indicates the variable is
bbeign declared as a pointes.

---------------------------------------------------------------------------------------------------------------------------------------

                                            Indirection Opperator *
                                            (Dereference opperator)

--------------------------------------------------------------------------------------------------------------------------------------------


The uniary * operator commonly refered to as the indirection operator or dereferencing operator

    Returns a L value reperesenting the object to which the pointer opperand points.....

For Example:
        cout << *ypoint << endl;   // outputs the same as 
        cout << y << endl;

other L values include the name of the place, r values are the temorarty / ghostlike / momentary
L values are to the left of the equal sign.

        *ypoint = 9;    //this also works this is specifically DEREFERENCEING A POINTER
        cin >> *ypoint; //this also works



        side note:
            really only declare one pointer at a time.

*/
/*
#include <iostream>
using namespace std;
int cubeByPointer(int*);

int main() {
    int a{7};
    int* aPtr = &a;

    cout << "The adress of a is (&a) "<< &a 
        << "\nThe value of aPtr is (aPtr) " << aPtr;
    cout << "\n\nThe value of a is (a) "<< a 
        << "\nThe value of *aPtr is (*aPtr) " << *aPtr;
    cout << "\nThe adress of aPtr is (&aPtr) "<< &aPtr 
        << "\n" << endl; 
    cout << "\nThe cube of a is " << cubeByPointer(aPtr);

}
int cubeByPointer(int* y) {
    *y = (*y) * (*y) * (*y);
    return *y;
}
*/
/*
    References allow you to work with existing variables or objects as aliases, without directly dealing with 
    memory addresses.
    Pointers explicitly store and allow you to manipulate memory addresses, giving you more control over where they
    point and the ability to modify the memory at a specific address.

    references allow you to get a memory adress 
    pointers allow you to store a memory adress 
    and both allow you to mody the memory at a adress 
    am i missing anything
    ChatGPT
    You've captured the essence of references and pointers quite well, but there are 
    a few additional points to consider:
    
    Getting a Memory Address:
    
    References don't provide a direct way to obtain the memory address.
    You work with references as if they were the original variable, so you don't 
    need to explicitly access the memory address. However, you can use the address-of 
    operator & to get the address of the variable to which the reference is bound.
    
    Pointers, on the other hand, inherently store memory addresses. You can use the 
    pointer variable itself to access the address it holds.
    
    Storing a Memory Address:
    
    References do not store memory addresses themselves; they are essentially aliases
    for an existing memory location. You can't change the memory address a reference
    is bound to once it's initialized.
    
    Pointers explicitly store memory addresses. You can reassign a pointer to point 
    to a different memory address at any time.
    
    Modifying the Memory at an Address:
    
    Both references and pointers allow you to modify the value stored at a
    memory address.
    In summary, references and pointers are used for similar purposes,
    but they have different semantics and syntax:
    
    References are aliases for existing variables or objects, and they provide a 
    more natural way to work with values without explicitly dealing with memory addresses. 
    They are bound to a memory address when initialized.
    
    Pointers explicitly store memory addresses and offer more flexibility in terms of 
    reassignment, allowing you to change the memory address they point to. You need to
    use the dereference operator (*) to access the value stored at the memory address.
    
    Both have their use cases and advantages, and the choice between them depends on
    your specific needs and the design of your code.
----------------------------------------------------------------------------------------------------------------------------------------

                                                Built in Arrays 

----------------------------------------------------------------------------------------------------------------------------------------

int c[12]; // built in  interger array of of size 12 

int n[5]{30,40,50,20,10};

int n[]{50,20,30,10,40};

                "The value of a built in array's name is implicitly compvertable 
                    to the adress of the built in array's first element"

                    (e.g.)
                    arrayName is implicitly covertable to &arrayName[0]
                

        If you declare a built in array and its size is bigger then the initializers list
        - fundemental numeric types are set to 0
        - those of type bool are set to false,
        - pointer types are set to nullptr
        - class objects are initialized by their default constructors

    Because a function can modify the pointer passed to it unless its const (e.g)void modfyPointer(int* pointr){}
    when passing a built in array which is a pointer to the built in arrays first 
    element the reciving function can modify all the values in the built in array.
    (e.g)
        #include <iostream>
        void modifyArray(int arr[], int size) {
            for (int i = 0; i < size; i++) {
                arr[i] += 1; // Modifying each element of the array



    Declaring a Built in array parameter in a function header
        int sumElelements(const int values[], const size_t numberOfElements)
        int sumElements(const int* values, const size_t numberOfElemnts) 
    These are the same.


        Previously:
            sort(colors.begin(), colors.end());
            was used to sort an array of strings "colors" last chapter...
            The arrays class's begin and end functions specified that the entire array should be sorted

            sort(), and many other C++ Standard Library functions, can be called with built-in array's.

        Alternatvely:
            sort(begin(n), end(n)); 
            can be used to sort through a built in array of the name "n"


    "C++'s new begin(), and end() functions from the header <iterator>. each revieve a built in array as 
        an argument and return a pointer that can be used to represent ranges of elements to process in C++
            Standard Library Functions like sort()"
            
    

both the begin and end library functions specified that the entire array should be sorted
function sort and many other C++ standard library functios 

Built In Array Limitations:

    1)They cannot be compared using the relational and equality opperators - you must use a loop to 
    compare two built in arrays element by element

    2)They cannot be assigned to one another-an array name is efficitively a pointer that is const

    3)they dont know their own size a functction that process a built-in array typically recieves both 
    the built-in arrays name and its size as arguments.
    int sumElelements(const int values[], const size_t numberOfElements)
    int sumElements(const int* values, const size_t numberOfElemnts) 




Built in arrays are sometimes required,

    like when processing a programs command line arguments
        dir /p
        ls -la

    These are passed to their repspective programs as a built in array of pointer-based strings.
    C++ inheritied these abilitys from C. it is a hybrid sayan,



Using Const with Pointers:
    
    "Recall that const is a way for you to tell the compiler that you don't want to modify a variable
        there are many ways to use and not use const so how do we decide?...
            let the principle of least priviledge be your guide"

    Rember in chapter 6 that when we pass a variable as a argument to a functuion we create 
        a copy of that variable in memory
            now if the copy is modified the original variable does not change.

    Built in arrays are passed by refernece
        and we need to keep in mind that we pass objects with const if we dont modify them, and
            if we do modify them we should pass a pointer

    Consider a function that takes a pointer to the initial element of a built in array
    and the array's size as argumetnts, then displays the arrays elements...

    The size wont need to change in the body so we should declare it as const to ensure that it does
    not change, becasue the built in array is only beign display it to shoulc be declared as const.

    This is important because built in arrays are allways apassed by refernce and this can easly be
    modified and declaring them as const ensures this does not happen.

     there are four ways to pass a poiner to a function:
        a nonconstant pointer to nonconstant data   | highest 
        a nonconstant pointer to constant data      | mid 
        a constant pointer to constant data         | mid 
        a constant pointer to nonconstant data      | least 

    Each is a different level of access...
    






    Nonconstant Pointer to Nonconstant Data:
    The highest level of access because...
    - the data can be modified through a dereferenced pointer, and 
    - the pointer can be modified to point to other data.

    int* counterPtr; // Does not include const

    Nonconstant Pointer to Constant Data:
    - Pointer that can be modified to point to any data of the appropriate type, but
    - the data to which it points cannot be modified by that pointer.
        Might be used to..
        - Recieve a built-in array argument to a function that should be allowed to read the elements
            but not modify them
    Any declaration of this type of pointer places const to the left of the pointers type as in
    
    const int* countPtr; 
        
    Read Right to left as "counterPtr is a interger pointer to a interger constant"
    More Precicely:
        "countPtr is a nonconstant pointer to a interger constatnt"

        // GNU C++ compiler 
        void f(const int*);
        int main() {
            int y{0};

            f(&y); // f will attempt a illegel modification
        }
        //const variable cannot be modified through xPtr
        void f(const int* xPtr) {
            *xPtr = 100;
        }
        // Attempting to modify data through a nonconstant pointer to const data.
        // err: assignment of read-only location '* xPtr'

        "When a pointer to a object is passed only a copy of the adress of the object is made,
            the object itself is not copied."

    Constant Pointer to Nonconstant Data: 
    - Allways points to the same location in memory
    - The data at that location can be modified through the pointer.

    Pointers that are declared const must be initialized when they're declred, but if the pointer 
    is a function Parameter its initialized with the pointer thats passed to the funcuton.

    int* const pointer {&x};

    Read right to left as "Ptr is a constant pointer to a nonconstant interger"
    the pointer is initialized with the adress of interger value variable x
        // Microsoft Visual C++ compiler
        int main() {
            int x, y;
            int* const ptr{&x};

            *ptr = 7; //  allowed:   *ptr is not constant (dereferenced pointer is not constant)
            ptr = &x; //    error:    ptr is const cannot assign to a new address
            
        }

    Constant Pointer to Constant Data:
        Minimum privieledge.

        const int* const Ptr{&x};

        *ptr = 7 // error
        ptr = &x // error

        //xcode 
        // Read only variable is not assignable.
        // Read only variable is not assignable.        

        Read from Right to Left as...
        "Constant pointer to an interger constant"
    

---------------------------------------------------------------------------------------------------------------------

    "The compiler time uniary operator sizeof determines the size in bytes of a built in array
        or of anyother data type, variable or constant during program calculation"

                        when applied to a built in arrays NAME (ptr*)...        

    "sizeof returns the total number of bytes in the built in arrays as value of type size_t"   

    ... When applied to a pointer paramerter ins a function that recieves a built in array 
    as an argument, the size of operator returns the size of the pointer in bytes  -- not the built 
    in arrays size 
*/
/*
#include <iostream>
using namespace std;
size_t getSize(double*);

int main() {
    double numbers[20]; // 20 doubles 
    cout << "The number of bytes in the array is " << sizeof(numbers);
    cout << "\nThe number of bytes returned by get size is "
        << getSize(numbers) << endl;

    cout << "The number of elements is " << sizeof(numbers) / getSize(numbers) << endl;
    // also can be done with sizeof(numbers) / sizeof(numbers[0])
}
size_t getSize(double *ptr){
    return sizeof(ptr);
}




*/
//Size of Test Program
//
//#include <iostream>
//using namespace std;
//char c;
//short s;
//int i;
//long l;
//long long ll;
//float f;
//double d;
//long double ld;
//int a[20];
//int* ptr{a};
//int main() {
//cout << "Size of c = " << sizeof c  
//    << "\tsizeof(char)" << sizeof(char)
//<< "\nSize of s = " << sizeof s  
//    << "\tsizeof(short)" << sizeof(short)
//<< "\nSize of i = " << sizeof i  
//    << "\tsizeof(float)" << sizeof(int)
//<< "\nSize of l = " << sizeof l  
//    << "\tsizeof(long)" << sizeof(long)
//<< "\nSize of ll = " << sizeof ll  
//    << "\tsizeof(long long)" << sizeof(long long)
//<< "\nSize of f = " << sizeof f  
//    << "\tsizeof(flaot)" << sizeof(float)
//<< "\nSize of d = " << sizeof d  
//    << "\tsizeof(double)" << sizeof(double)
//<< "\nSize of ld = " << sizeof ld   
//    << "\tsizeof(long double)" << sizeof(long double)
//<< "\nSize of a = " << sizeof a  
//<< "\tSize of ptr = " << sizeof ptr << endl;
//cout << &i 
//    << "\tSize of & = "<< sizeof &ld << endl;
//
//
//}


/*Pointer Arithmatic is only to be used with pointers that point to built in arrays

    int* vPtr{v};
    int* vPtr{&v[0]};

    vPtr    v[0]    v[1]    v[2]    v[3]    v[4]
     v----> 3000    3004    3008    3012    3016
     
     vPtr+=2 should produce 3008(from the calculation 3000 + 2 * 4)
                            3016(from the calculation 3000 + 2 * 8)
                            if interger is stored in a 8byte value
    
    Remeber the pointer itself is a size of 8 bits the address in it changes by the size of the 
    datatype 

    vPtr -= 4 ;         If vPtr had been incremented to 3016 vPtr would go to 3000
    
    ++Vptr;             Increments vPtr by type size 
    Vptr++;         
    
    --vPtr;             Decrements vPtr by type size
    vPtr--;

    x = v2Ptr - vPtr    this would assign x the number of array elements between the two
    x = 2;              ((3016-3008)/4)
                        or 1 if ((3016-3008/8)/4)


    Pointer Assignment

    A pointer can be assigned to another pointer if they have the same type 
    if they do not have the same type you can use a cast operator, normaly a reintupret_cast:
        which must be used to convert the value of the pointer on the right side of the cast to the 
        left side of the cast 
    
    or you can use a pointer to void (void*) to represent a pointer of any type.
    

    Pointer to Void...
        Any fundemental type can be cast into a pointer of void,
        but not void pointers back into a fundemental type,
            it must be cast into the proper pointer type first (reinterpret_cast?..)

        A pointer to void also cannot be dererfferenced, for example the compiler knows
        that a int* points to four bytes of memory on a machine that stores int's in 4 bytes
        yet IT DOES NOT KNOW the size of the data type stored in the pointer to void. Yet its adress is 
        still stored in a 8 byte variable on this compiler as i write this

        -- The allowed operations on void are comparing void* poiners to other pointer types
        -- casting void pointers to other pointer types and
        -- Assigning addresses to void pointers... All other options are copilation errors

        Pointerss can be compared using the equality and realtional operators
        comparisons using the relational operators are meaningless unless 
        the poiners point to elements in the same built in array.

    Built-in Arrays and Pointers are itimately relatesd in c and may be used 
    almost interchangebly...

        int b[5];
        int* bPtr;  
        bPtr = b;       // Assingn address of built in array to b to bPtr
        bPtr = &b[0];   // This is the same thing.
                        // b += 3 causes a compileation error
            
        *(bPtr + 3)     // This is another way to get the 3rd element,
                        // The 3 is the Pointer Offset
        
        &b[3]           // This is the element adress of the third value
        bPtr + 3        // These are the same.

                        // #include <iostream>
                        // using namespace std;
                        // 
                        // int main() {
                        //     int a[5] {1,2,3,4,5};
                        //     int * aPtr = &a[1];
                        //     cout << &a[0] << endl;
                        //     cout << aPtr + 3 << endl;
                        //     cout << *aPtr << endl;
                        //     cout << *(aPtr - 1) << endl;
                        // }
                        // 

*/
/*
#include <iostream>
using namespace std;

int main () {
    int b[]{10,20,30,40};
    int* bPtr{b};

    cout << "Array b displayed with:\n\nArray subscript notations\n";

    for(size_t i{0}; i < 4;++i) {
        cout << "b[" << i << "] = " << b[i] << '\n';
    }

    cout << "\n Pointer/offset notation where "
        << "the pointer is the array name\n";
    
    for(size_t offset1{0}; offset1 < 4; ++offset1) {
        cout << "*(b + " << offset1 << ") = " << *(b + offset1) << '\n';
    }

    cout << "\nPointer subscript notation" << endl;

    for(size_t j{0}; j < 4; ++j) {
        cout << "bPtr[" << j << "] = " << bPtr[j] << '\n';
    }

    cout << "\nPoiinter / offset notation\n";

    for(size_t offset2{0}; offset2 < 4; ++offset2) {
        cout << "*(bPtr + " << offset2 << ") = "
            << *(bPtr + offset2) << '\n';
    }
}
*/
/*
---------------------------------------------------------------------------------------------------------------

                                                C Strings

--------------------------------------------------------------------------------------------------------------

            "C-Style Pointer Based Strings..."


            "C++ strings class is prefered for new programs, because it removes many of the 
                    security vulnerabilitys and bugs introduced in C Strings."

            "There are some cases such as command line arguments where C Strings are required"
            
            
            Character constants:
        ASCII: '\n' is ascii value 10
        ASCII: 'z' is asci value 122... 

            These make up a string because...
    
    "A string is a series of characters represented as a single unit, a string my include leters
    digits and various other special characters such as +,-,*,/, and $..."

    Strign literals and string constants are written in c++ in double quotatio marks as follows....

    "John Q Doe"                // Name 
    "4082212112"                // Number 
    "Maynard, Massachusetts"    // City and State 
    "99999 Vinard Pl."          // Address


!!!!!!!!!!!Pointer based string is a built in array of characters ending with a null character '\0'!!!!!!!!!!!
    

    char color[] {"blue"};                  // The first declaration creates a five-element built in 
                                            // Array color containing the characters 'b''l''u''e' and '\0'...
    
    const char* colorPtr{"blue"};           // The second delcaration 
                                            // Creates a pointer variable colorPtr that points to the letter 'b' in the string blue...


    String Literals exist for the duration of the program and may be shared if the same string literal 
    is referenced in different locations in a program.

    char color[] {'b','l','u','e','\0'};    // Was also acceptable.
                                            // Not having the null character is a logic error.
                                            // If someone writes to a C String 
    

    we can use cin to pass values into a built in array of characters, 

    cin >> word;                       // Pass into word array,
    cin >> setw(20) >> word;           // Set w atring manipulaor ensure we dont exceed the sizeof built in array.
    
            setw:
        "The set w stream manipulaor is not a sticky setting.- it applies only to the next value being input
                if more then 19 variables are input (setw(20)) the remaining characters are not saved in 
                    word. They will be in a input stream and can be read by the next input operation."
        
        Of course any input operation can fail however so in chapter 13 we learn about failures...

    char sentence[20];
    cin.getline(sentence, 80, '\n');    // This takes 3 arguments 
                                        // fisrt is the built in array
                                        // second d the size of the array
                                        // third is the deliminator character
    Displaying c strings 
    cout << sentence; 
    
*/

/*





*/









































/*
int main() {
    !maze start should be a period
    mazeTraverse(maze, mazestart)
    

}

mazeTraverse(maze, mazestart) {
    mazePrint(maze)
    player_loc = maze_start
    player_loc = should have one zero

    new_player loc = move(player_loc)
    
    check if new_player loc has a zero,
    if has zero return
    // ?else recursive with new, mazestart.

}   
move(player_loc) {

    !right hand movement...
    figure out right 
    move 
    recursive
   ]
}
*/
/*  
#include <array>
#include <iostream>
#include <iomanip>
using namespace std;

const size_t columnSize{12};
const size_t rowSize{12};
const size_t playerRaySize{2};

char removedValue;

void printMaze(const array<array<char, columnSize>, rowSize>&);
void mazeTraversal(array<array<char, columnSize>, rowSize>&, array<int,playerRaySize>&);
void updatePlayer(array<array<char, columnSize>, rowSize>&, array<int,playerRaySize>&);

int main(){
    array<array<char, columnSize>, rowSize> maze{
        {{'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','#','.','.','.','.','.','.','#'},
        {'.','.','#','.','#','.','#','#','#','#','.','#'},
        {'#','#','#','.','#','.','.','.','.','#','.','.'},
        {'#','.','.','.','.','#','#','#','.','#','.','#'},
        {'#','#','.','#','.','#','.','#','.','#','.','#'},
        {'#','.','.','#','.','#','.','#','.','#','.','#'},
        {'#','#','#','#','.','#','.','#','.','#','.','#'},
        {'#','.','.','.','.','#','.','.','.','#','.','#'},
        {'#','#','#','#','#','#','.','#','#','#','.','#'},
        {'#','.','.','.','.','.','.','#','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'}}};
    array<int, playerRaySize> playerLoc{0,2};

    //printMaze(maze);
    mazeTraversal(maze,playerLoc);

}
void printMaze(const array<array<char, columnSize>,rowSize>& mazePass) {
    for(auto const row : mazePass){
        for(auto const element : row){
            cout << element << " ";
        }
        cout << endl;
    }
    return;
}
void updatePlayer(array<array<char, columnSize>, rowSize>& maze, array<int,playerRaySize>&playerLo) {
    int x{0};
    int y{0};
    for(auto const row : maze){
        for(auto const column : row){
        array<int, playerRaySize> tempLo = {x, y};
            if(playerLo == tempLo){
                removedValue = maze[y][x];
                maze[y][x] = 'X';
                playerLo = {x,y};
            }
            ++y;
        }
        ++x;
    }
}
void mazeTraversal(array<array<char, columnSize>, rowSize>& maze, array<int,playerRaySize>&playerLo) {
    updatePlayer(maze,playerLo);
    printMaze(maze);
    static array<int, playerRaySize> lastLo = playerLo;
    int up = playerLo[1]-1;
    int down = playerLo[1]+1;
    int left = playerLo[0]-1;
    int right = playerLo[0]+1;
    if (up >= 0 && maze[up][playerLo[0]] == '.') {
        maze[up][playerLo[0]] = 'X'; // Move up
        maze[playerLo[1]][playerLo[0]] = removedValue;
        playerLo[1] = up;
        mazeTraversal(maze, playerLo); // Recursive call
    }
    if (down < static_cast<int>(rowSize) && maze[down][playerLo[0]] == '.') {
        maze[down][playerLo[0]] = 'X'; // Move down
        maze[playerLo[1]][playerLo[0]] = removedValue;
        playerLo[1] = down;
        mazeTraversal(maze, playerLo); // Recursive call
    }
    if (left >= 0 && maze[playerLo[1]][left] == '.') {
        maze[playerLo[1]][left] = 'X'; // Move left
        maze[playerLo[1]][playerLo[0]] = removedValue;
        playerLo[0] = left;
        mazeTraversal(maze, playerLo); // Recursive call
    }
    if (right < static_cast<int>(columnSize) && maze[playerLo[1]][right] == '.') {
        maze[playerLo[1]][right] = 'X'; // Move right
        maze[playerLo[1]][playerLo[0]] = removedValue;
        playerLo[0] = right;
        mazeTraversal(maze, playerLo); // Recursive call
    }
}
*/   
/*
#include <array>
#include <iostream>
#include <iomanip>
using namespace std;

const size_t columnSize{12};
const size_t rowSize{12};
const size_t playerRaySize{2};

char removedValue;

// Define directions (right, down, left, up)
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void printMaze(const array<array<char, columnSize>, rowSize>&);
void mazeTraversal(array<array<char, columnSize>, rowSize>&, array<int, playerRaySize>&, array<array<bool, columnSize>, rowSize>&);
void updatePlayer(array<array<char, columnSize>, rowSize>&, array<int, playerRaySize>&);

int main(){
    array<array<char, columnSize>, rowSize> maze{
        {{'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','#','.','.','.','.','.','.','#'},
        {'.','.','#','.','#','.','#','#','#','#','.','#'},
        {'#','#','#','.','#','.','.','.','.','#','.','.'},
        {'#','.','.','.','.','#','#','#','.','#','.','#'},
        {'#','#','.','#','.','#','.','#','.','#','.','#'},
        {'#','.','.','#','.','#','.','#','.','#','.','#'},
        {'#','#','#','#','.','#','.','#','.','#','.','#'},
        {'#','.','.','.','.','#','.','.','.','#','.','#'},
        {'#','#','#','#','#','#','.','#','#','#','.','#'},
        {'#','.','.','.','.','.','.','#','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'}}};
    array<int, playerRaySize> playerLoc{0, 2};
    array<array<bool, columnSize>, rowSize> visited = {}; // Initialize visited array

    //printMaze(maze);
    mazeTraversal(maze, playerLoc, visited);
}

void printMaze(const array<array<char, columnSize>,rowSize>& mazePass) {
    for(auto const row : mazePass){
        for(auto const element : row){
            cout << element << " ";
        }
        cout << endl;
    }
    return;
}

void updatePlayer(array<array<char, columnSize>, rowSize>& maze, array<int, playerRaySize>& playerLo) {
    int x{0};
    int y{0};
    for(auto const row : maze){
        for(auto const column : row){
        array<int, playerRaySize> tempLo = {x, y};
            if(playerLo == tempLo){
                removedValue = maze[y][x];
                maze[y][x] = 'X';
                playerLo = {x,y};
            }
            ++y;
        }
        ++x;
    }
}

bool isValidMove(array<array<char, columnSize>, rowSize>& maze, int x, int y, array<array<bool, columnSize>, rowSize>& visited) {
    if (x >= 0 && x < static_cast<int>(columnSize) &&
        y >= 0 && y < static_cast<int>(rowSize) &&
        maze[y][x] == '.' && !visited[y][x]) {
        return true;
    }
    return false;
}

void mazeTraversal(array<array<char, columnSize>, rowSize>& maze, array<int, playerRaySize>& playerLo, array<array<bool, columnSize>, rowSize>& visited) {
    updatePlayer(maze, playerLo);
    printMaze(maze);
    static array<int, playerRaySize> lastLo = playerLo;

    for (int i = 0; i < 4; ++i) {
        int nextX = playerLo[0] + dx[i];
        int nextY = playerLo[1] + dy[i];

        if (isValidMove(maze, nextX, nextY, visited)) {
            visited[nextY][nextX] = true;
            maze[nextY][nextX] = 'X';
            maze[playerLo[1]][playerLo[0]] = removedValue;
            playerLo[0] = nextX;
            playerLo[1] = nextY;
            mazeTraversal(maze, playerLo, visited);
        }
    }
}
*/