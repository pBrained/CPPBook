/*
----------------------------------------------------------------------------------------------

                                        CHAPTER 6
                                       "Functions"

----------------------------------------------------------------------------------------------
                                                                      

Functions either return a result, or control to the caller. 

Functions allow you to modularlize a program by seperating its tasks into self-contained units. 

The caller has no idea what the function does with the input like a boss and a worker.


<cmath> library functions
Function, Description, Example
ceil(x), Round X to the smallest interger not lest then x, ceil(9.2) is 10.0
cos(x), Trigonometric cosine of x (x in radians), ceil(-9.8) is -9.0  
exp(x), Exponential function e^x,  exp(1.0) is 2.718282 exp(2.0) is 7.389056
fabs(x), Absolute value of x, fabs(5.1) is 5.1 fabs (0.0) is fabs (-8.9) is 8.8
floor(x), Rounds x to the largest interger not greater than x, floor(9.2) is 9.0 floor(-9.8) is -10.0
fmod(x, y), Remainder of (x/y) as a floating point number, fmod(2.6, 1.2) is 0.2
log(x), Natural logarithym of x (base e), log(2.718282) is 1 log of (7.389056) is 2.0
log10(x), Logarithm of x (base 10), log10(10.0) is 1.0
pow(x, y), x raised to power y (x^y), pow(2, 7) is 128 pow (9, .5) is 3
sin(x), Trigonometric sine of (x) (x in radians), sin(0.0) is 0
sqrt(x), Square root  of x (where x is a nonnegative number), sqrt(9.0) is 3
tan(x), Trigonometric tangent of (x) (x in radians), tan(0.0 is 0)



C++ has Many Different Ways to call a function...

Function Prototype:                 // Which describes the function without revealing
int maximum(int x, int y, int z);   // its implementation;
                                    // Function Prototype of maximum function

A type is required for each of the funtions parameters
in the "Paramter List"

Tells the compiler the functions name, return type, and parameters.
For a function of type void you cannot call the function on the right side 
of the parameters.


                                        ------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

int maximum(int x, int y, int z); // Is a function prototype 

int main(){
    cout << "Enter three interger values" << endl;
    int int1, int2, int3; // I love this naming convention
    cin >> int1 >> int2 >> int3;

    // Invoke maximum

    cout << "The maximum valus of these intergers is " << maximum(int1,int2,int3) << endl;
}
int maximum(int x, int y, int z){
    int maximumValue{x};
    if(y > maximumValue){
        maximumValue = y;
    }
    if(z > maximumValue){
        maximumValue = z;
    }
    return maximumValue;
} 


Commas in paramerter list are not comma operators, and its good to note that
Different compilers read the parameters in the list in different orders.

Sometimes when a functions arguments are expressions differnt compilers 
will read them in different orders causing subtle logic errors
such when a functions argument is a call to another function. 

How to fix or see if there will be a conflict
Evaluate the arguments in seperate assignment statements and before
the function call, and assign the results of each expression into a local 
variable then pass those variables as arguments to the functon

- Function prototypes help you find errors at compiletime.

------------------------------------------------------------------------

Name of the function and the types of its arguments are its signature
or simply the signature (return type is not a part of the signature)

A important feature of function prototypes are known as argument coercion
forcing arguments to appropriate types specified by the paramater declerations

a function can be called with a int input even if it required a double
provided this is not a narrowing conversion.

truncation happens when assinging like this int x = 12.7 and x = 12
the value is narrowed and this does not work when declarig like this
int x{12.7}; becasue this will return a compile error

list initilization "x = x"
non list "{x}"

----------------------------------------------------------------------------

Argument-Promotion Rules and implicit conversions

int to double and double to int are truncated and have dataloss but are allowd

also aplies to expressions with two or more data types called "Mixed-Type
Expressions"
they type of each value in a mixed type expression is promoted to the "Highest" type
int the expression (actually a temporary value is created and used for the
expression - the original values remain unchanged)

Data Types In order from "Highest type" to "lowest type"

long double,                                                 |
double,                                                      |
float ,                                                      |
unsigned long long int, (synonomous with unsigned long long) |
long long int,          (synonomous with long long)          |
unsigned long int,      (synonomous with unsigned long)      |
long int,               (synonomous with long)               |
unsigned long int,      (synonomous with unsigined)          |
int ,                                                        |
unsigned short int,     (synonomous with unsigned short)     |
short int,              (synonomous with short)              |
unsigned char,                                               |
char and signed char,                                        |
bool,                                                        |
                                                             V

<iostream>, C++ Standard input and output functions
<iomanip>, C++ Function Prototypes for stream manipulators that format streams of data.
<cmath>, Containts function prototypes for math library functions
<cstdlib>, Contains function prototypes for conversion of numbers to text text to numbers memory
            allocation, random numbers, and various other utility fuinctions.
<ctime>, Contains function prototypes for manipulating the time and date.
<array>, These Headers contain classes that implement the C++ standard library containers.
<vector>, Containers store data during a programs execution.
<list>, (<array>, <foward_list>, <unordered_map>, and <unordered_set> were all introduced in C++ 11)
<foward_list>, 
<deque>,
<queue>,
<stack>,
<map>,
<unordered_map>
<unordered_set>,
<set>,
<bitset>,
<cctype>, Contains function prototypes for functions that test charactes for certain properties(such as
            wether or not a digit has punctiation) for ffunctions that can be used to convert lowercase 
            letters to uppercase and vise versa. 
<cstring>, Contains function prototypes for C-style string processing.
<typeionfo>, Contains classes for runtime type identification
<exception>, These headers contain classes that are used for excption handeling.
<stdexcept>,
<memory>, Contains classes and functions used by the C++ standard library to allocate memory to the C++ Standard library containers
<fstream>, Contains functions prototypes for functions that preform input form and output to files on disk. 
<string>, Contains the definition of class string from the C++ Standard Library
<sstream>, Contains functions prototypes for functiuons that preform input from and output to strings in memory.
<functional>, Contains classes and functions used by the C++ Standard Library Algorithms
<iterator>, Contains classes for accessing data in the C++ Standard Library Conatainers 
<algorithm>, Contains functions for manipulating data in the C++ Standard Library Containers
<cassert>, Contains macros for adding diagonostics that aid program debugging, used ind Appendex E.f Postprocessor
<cfloat>, Contains the floating point size limits of the system
<climits>, Contains the intergral size limits of the system
<cstdio>, Contains the function prototypes for C-style Standard input and Output Library functions
<locale>, Contains the Classes and functions normally used by stream post processing to process data int the natural form to different languages (monetary formats, sorting strings, character presentation, etc.).
<limits>, Contains classes for determining numerical data type limits on each Computers platform C++ version  of climits and cfloat
<utility>, Contains classes and functiuons that are used by many C++ Library Headers.


"setw(20)" prints out the calue in the necesary space and if we go over that space it just prints the value with no space.
its a really nice function for fomrmating clean output in te terminal.

<cstdlib>
    rand();
    Generates an unsigned interger from between 0 and RAND _MAX(a symbolic constant defined in the 
    <cstdlib> header)

    we have to use it by scaling, it does not return a truly new interger 
     in "rand() % 6" 6 is the scaling factor.
    
    rand() 6 produces the same values each time.


*/
/*
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
    unsigned int frequency1{0}; // count of 1 rolled    
    unsigned int frequency2{0}; // count of 2 rolled
    unsigned int frequency3{0}; // count of 3 rolled
    unsigned int frequency4{0}; // count of 4 rolled
    unsigned int frequency5{0}; // count of 5 rolled
    unsigned int frequency6{0}; // count of 6 rolled
    
    
    int face;
    for (unsigned int roll{1}; roll <= 60'000'000; ++roll) {
        
        face = 1 + rand() % 6;
        cout << face << endl;
        
        switch(face) {
            case 1:
                ++frequency1;
                break;                
            case 2:
                ++frequency2;
                break;                            
            case 3:
                ++frequency3;
                break;            
            case 4:
                ++frequency4;
                break;            
            case 5:
                ++frequency5;
                break;            
            case 6:
                ++frequency6;
                break;                  
            default:
                cout << "Some how you produced a incorrect value"  << endl;
        }
    }
    cout << "Face" << setw(13) << "Frequency" << endl;
    cout << "   1" << setw(13) << frequency1 
    << "\n     2" << setw(13) << frequency2
    << "\n     3" << setw(13) << frequency3
    << "\n     4" << setw(13) << frequency4
    << "\n     5" << setw(13) << frequency5
    << "\n     6" << setw(13) << frequency6 << endl;
}
*/
/*
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
    unsigned int seed{0};

    cout << "Enter seed:    ";
    cin >> seed;
    srand(seed);
    
    for(unsigned int counter{1}; counter <= 10; ++counter){
        cout << setw(10) << (1+rand()%6);

        if(counter % 5 == 0) {
            cout << endl;
        }
    }
}
*/
// srand(static_cast<unsigned_int>(time(0))); will use computer clck to obtain 
//  the seed value
// type variableName{shiftingValue +rand() % scalingFactor};

/*
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

unsigned int rollDice();

int main() {
    enum class Status {CONTINUE, WON , LOST}; // enumeration is a class that returns a index value for the constants put into it.

    srand(static_cast<unsigned int>(time(0)));
    unsigned int myPoint{0};
    Status gameStatus; // Can be continue won or lost
    unsigned int sumOfDice{rollDice()};

    switch(sumOfDice) {
        case 7:
        case 11:
            gameStatus =Status::WON;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = Status::LOST;
            break;
        default:
            gameStatus = Status::CONTINUE;
            myPoint = sumOfDice;
            cout << "Point is " << myPoint << endl;
            break;
    }

    while (Status::CONTINUE == gameStatus) {
        sumOfDice = rollDice();

        if(sumOfDice == myPoint) {
            gameStatus = Status::WON;
        }
        else {
            if(sumOfDice == 7){
                gameStatus = Status::LOST;
            }
        }
    }

    if (Status::WON == gameStatus){
        cout << "Player Wins" << endl;
    }
    else{
        cout << "Player Loses" << endl;
    }
}

unsigned int rollDice() {
    int die1{1 + rand() % 6};
    int die2{1 + rand() % 6};
    int sum{die1 + die2};

    cout << "Player rolled " << die1 << " + " << die2 << " = " << sum
    << endl;
    return sum;
}

----------------------------------------------------------------------------------------------------

                                        Enumeration

-------------------------------------------------------------------------------------------------------

Scoped Enumeration:
    enum class Months {JAN = 1, FEB, MAR, APR, MAY, JUN, JLY, AUG, SEP, OCT, NOV, DEC};
        creates user defined type months with enumeration constants respresenting the months of the year;
        The values of enumeration constants are ints and start at 0 (unless specified otherwise) and
        increment by 1. 

    To reference a scoped enum constant, you must qualify the constant with the scoped enums type 
    name (Months) and the scope-resolution operator (::). When the game above is lost the program 
    sets the status to Status::LOST; and when it is won tHE gameStatus is set to Status::WON;

Unsocped Enum:
    enum class Status : unsigned int{CONTINUE, WON, LOST};
        The underying type depends on its constants values and is garenteed to be big enough to 
        fit its constants values. 

        A "Scoped Enumeration's" underlying intergral type is int, but you can specifiy a different
        type by following the type name with a colon (:) and the intergral type. 

        We will get a error if a constants value reaches beyond the bounds of its type.



---------------------------------------------------Scope-----------------------------------------------

            "Variables should be declared in the narrowest scope in wich they need to be accesed"
                "Except for "cin" and "cout"...

Block Scope:
    {{{{{Scope of the block determined by the curley braces}}}}};
    Identifiers determined inside of a block have the scope of that block.

    If blocks nested within have the same function name the outer function is hidden until the inner function returns to caller


Local Variables:
    static unsigned int count{1};
    May be declared staticSuch variables also have a block scope , but unlike other local variables, a static local variable
    retains its value when the function returns to its caller.

    "The next time a function called the static local variable retains its value from the last execution of the function.

*/
/*
#include <iostream>
using namespace std;

void useLocal();
void useStaticLocal();
void useGlobal();

int x{1};

int main(){
    cout << "global x in main is " << x << endl;

    {
        int x{7};

        cout << "local x in main's inner scope is " << x << endl;
    }

    cout << "local x in main's inner scope is " << x << endl;

    useLocal();
    useStaticLocal();
    useGlobal();
    useLocal();
    useStaticLocal();
    useGlobal();

    cout << "\n local x int main is " << x << endl;
}

void useLocal() {
    int x{25};
    cout << "\nlocal x is " << x << " on entering useLocal" << endl;
    x++;
    cout << "local x is " << x << " on exiting useLocal" << endl;
}

void useStaticLocal (){
    static int x{50};
    cout << "\nlocal static x is " << x << " on entering useStaticLocal" << endl;
    x++;
    cout << "local static x is " << x << " on exiting useStaticLocal" << endl;
}
void useGlobal(){
    cout << "\nGlobal x is " << x << " on entering use Global" << endl;
    x++;
    cout << "Global x is " << x << " on exiting useGlobal" << endl;
}


----------------------------------------------------------------------------------------------

Function Call Stack;        // Pile of dishes                   
(Program-execution Stack)    // Dishes Placed at the top
                                // "PUSHING" the dishes on to the stack 
                                    // "POPPING" the dishes off the stack
                                    // Last in first out Data Structure. (LIFO)


-----------------------------------------------------------------------------------------------

                                       Stack Frame

-----------------------------------------------------------------------------------------------

    A Stack Frame or Activation Record, contains the return address that the called function 
    needs in order ro rerturn the calling function. it also contains some additional informa-
    tion...

    If the calling function returns before calling another function, the stack frame for the 
    function call is popped, and control is given to the return adress in the given stack frame. (vunerablility)?

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



                                        Stack OverFlow


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            "If more function calls occur then than can have their activation records stored
                A stack overflow occurs"
*/
/*
#include <iostream>
using namespace std;

int square(int);

int main(){   // Step one operating system calls main() --> Function Call Stack after calling main
                                        // Top Of Stack --> //____________________ --Called Sequence values before
    int a{10};                                              // Return Location: R1
                                                            // Local Variables: a = 10
                                                            //____________________
    cout << a << " squared: " << square(a) << endl;         //  ^ Activation Record for function main
}                                                           //   
int square(int x) {                                         // After square calculates its argument, it returns to   
    return x * x;                                           // main and no longer needs its variable. So squares 
}                                                           // Stack Frame (above) is popped from the stack, giving 
                                                            // giving suare the return location in main and loosing
                                                            // squares local variable step 3.
*/
/*

------------------------------------------Function Call Stacks-------------------------------------------------



RETURN LOCATION R2      int main() {
                            int a {10};
                            cout << a <<  "Squared:  " <, square(a) << endl;
                        }

Function Call stack after main calles square. 

                    Activation Record for fuction square
Top of Stack --->   // RETURN R2       
                    // LOCAL VARIABLES: 
                    // X = 10;
                    //              //Gets put on top of Activation function for main.
                                    // RETURN R1
                                    // LOCALVARIABLES:
                                    // A = 10;
*/
/*
------------------------------------------Inline Functions-------------------------------------------------------

            "C++ provides inline functions to help reduce function-call overhead."
                
                
                
Placing thee qualifier inline before a functions return type in the function
advices the ccompiler to generate a copy of the functiuons body code in every
place the function is called(when appropriate) to avoid a function call. This 
often makes the program larer. 

The compiler can ignore the inline qualiufier and generally does so for all but the smallest functions.
Reuseable inline functions are typically placed in header, so that their definitions can be inclided in 
each source file that uses them.

If you change the definition of a inline functin you have to recompile all of that functions clients.

Compilers can inline cde for which you have not explicitly use the inline keyword. Todays optimizing
compilers are so sophisticated that its best to leave tyhe inline decisions to the compiler.

The const qualifier should be used to enforce the principal of least priviledge. Using thei9s principle 
to properlydesign software can grewately redue  debugging type and improper side effects and can make a 
program easier to modify and maintain.

*/
/*
#include <iostream>
using namespace  std;

inline double Cube(const double value){
    return value * value * value;
}

int main(){
    double sideValue;
    cout << "What do you want the cube of?" << endl;
    cin >> sideValue;

    cout << "The anwser is " << Cube(sideValue);

}
*/
/*
---------------------------Passing References and Referance parameters-----------------------------

Two ways to pass arguments to functions in many programming languages are....



Pass by Value:
        When an assignment is passed by value, a copy of the argument's value is made and passd
        (on the function call stack)
        
        -- Changes to the copy do not effect the original variables value in the caller.
        
            This prevents the accidental side effects that so greately hinder the development 
            of correct and valueable software systems. So far each variable in the book has been
            passed by value.


Pass by Reference:
        With pass by refernece the caller gives the called function THE ABILITY TO ACCESS THE 
        CALLERS DATA DIRECTLY, AND TO MODIFY THAT DATA. 

        -- Changes to the value at the refrence change the original variables value in the caller.

        -- Good for preformance, but can also weaken security; the called function can corrupt the 
                                                               callers data.



-- Referance Parameter:
        Alias for its corresponding argument in a function call.
        
        To indicate that a function parameter is passed by referance, simpily follow the parameter's
        Type in the function prototype by an ampersand(&); use the same convention when listing the 
        parameters type in the function header 
        
        "int& number"
        

        when "read from right to left" is pronounced "number is a refrance to an int" In the function call, 
        simplily mentions the variable by name (e.g number )to pass it by reference. In the called function's
        body, the referance parameter actually referes to the original variable in the calling functrion, and 
        the original variable can be modifid directly by the called function. As allways the function
        prototype and header must agree. Note the placemnent of & in the preceding declaration-- Some C++ 
        programers prefer to write the equivalent from int&number.

                "Because referance parameters are mentioned only by nname in the body of the called
                function, you might inherantly treat refreance parameters as pass by value parameters
                this can cause unexpted side effects if the original variables are changed by the function"
                        Read from Right to left is pronounced by the compiler, we assume, as well as being necessary
                        for the pointerto be read it is read as number is a reference to int. 

        
*/
/*

#include <iostream>
using namespace std;

int squareByValue(int);                 // Function Prototype with (value pass) pass by value 
void squareByReferance(int&);           // Function prototype with (reference pass) pass by reference

int main(){
    int x{2};
    int z{4};

    cout << "x = " << x << " Before Square by value " << endl;
    cout << "z = " << z << " Before Square by referance " << endl;

    cout << "Value returned by squareByValue " << squareByValue(x) << endl;
    squareByReferance(z);
    cout << "Value returned by squareByReferance " << z << endl;
}

int squareByValue(int number){
    return number * number;
}

void squareByReferance(int& numberRef){ // this function understands it is recieveing a pass to wehre the real value of numberRef is/
    numberRef *= numberRef;
}

*/
/*



                    "Reference variables must be initialized in their declarations and cannot be reassigned
                            as Aliases to other variables."

    --In this sense references are constant.

        All opperations preformed (supposedly) on the Alias are preformed (actually) on the original variable.

        Unlsess its a reference to a constant(code below) a reference inializer must be a lvalue (e.g variable name), not a constant or rvalue expression
        (e.g the result of a calcualtion.)

        Const References:             
            const std::string& accountName
                To specify that a reference parameter should not be allowed to modify the corresponding argument,
                place the const qualifier before the type name in the parameters declaration.

    
    Before in our DollarAmmount setname function (CH3), we used void setName (std::string accountName); 
    
    NOW we use "const std::string& accountName;"

        When its read from right to left it goes accountName pointer from the std scope string class of type constant.
        -- Or simply "Account name is a referance to a string constant."

        setName treasts the argument as a constant.
            So it cannot modify the value in the caller- just like with passby value.

    "For passing large objects, use a const referance parameter to simulate the appearance and security of a pass-by-value
        and avoid the overhead of passing a copy of the large object."

    int count{1};
    int& cRef{count};
    ++cRef;


Similarialy

    class Accounts getName() member function was defined with the header..

        std::string getName() const
            
            and changing this to

        const std::string& getnName() const
    
    Indicates tht the string should be returned by reference. (eliminating the overhead of copying a string)
    and that the caller cannot modify the returned string.

    Functions can return refernces to local variables but this can be dangerous, when returning a reference to a local variable
    unless that variable is declared static - the refernece refeeres to a variable that's dicarded when the function terminates.
    An attempt to access such a variable yeilds undefined behavior references to undefined variables are considered dangaling.


    Default Arguments
    Programs often call the same function over nd over agian with the same argument value 
    for a particulat paramter, so we can specifiy that such a paramter has a default argument
    i-e a default value will be passed to that paramterer. When a program omits an argument for 
    a parmater with a default argument in the function call, the compiler rewrtites the function
    call and inserts the default value of the argument.

*/      
/*
    #include <iostream>
    using namespace std;

    unsigned int boxVolume( unsigned int length = 1, unsigned int width = 1, unsigned int height = 1);

    int main(){
        cout << "The default box volume is" << boxVolume();

        cout << "\n\nThe volume of a box with length 10. \n" << boxVolume(10);

        cout << "\n\nThe volume of a box with length 10, width 5. \n" << boxVolume(10, 5);

        cout << "\n\nThe volume of a box with length 10, width 5 and height 2. \n" << boxVolume(10,5,2) << endl;

    }

    unsigned int boxVolume(unsigned int length, unsigned int width, unsigned int height){
        return length * width * height;
    }


    **Important**

    Default arguments must be the rightmost (trailing) arguments in a function's parameter list.
    When calling a function with two or more default arguents, if an ommittd arguments is not 
    the rightmost, then all arguments to the right of that argument must be omitted.

    Default arguments must be called with the first occurance of a function name -- typically in 
    the function prototype; 
    
    If a function prototype is ommited because the function definition also serves as the prototype, 
    then the default arguments should be specified in the function header. 
    
    Default values can be any expression, including constants, global variables, or function
    calls. Default arguments can also be used with inline functions.

    Using defualt arguments can simplify writting function calls. However, some programmers feel 
    that ecplicitly specifying all arguments is clearer.

    -----------------------------------------Uniary Scope Operator P2---------------------------------
    
    C++ provids the uniary scope resolution operator (::) to access global variable when a local 
    variable of the sanem name is in scope. The unary scope resolution operator cannot be be used 
    to access a local variable of the same name in an outer block. A global variable can be accessed 
    directly without the unary scope operator if the name of the global variable is not the same
    as that of a local variable in scope.



*/
/*
    #include <iostream>
    using namespace std;

    int number{7};

    int main(){
        double number = 10.20;

        cout << "local variable = " << number << endl;
        cout << "global variable = " << ::number << endl;

        cout << "\n Remeber \n Allways use :: to call global vairbale to be clear." << endl;

    }

    Allways start using the unary scope opperator :: to refer to global variables (even if 
    there is no collision with a local-variable name) it makes your intentions clear.
    -Also makes the programs easier to modify
    --Also stops accidental hiding the global variable when a new one is called.
    ---Also just avoid this all togther.



    Function Overloading allows sevral function of the same name to be defined, as long as they have
    different siginatures This is called function overloading. 
    
    The C++ compiler selects proper function to call by examining the number order and type of the 
    arguments in the call.

    Function overloading is used to create functions of the same name that preforme similar tasks but 
    on different data types.Overloaded functions are distinguished by therir signatures. 


    #include <iostream>
    using namespace std;

    int square(int x){
        cout << "square of interger " << c << " is ";
        return x * x;
    }

    double square(double y){
        cout << "square of double" <, y << "is";
        return y * y;
    }

    int main(){
        cout << square(7);
        cout << endl;
        cout << square(7.5);
        cout << endl);
    }
    // So the compiler knows which function to call based on the name and paramater types (in order).
    // The compiler encodes each function identifier with the types of its parameters
    // Sometimes refered to as name mangling or name decoration to enable type safe linkage
    

------------------------------Type Safe Linkage ------------------------------------------

    name mangling or name decortion is when the compiler encodes each function dentifier with the type of
    its parameters.

    Type safe linkage ensures that the proper overloaded function is called and the types of the arguments 
    conform to the types of the parameters.

    GNU C++ each mangaled name (other then main) begins with two unerscores __ followd by the letter z a
    number and the function name. the number that follows z specifies how many characters are in the 
    functions name for example function square 

    ----------------------- Name mangaling to enable type safe linkage ----------------------

int square(int x){
    return x*x;
}
double square(double y){
    return y * y;
}

void nothing1(int a, float b, char c, int& d) { }

int nothing2(char a, int b, float& c, double& d){
    return 0;
}

int main(){}

//__Z6squarei
//__Z6squared
//__Z8nothing1ifcRi
//__Z8nothing2ciRfRd
//main

// All compilers do this different 
// Visual C++ produces the name square@@YAHH@Zfor the squaure function
// The gnu C++ compiler did not mangle main's name; however, some compilers
// Do for example For Exampel Visual C++ uses_main.


Creating over loaded functions with identical parameter lists and different return types
is a compileaton error.

The compiler onley uses the paramter lists to distinguish tbetween overloaded functions 
such functions need not have the same number of parameters Use caustiuon when overlading 
functions with default functions because this may cause ambiguity and confustion 

As you may end up passing all the same values into a a overladed function and 
confusing the compiler

for example if a function that explicity takes no arguments and a function
of the same name contains all default arguments results in a compilation error 
when an attempt is made to use that function name in a call passing no arguemts

Overload opperators define how the compiler should operate of objects of
user deined data types. In fact weve been usiong to many overloaded opperators to this
point, including all the stream insertion << stream extraction >> opperators which are 
OVERLOADED FOR ALL THE FUNDEMENTAL TYPES!


------------------------------Function Templates----------------------------------------

All function definitions begin with the template keyword followed by a template parameter
list enclosed in the handle brackets <and> every typename in the parameter list 

Function Templates begin with the 
Template keyword followed by a 
Template parameter list enclosed ion andle brackets 
Every Parameter in the template parameter list 
is Precceded by keyword typename or keyword 
class. (they are synonoms in this context)


The type parameters are placeholders for the fundemental or user defined types.
The placeholders in theis case, T, are used to specidy the types of the 
functions parameters. to specify the return type (line4 and to declare variables within 
the body of the function definitonn a function template is defined like anyother function
 */


// This goes in the maximum.h header file.
//template <typename T>
//T maximum(T value1, T value2, T value3){ // Place holder for the type of data to be tested by function maximum
//    T maximumValue{value1};
//
//    if(value2 > maximumValue){
//        maximumValue = value2;
//    }
//    if(value3 > maximumValue){
//        maximumValue = value2;
//    }
//    return maximumValue;
//}


/*


#include <iostream>
//#include maximum.h
using namespace std;
template <typename T>
T maximum(T value1, T value2, T value3)
{ // Place holder for the type of data to be tested by function maximum
    T maximumValue{value1};

    if (value2 > maximumValue)
    {
        maximumValue = value2;
    }
    if (value3 > maximumValue)
    {
        maximumValue = value2;
    }
    return maximumValue;
}
int main(){
    cout << "Input three interger values";
    int int1, int2, int3;
    
    cin >> int1 >> int2 >> int3;
    cout << "The maximum interger value is: " << maximum(int1, int2, int3);

    cout << "\n\n Input three double values: ";
    double double1, double2, double3;

    cin >> double1 >> double2 >> double3;
    cout << " The maximum double value is: "
         << maximum(double1, double2, double3);

    cout << " Input three characters ";
    char char1, char2, char3;

    cin >> char1 >> char2 >> char3;

    cout << " The maximum char value is " 
        << maximum(char1, char2, char3) << endl;

}

// This goes in the maximum.h header file.
//template <typename T>
//T maximum(T value1, T value2, T value3)
//{ // Place holder for the type of data to be tested by function maximum
//    T maximumValue{value1};
//
//    if (value2 > maximumValue)
//    {
//        maximumValue = value2;
//    }
//    if (value3 > maximumValue)
//    {
//        maximumValue = value2;
//    }
//    return maximumValue;
//}

-----------------------------------------------------------------------------------------


                                          Recursion


-----------------------------------------------------------------------------------------

For some problems its good to have functions call themselves. A recursive function os a function 
that calles itself either directly or indirectly (through another function)

Note:  Main should not be called recursively because its sole purpose is a starting point. // Main break?


Recursion Concepts 
Recursive problem-solving approaches have a number of things in common.

-The function only knows how to solve the base case(s) (simpilist case(s)).

--If the function is called with a base case it simpily returns a result.

---If a function is called with a more complex problem it typically devides the problem into to pieces 

----One that the function knows how to do and one it does not.

-----To make this even feasable the latter piece MUST resemble the original problem

------but be a slightly simplier or smaller version.

-------This new problem lookes like the original, so the function calls itsa copy of itself to work on 
        the smaller problem

--------This is called a recursive call or the recursion step

Omiting the base case or writing the recursion step incorrectly so that it does not converge on the base 
causes a infinite recursion error, typically causing a stack overflow. This analogous to the problem of
a infinite loop in an iterative (non recursive solution).

The recursion step executes while the original call is still open i.e., has not finished executing.

    the recursion step can result in many more such recursive calls. as the function keeps 
    dividing each new subproblem with which the function is called into two conceptual pieces.
    IN order for the recursion to eventually terminate, each time the function calls itself
    with a slightly simpler version of the origina;l problem this sequence of smaller and smaller
    probnlems converge on the base case. At that point the functin reconizes a base case and returns
    a result to the previous copy of the function and a sequence of returns ensues up the line 
    until the original eventually returnes the result to main.



Factorials:
    The factorial of a nonnegative interger n written n! is the product

    "n * (n - 1) * (n - 2) * ... * 1" 


Iterative Factorial:
    the factorial of a interger , number, greater than or equal to 0, can be calculaterd iterativelty 
    (non recursivbely) by using a forstatement as follows:
        
        factorial = 1;
        for (unsigned int counter{number}; counter >= 1; --counter) {
            factorial *= counter;
        }
    
    
    
Recursive Factorial:

    n! = n * (n - 1)!

    5! = 5 * 4 * 3 * 2 * 1
    5! = 5 * (4!)

    Values form each recursive call
     5!
        5 * 4!
            4  * 3!
                3 * 2!
                    2 * 1! 
                        1  <-- Returns 1
    */

//   #include <iostream>
//   using namespace std;
//
//   unsigned long fibonacci(unsigned long);
//
//   int main()   {
//    for(unsigned int counter{0}; counter <= 10; ++counter)
//        cout << "fibonacci(" << counter << ") = " << fibonacci(counter) << endl;
//    
//        cout << "\nFibonacci(20) = " << fibonacci(20) << endl;
//        cout << "\nFibonacci(30) = " << fibonacci(30) << endl;
//        cout << "\nFibonacci(35) = " << fibonacci(35) << endl;
//   }
//    unsigned long fibonacci(unsigned long number){
//        if((0 == number) ||  (1 == number)) { // base cases
//            return number;
//        }
//        else {
//            return fibonacci(number - 1) + fibonacci(number - 2); // recursive call if not base case
//        }
//    }



        //                      Evaluating the Fibonacci
               
        //
        //                          Fibbonacci( 3 )
        //                          /              \
        //         return Fibonacci( 2 )   +   Fibonacci ( 1 )
        //                  /                               |
        // return Fibaonacci( 1 ) + fibonacci ( 0 )      return 1
        //          |                       |
        //         return 1             return 0
        //
        //


/*  
    Most assume that the opperands are evaluated left to right but C++ does not specify the order in
    which the opperands of most operators (including +) are to be evaluated. Therefore, you must make no 
    assumption about the order these execute it could be former latter latter former, in this progam and 
    most others it turns out the final result could be the same, HOWEVER in some programs the evaluation
    of a opperand can have side effects (changes to data values) that could effect the final result of 
    the expression 

    C++ Sepcifies the order of evaluation of the operands of only four operators
     -- &&, || , (,) , and (?:).

    The first three are bibary operators guarenteed to be evaluated left to right. The last operstor is 
    C++'s only ternary operator -- Its left most operand is allways evaluated first; if true then the
    midle then last if false then the last only ignoring middle.

    Never depend on the order of the opperands that are not the -- && || ?: this can lead to logic errors


                                        Be Careful With Recursive Calls
    Each level ove recursion in the fibonaci function has a doubling effect on the ammount of calls
    ie the number of recursive calles required to calculate the nth fibvonacci number is on the order
    of 2 to the n 2 ^ n so  2 ^ 20 is about a million calls 2 (30) if number = 30 is near a billion calls 
    Computer scientist refer to this as exponential complexity
    problems of this nature can humble even the most powerful of computers.



    Recursion vs iteration 
        - Both are based on a controll statement
        - Both involve iteration, recursion achives this through function calls
        - Iteration and recursion involve a termination test
        - Itteration when a loop continuation condition fails 
        - Recusrsion when a base case is reconised.

        - Counter Controlled iteration and recursion gradually approach termination
        - Iteration modifies a counter unteil the counter assumes the value that makes the loop
        - Continuation condition fail; recursion produces simpler version ofd the original problem
         -until the base case is reached.

         -- Both iteration and recursion can happen inffinitley; an indfintiel loop when the conditions 
         never become false

         -- recusuon occurs if the recursion step does nott reduce the problem during each recursice call
         in a manner that converges on the base case.

*/
/*
// Itterative Factorial
#include <iostream>
#include <iomanip>
using namespace std;

unsigned long factorial(unsigned int);

int main(){

    for(unsigned int counter{0}; counter <= 10; ++counter){
        cout << setw(2) << counter << "! = " << factorial(counter) << endl;
    } 
}
unsigned long factorial(unsigned int number) {
    unsigned long result{1};
    for (unsigned int i{number}; i >= 1; --i) {
        result *= i;
    }
    return result;
}

// Recursion can have negatives, It repeteadelt revokes the mechanisim and 
// consequently the over head of function calls. This can be expensive 
// in both processor time and space.


// It coppys the variable and happens so the over head of repeated function calls and
// memory is ammited.

  

            "Any problem that can be solved recursively can be solved iteratively."

    - recursive is chosen when it is more natural and sometimes it can be the only visible solution

Avoid recursion in preformance situations 

Acidentally having a nonrecursive function call itself either directly or indirectly
(through another function) is a logic error.

Wrap up

Functions rand and srand seeded random
C++ 14 Digit seperators
Define sets of constants and enums 
Scope of Variables
Two differnt ways of arguments reference and value 
refrences as a alias to a vairable
Inline functions 
Default Arguments
Overloading functions with 
Function templates wehre a function is dfined once but uses several different types 
Recursion 

*/
/*
//Prime Number Factor

#include <iostream>
#include <cmath>
using namespace std;

void primeFactor(unsigned int, unsigned int divisor = 2);
int loop{0};
unsigned int original;

int main() {
    unsigned int number;
    cout << "Enter positive interger: ";
    cin >> number;
    original = number;

    cout << "Prime factors of " << number << " are : " ;
    primeFactor(number);

    return 0;
}

void primeFactor(unsigned int number, unsigned int divisor) {
    int& loopref = loop;
    if(number <= 1) {                           // Testing aganst the size of the number
        return;
    }
    if (divisor > sqrt(original)){                //esting against the square root of tghe original
        cout << original << " is prime" << endl;
        return;
    }
    if(number == divisor && loop == 0){         // Testing againsy the divisor
        cout << original << " is prime" << endl;
        return;
    }
    if(number % divisor == 0) {                 // Testiong against the incrimenting diviso untill we get equal to number above
        cout << number << " ";
        loop += 1;
        primeFactor(number / divisor, divisor); // dividing the number by divisot
    } 
    else {
        return primeFactor(number, divisor + 1);   // incrimenting the divisor and recursioning
    }
}
*/
/*
#include <iostream>
using namespace std;

int GCD(int number,int number2);

int main (){
    int number1, number2;
    cin >> number1 >> number2;

    cout << GCD(number1, number2);
    return 0;
}

int GCD(int num1, int num2){
    int min{0};
    int max{0};
    if(num1 > num2){
        min = num2;
        max = num1;
    }
    else{
        min = num1;
        max = num2;
    }
    for(int i{0}; i < min; i++){
        if(i == min){
            return min;
        }
        if(min % max != 0){
            min--;
        }
        else
            return min;
        
    }
    cout << "GCD" << endl;
}




        OKAY OKAY IM BACK


        Towers Of Hanoi Using recursion
        shift (n-1) disks from rodA to rodB using rod C 
        shift last disk from A to C 
        shift (N-1) Disks from rodB to rodC using rod A

        return fuinctin where passing the N, from_rod, to_rod, aux_rod.
        Make a function call for N-1th Disk
        then print the current disk along with form_rod and to_rod
        Again make a functin call for N-1th disk.

*/

// C++ recursive function to
// solve tower of hanoi puzzle
#include <iostream>
#include <iomanip>
using namespace std;
  
void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
  
// Driver code
int main()
{
    int N = 3;
  
    // A, B and C are names of rods
    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}
//Time complexity: O(2N), There are two possibilities for every disk. Therefore, 2 * 2 * 2 * . . . * 2(N times) is 2N
//Auxiliary Space: O(N), Function call stack space  
//// This is code is contributed by rathbhupendra#include <iomain