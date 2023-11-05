/*
---------------------------------------------------------------------------------------------------------

                                        Classes Part 2

--------------------------------------------------------------------------------------------------------

        Deeper Look At Classes, Time, Date and Employee case studys...

    Time Class:
        First we look at a time class that is engineered to seperate its interface from its implemention
    allowing for reuse...

    Include Guard:
        Using a incluide guard in a header prvent header code from being used more then once, which 
    usually results in compilation errors. In addition the class, time uses ostring streeam to 
    create string implementations of the time in standard and univeraial time formats.

    Were also going to touch on the compilation and linking porcess from the standpoint of the 
    class-implementation programmer, the client-code programmer and the application user.

-------------------------------------------------------------------------------------------------------

    
    We demonstrate how client code can access a class's public members via
    
    - the name of an object and the dot operator (.)
    - a reference to an object and the dot operator (.)
    - a pointer to an object and the arrow operator (->)
    
    We discuss access functions that can read or write an object's data members. A common use 
    of access functions is to test the truth or falsity of conditions - such functions are
    known as predicate functions.

    We also demonstrate the notion of a utility function (also called a helper function) - a 
    private member function that supports the operation of the class's public member functions 
    but is not intended for use by clients of the class.
    
    We show how default arguments can be used in constructors to enable client code to initialize
    objects using a variety of arguments. Next, we discuss a special member function called a 
    destructor that's a part of every class and is used to perform "termination housekeeping" on
    an object before it's destroyed.
    
    We also demonstrate the order in which constructors and destructors are called.
    
    We show that returning a reference or pointer to private data breaks the encapsulation of 
    a class, allowing client code to directly access an object's data.
    
    We use default member-wise assignment to assign an object of a class to another object of 
    the same class.
    
    We use const objects and const member functions to prevent modifications of objects and 
    enforce the principle of least privilege.
    
    We discuss composition, a form of reuse in which a class can have objects of other classe
    s as members.
    
    We use friendship to specify that a non-member function can access a class's non-public 
    members, a technique that's often used in operator overloading (Chapter 10) for performance and structural reasons.
    
    We discuss the `this` pointer, which is an implicit argument in all calls to a class's
    non-static member functions, allowing them to access the correct object's data members as
    non-static member functions.
    
    We motivate the need for static class members and show how to use them in your own classes.
    

--------------------------------------------------------------------------------------------------------------

    Include guard: 
    --- Makes it so we need only declare the header in the source once making the client facing code
        much more secure.

    Interfaces of a Class:
    --- Define and standardize the ways in which things such as people or systems intreract with one
        anoter (e.g.) The radio's controlls serve as a interface between the radios users and internal
        components.

    --- Interface of a class describes what services a class's clients can use and how to request those 
        services, but not how the class carries out those services.

    --- A classes public interface consists of the class's public member functinons also known as the
        public services.

    --- Specify a classes interface by writing a class definition tthat list only the class's
        member function prototypes and the class's data members.

    
    Seperating the Interface from the Implementation:
    
    --- To seperate the class's nterface from it's implementation, we breack up cvlass Time
    into two files- the header Time.h ain which class Time is defined, and the source code 
    file Time.cpp in which times member functions are defined - so That 
        
    1.) The class is reusabele.

    2.) The clients of the class know what member functions the class provides how toi call them 
        and what return types to expect and 
    
    3.) The clients do not know how the class's member functions are implemented.
    
    --- By convenion, member-function definitons are placed in a source code file of the same base
        name (e.g Time) as the class's header but with a .cpp file name exrtension (some compilers
        support oopther filename extensions aswell.)...
    
    Below we see how this theree file program is compiled form the persepcifve of the Time class 
    programer and trhe client-code programmer-and what the time class application user sees/

    The header Time.h contains the Time's class definition.  Instead of a function definitions,
    the class contains function prototypes that describe the class's public interface  without 
    revealing the public member-functions implementation,
*/
/*
#include <string>
#ifndef TIME_H  // Include Guard enlcoses the classes definition if not defined
#define TIME_H  // Define

class Time{
    public:
        void setTime(int,int,int);
        std::string toUniversalString() const;  // these are inline i beleive...
        std::string toStandardString() const;   // these are inline i beleive...
    private:
        unsigned int hour{0};
        unsigned int minute{0};
        unsigned int second{0};
};
#endif  // these prevent the code between #ifdef anf #endif from being #included
        // if the name TIME_H has been defined 

        // Pragma used to be a alternate way to implement a include guard in the compiler


#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;

void Time::setTime(int h, int m , int s) {
    if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)) {
        hour = h;
        minute = m;
        second = s;
    }

    else {
        throw invalid_argument(
            "hour minute and/or second was out of range");
    }
}
string Time::toUniversalString() const {
    ostringstream output;
    output << setfill('0') << setw(2) << hour << ":"
        << setw(2) << minute << ":" << setw(2) << second;
    return output.str();
}

string Time::toStandardString() const {
    ostringstream output;
    output << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
        <<setfill('0') << setw(2) << minute << ":" << setw(2)
            << second << (hour < 12 ? " AM" : " PM");
        return output.str();
}
*/
/*  
    Member Functions Names:
    --- Are preceded by the scope resoluton operator (::). This ties them to the (now 
        sepearate) Time Class Defintion which declares the class's members. The time::
        tells the compiler that each memebr function is with in that class's scope and
        its name is known to the other class members.

    --- If we didnt have the scope operator telling the compiler these funcitons are from
        time they would be global functions, not able to access times private data or 
        the classes member functions without specifying a object.

    
    Ostringstream <sstream>:
    --- Class creates objects that provide the same functionality as cin cout 
        stream operators but they do this into a a string objects in memory.

    --- You can use the class ostringstream's str member function to get the formatted
        string.
    
   
    setfill() <sstream>:   
    --- Used to specify the fill character thats displayed when an interger is output 
        into a feild that is wider then the number of digits in the value.

    --- The fill characters appear to the left of the digits in the number bause the 
        number is right alligned by default.

    --- For left alligned values the fill characters would appear to the right. In this 
        example if the minute value is is 2 the value will be displayed as 02 because 
        the fill character is set to 0.

    --- Once the fill charactr is specified with sef fill it applies to all subsequent 
        values that displayed in display feilds wider then the number digits of the value.
    
    --- Setfill() is a non-sticky setting.


    Implicitly Inlining Member Functions:
    --- If a member function is declared in a classes body it is implicitly declared 
        inline. Rember that the compiler reserves the right to not inline any funciton...
    
    --- This can inprove preformance...
    
    !!! Only the simplist and most stable member functins (whos implementations aren't
        likly to change) should be defined int the class header, because every change 
        to the header requires you to recompile every source code file thats dependent 
        on that header (a time consuming task on large systems.)


    Member funtcions vs Global Functions:
    --- The toUniversalString and toStandardString member functions take no argument's,
        this is because they implicitly know that they are they're to create string 
        representations of the data !!! AT THE TIME THEIR INVOKED !!!

    --- Member functions usually are shorter then functions in non object oreinted programs.
        because thje data stored in member functions have ideally been validated by a 
        construcor or by member functions that store new data. Because the data is 
        allready in the object, the member functions calls usually have little to no 
        arguments compared to function calls in  non object oriented languages. Thus the 
        calls function prototypes and function definitons are shorter. This improves many
        aspects of program development.

    --- Also they have less likely hood to pass incorect arguments if we pass little to 
        no arguments at all.
    

    Using Class Time:
    --- Once A class like time is defined it can be used in type definitions such as

        Time sunset;                    // Object of type time
        array<Time, 12> arrayofTime;    // Array of 12 time Objects
        Time& dinnerTimeRef{sunset};    // Reference to a time object
        Time* timePtr{&sunset}          // Pointer to a time object

        "Seperating a classes interface from the implementation of its member functions does
            not addect the way that this cliient code uses the class. It only effects how 
                the client code is compiled and linked."

    --- Includeing the time header lets the compiler know how much space to reserve for time object 
        and ensure the time objects are created and manipulated correctly in the code.


*/
/*
#include <iostream>
#include <stdexcept>
#include "time.h"
using namespace std;

void displayTime(const string& message, const Time& time) {
    cout << message << "\nUniversal TimeL " << time.toUniversalString()
        << "\nStandardTime" << time.toStandardString() << "\n" << endl;
}

int main() {
    Time t;

    displayTime("Initial time:", t);
    t.setTime(13,27,5);
    displayTime("After Set time", t);

    try{
        t.setTime(99,99,99);
    }
    catch (invalid_argument& e){
        cout << "Exception: " << e.what() << "\n" << endl;
    }

    displayTime("After attempting to set an invalid time: " , t);
}


    Object Size:
        Logically objects should be very large and this is true but physically they arent
    as big as they seem.

!!!!Objects only data so objects are much smaller than if they also contained member functions
    The compiler creates one copy only of the member functions seperate from all objects of the
    class . All objects of the class share the one copy...
    
    Each Object of course needs its own copy of the class's data becasuse the datta can vary 
    among the objectys the functions clde is the same for all objects of a class and hence 
    can be shared amongst themselves.

*/
/*
------------------------------------------------------------------------------------------

                            Compilation and Linking Process

-------------------------------------------------------------------------------------------

    Often a classes iterface and implementation will be compiled by one programmer and 
    used and implemented by another programmer that uses the client code of the class.

    So they make a diagram to show whats needed by both the client code programmer and the 
    Class implementation programmer.

    A class implementation programmer is responsible for creating a reusabvle time class
    crates the header time .h and the source code fiel time .cpp that #include the header 
    then compielr sthe soource coude dile to create time objects code.

    to hide the class;s member function implemnentation details the class implementation programmer
    provides the client implementsion programemer witrh the headeer Time.h that specifies
    the class interface asn data members and the time object code (i.e the machine code instructions
    that reperesent Time's member functions).

    The client code programmer is not given time.cpp so the client remains unaware of how the 
    time members functions are implemented.

    The client code programmer need to only know the times interdace to use the class and 
    must be able to link its object code

    Since the interface of the of the class is part of the class definiton in the time.h 
    headerThe client code ptogrammer must have access to the file and must #include it 
    int the clients source code file. When the client code is compiled the compiler ueses
    the class definiton in Time.h to ensure that the main function creates and manipulates 
    objects of the time class correctly.

    To create the executable time application the last stepn is to link

    1 ) The object code from the main function 

    2 ) The object code for class Time's member dunction implementations

    3 ) The C++ Standard Library object code for the C++ Classes (e.g. string)
        used by the class implementation programmer and the client side programmer

        - - - - - - - - - - - -  -- - - - - -  
      /                              -- - - - \ -- - - - - - - - - - -- - - - - -                      
     /  Class implemantation       /           \                Client Code       \
    /       PROGRAMMER            /             \                PROGRAMMER        \ 
   |            ||               / _____________ \                   ||             |
   |         Time.cpp           / /    time H    \\   Main Function (client source code)
   |            ||              || Class Defintion||                 ||             |
   |         Compiler <------------ Interference ----------------> Compiler         |
   |            ||              |  \____________/  |                 ||             |
   |        Time Class          |   C++ Standard   |            Main Functions      |
   |        object code         |  Library Object  |            Object Code         |   
   |            \\              |      Code        |                //              |
    \             \\             \                /                //              /
      \             \              \             /              //                /
        \               \\           \          /            //                 /
          \_ _ _ __ _ __ _  \\ _ _ _ __\__ _ __/        //                    /
                                \\       \___ _ _   // __ _ _ _ __ _ _ _ _ _/
                                    \\          //
                                        Linker
                           -------------  ||-----------------------------------     
                           |              ||                                  |     
                           |        Time Executable         Time Application  |             
                           |          Application                  USER       |         
                           ----------------------------------------------------        


        The linker's output is the executuable time application that users can 
    execute to creat and manipulate a time object. Compiler and IDE's typically 
    invoke the linker for you after compiling your code.                             




How To Compile Programs With mutiple source code files:

--- In Visual Studio:
    Add to your project all the headers and source-coe filles that make up a program
    then build and run the project.
    You can place the headers in the project's Header Files folder and the source code
    in the projectrs Source Files folder, but these are mainlt for organizing files in
    large projects. We tested the book's programs bu placing all the files for each 
    program in the projct's Source Files folder.

--- For GNU C++:
    Open A shell and change into the directory containing all the files for a given program
    and execute the following command
    (g++ -std=c++14 *.cpp -o ExecutableName)

    "*.cpp" - Specifies that you want to compile and link all of the source-code files in the 
    current directory-- the preprocessor automatically locates the program specific headers in
    the directory.

--- For Apple XCode 
    Add to your project all the headers and source-code files that make up a program and then
    build and run the program.

------------------------------------------------------------------------------------------------

                            Class Scope and Accessing Class Members

--------------------------------------------------------------------------------------------------

    A class data members and member functions belong to that class's scope...
    NonMember functions are declared in the global name space scope, by default.

    Whithin a class members scope class members are immediately accessible by all that class's
    member functions and can be referenced by name. 
    
    Outside a class's scope public class members are referenced through an objects name, a 
    reference to an object, or a pointer to an object.

    We refer to these as Handels on a object the handle's type enables the compiler to determine
    the interface (e.g. the class members functions) accessable to the client via the handle.
    (the implicit handle is called a this pointer) is inserted bt the compieler on every reference
    to a data member or member function within an object.

----------------------------------------------------------------------------------------------------
    
        Dot (.) and Arrow (->) Opperators:

        Dot Member Selection:
    --- To reference the objects members we use the object name or referance to name followed 
        by a dot (.) opperator

        Arrow Member Selection:
    --- To reference the Via a pointer to the object we use the arrow member selection
         (->) Opperator 
        (e.g.) pointerName -> memberName 

        For Example:
        Consider an account class that has the public setBalance member function...

    Account account;                        // An Account object
    Account& accountRef{account};           // accountRef refers to an Account object
    Account* accountPtr{&account};          // accountPtr points to an Account object 
    account.setBalance(123.45);             // Call setBalance() via the Account object
    acconutRef.setBalance(123.45);          // Call setBalance() via a reference to the Account object
    accounyPtr->setBalance(123.45);         // Call setBalance() via a pointer to the Account object


Access Functions and Utility Functions:

    Access Functions:
    --- Can read or diasplay dat a, not modify it, Another use its to test the truth or falsity
        of conditions - such functions are called Predicate Functions An example would be a empty 
        function for any container class -- a class capable of holding many objects, such as an
        array or vector. 
    --- A program might tesst empty before attempting to read another item from the container object

    A Utility Function:
    --- Also called a helper function is a privvate member function that suports the operation of 
        a class's other member functions.
    --- Utility Fuinctions are declared private becasue their not intended for use by the classes
        clients.
    --- A popular use for a Utility Function would be to place in a function some block of code 
        that would otherwise be duplicated in multiple other member fucntions


------------------------------------------------------------------------------------------------------------

                                    Constructors With Default Arguments....

------------------------------------------------------------------------------------------------------------

//  There can be one default constructor per class.
//  The vesrsion of class time in this example provdes set and get functions for each dataq memeber.
//  The time constructor now calls set time which calls the set hour set minute and set second functions 
//  To validate and assign variables to the data memebrers
-- Any change that happends to the default arument values a function requires the client code to be 
recompiled(to ensure the program still functions correctly)

-- Chapter9Time File has the example for this subsection

Times set and get functions arte called thoroughout the class's body. In particular, function settime()
calls functions setHour, set Minute and setSecond and functions toUniversal string and tyo standard string
call functions gethHour, getMinute, getSecond in lines of MainTime.cpp

In each case, these functions could have accessed the calsses private diata directly. However, consider 
changing the representations of the time from three int values (requiring 12 bytes of memory insystems with 4 byte int's)
to a single int value representing the total number of seconds that has elapsed since midnight(requiring only
4 bytes of memory.)

If we did this change only the bodies of the functions that access the private that directly would need to change
in particular the individual set and get functionf for the hour minute and second. There would also be no need to modfy
the bodys of the functions setTime, toUniversalString or toStandard string, because they do not access the data directly
similarly the time constructor could be written to include a copy of the appropriate statemeents from function setTime and 
doing so may be slightly more efficent, becasue the extra call to setTime is eliminated however duplicating statements
in mutiple functions or constructors makes changing the classes internal data reperisentation more difficult.

having the Time constructor call setTime and having setTime call setHour, setMinute, and setSecond enables us to limit 
the changes to code that vaidates the hour minute or second to the corresponding set function.

This reduces the likelyhood of errors when altering the classes implementation

If a member function of a class allready provides all or part of the functionality required by a constructor or other 
member functions of the class call that member function. This follows the rule of theumb of do not rewrite code.
also significantly reduces the chance of an error....

A constructor can call other member functions such as set and get functions but becasue the constructor is initializing the
object, the data members may not be initialized... Using data memebers before they are initialized casuese logic errors.

making ddata members pricate and controlling acceess, espicially write access to those members through public member functions
ensure data integrity.

The benifits of data intergrity are not automatic simply becasuse data members are made private-- tou must provide appropriate
validity checking 
*/
/*
Over Loaded Constructors and C++11 Delegating constructors 
Over loaded functions are in Chapter 6

Overloaded Constructors typically allow objects to be intialized with different data types and/or number of arguments
To overload a constructorm provide in the class definition a prototype for each version of the constructor, and provide 
in the class definition a prototype for each version of the constuctor, and provde a seperate constructor definition for
each overloaded version. This also applies to the class's member functions.

In the Chapter9Time example the time constructor with three differet parameters had a default argument for each parameter
Time(); // Defualt hour and minute set to zero
explicit Time(int,) // init hour; default minute and second to -
Time(int, int)l     // Initialize hout and minute; default second to 0
Time(int, int, int);// Initalizse hour, minute and second.


So just as a constructo can call a class's other member functions to preform tasks, C++11 allows constructors to call 
other constructors in the same class. The calling constructor is know as a delegating constructor-- it delegates its
work to another constructor. This is useful when overloaded constructors have common code tha previously would have been
definded in a private utility function and called by all the other constructors.

The first three of the four constructors declared above can delegate work to one with three int arguments, passing 0 as 
the default value for extra paramters. to do so you use a member intializer with the name of the class as follows:

Time::Time() : Time{0,0,0} {}                               //  delegate to Time(int, int, int)
Time::Time(int hour) : Time{hour, 0,0} {}                   //  delegate to Time(int, int, int)
Time::Time(int hour, int minute) : Time{hour,minute,0} {}   //  delegate to Time(int, int, int)


---------------------------------------------------------------------------------------------------------------------------------------------------

                                                Deconstructors

------------------------------------------------------------------------------------------------------------------------------------------------------

Deconstructor is another type of special member function. the name of the deconstructor for a class is a tilde character (~) followed by the class name
        explicit ~CreateandDestroy 


    Using the tilde character has a intuitive feel becasue in the later chapters well see that the tilde character is the bitwise complement operator(~)
    
    And really the deconstructor is the compliment of a construstor.

    A deconstructor may not specify parameters or a return type


A classes deconstructor is called implicitly when an object of the class is destroyed...
This occurs as the program execution leaves the scope an object is instantiated ...

The deconstructor itself does not release a object's memory it preforms termination house keeping... before the objects memory is reclasmed
so the memory may be used to hold new objects. 

Even though deconstrictors are not delcared for the above classes every class has exactly one deconstructor. If you do not explicitly define
a deconstructor one will be apointed to you by the compiiler. In the nect chapter we beuild deconstructors appropriate fot classes whose
objects contain dynamically allocated memory, in chapter 17 we explain why exceptions should not be thrown from deconstructors.

Constructors and deconstriuctors are called implicitly when object are created and when their about to be removed from memory respectively. 
The ofer in which these functiopn calls occur depends on the order in which execution enters and leves the scope where objects are instansiated
generally deconstructor calls are made in the reverse orfer of the coresponding constructor calls, but as well see in figures 9.8-9.10, the 
global and static objects can alter the order in which objects are called.



Constructors and Deconstructors for Objects in a Global Scope:
    Constructors are called for objects defined in a global Scope(also clled global namespace scope...) before anyother function (including main..)
    in that program.
    In that program begins execution (although the order of execution of global object constructors between files are not guarenteed)
    The corespoinding deconstructors are called when main terminates. Function exit forces a program to terminate immideately and 
    does not execute the deconstructors of local objects
    
    the exit commnd ofit is used to terminate a program when a fatal unrecoverable error occurs.Function abort performs similarly to function exit
    but forces the program to terminate immediately, without allowing programmer defined clean up code of any kinf.

    Exit
        -- Deconstructor is called for global and static objects
    Abort
        -- Abort Function does not call deconstructors for static local variables.

    Constructor(){}
    ~Deconstructor(){}  // Note deconstructor shares the same name as constructor so these member functions are for different classes.

Constructors and Deconstructors for static Local Objects:

    The constructor for a static local object is called only once, when execution reaches the point 
    where that objhect is defined-- 
    the correspoinding deconstructor is called when the execution leaves the objects scope(i.e the block
     in which that object is defined finishes executing.)
    The deconstructor is called when main terminates the program or the program calls function exit.    
    Global and static objects are destroyed in the reverse order of their construction.
    Deconstructors are not called for static objects if the program terminates with a function called to abort


Demonstrating when Constructors and Deconstructors are called:

    See Create and Destroy Folder

Just as a constructor can call other member functions to preform tasks , C++11 also allows constructors to call other constructors
within the same class. The calling constructor is known as the delegating constructor... because it delegates its work to another constructor
this is defined in a private utility function and is called by all the other constructors.

    Overloaded constructurors typically allow object to be inialzed with different types
    and/oir numbers of arguments. To verload a constructor provide the class definition a prototype for each vertsion of the constructor,
    and privide a seprate constructor definition for each overloaded mversion... this also applies to the clsses member functions




*/
/*

    Returning a Reference or a Pointer to a private Data Member
    A reference to a object is an alias fot the name of the object and hence mayu be used on the ledt sign og an assignment statement.
    In this context the reference makes a perfectly acceptable lvalue that can recieve a value.

    A member function can return a reference to a prvate data member of that class. If the reference return type is declared const, 
    the reference is a nonmoddifiyable lvalue and cannot be used to modify the data. However, if the reference return type is not 
    decalred const, subtle errors can occur.

    In the CH9TimeReturning a referance ot a Pointer to a private Data Memeber 
    We see the issues as the member function badSetHour()...

    Such a reference return actually makes a call to member function badSetHour an alias fot private datamember hour!

    the function call can be used in any way that the pricate data member can be used incuding as an lvalue and this enables
    the clients of the class to clobber the class's privatge data at will.. a similar problem would aoccur if a pointer to the 
    private data were returned by the function... instead of the reference currently.....


    TimeMain.cpp declares the time object t(line 9) and a refernce hourRef(line 12 in the book) wich is intialized with the
    reference returned by the call t.badSetHou(20)...

    Line 14 displays the calles of the alias hourRef... this shows how hourRef breaks the encaplsulation of the class
    statements in main shoud not have acces to the private data  in the object class....

    Next line `5 uses the alias to set the value of thour to 30 (an invaluid value) and line 16 displays the value returned by 
    function get hour to show that assigning a value to hourRef actually modifes the private data in the time object t... 

    Finally... line 20 uses the badSetHour function call itself as a lvalue and assigns 74 to the refernece returned by the function. Line 25
    again displays the value returned by the functiun gethour to show that assigining a value to the result of the function call in line 20 modifies 
    the private data in the time object...

    hourRef = 30;

    t.badSetHour(12) = 74;

    t.getHour... 30.... 74.... not < 24 like the boundaries that we set up in the Time.cpp file that we used earlier...


*/
// Header is where we define a class and a object                               //  We want to hide this implementation
// The CPP File is wehre we deinf the member functions... and how the bject is  //  We want to create this interface
// Main is where we compose and use objects wioth member objects                //  We want to write the cient code...


/*  Default Member Wise Assignment
    
    --  The assignment opperaror (=) can be used to assign an object to another object of the same class.
    --  By Default , such assignmentis prefgormed by member wise assinment also called copy assignment.
    --  Each data member of the object on the right of the assignment operator is assigned individually to the 
        Same data member in the object on the left of the assignment operator. 


    //  See Default member wise assignment File.

    Objects may be bassed as function argumnts and may be returned from functions... such passing and returning is 
    preforemd using pass by value by default A COPY of that object is passed and returned...



    In this case the the month member of date1 is assigned to the month member of date2, and the date member of
    day1 is assigned to the date member of date2 and the year member of day1 is assigned to the yar member of day2.

    Caution Member wise assignmemnt can cause issues when used with a class whose data members contain pointers to
    dynamically allocated membery...

    Objects may be passed as function arguments and my be returned from functions....
    Such passinhg and returning is done by pass by value by default-- a copy ogf the object is passed and returned./..

    IN Such casses as passing and returning a object in a function C++ creates a new object with the copy constructor for the purpose
    of taking the values of the object into a ne object...

    For EACH CLASS the compiler provides a default coipy constructor that copys each member of the original object.. into the 
    corresponding member of the new object...

    AND like MEMBERWISE ASSIGNMENT copy constructors can cause issues wwen used on a class whos data members contain pointers
    to dynamically allocated memory.

    CHAPTER 10 discusses how to define customized copys of constructors that properlly copy such objects...


    -- Const Objects and const Member Functions    
        + lets see how the pricnipal of least priviledge applies to objects
        + Some objects need to be modifiyable and some objects do not.
            + You can use const do delclare a object is non modifyable and any attempt too do so should result in a compilation error..
            
            const Time noon{12,0,0};
    
            + Declares a const object noon of class Time and initalizes it to 12 noon. It's possible to instantiate const and non-const
              on objects of the same class.

        - attempts to modiy const object are caught at compile time rather than causing execution time errors...

        + Preformance Tips
        + Declaring objects const when appropriate can imporve preformance compilers can preform preformance optomization on constants
          That cannot be preformed on non constant variables.
        + Defining as const a member function that calls a non const member funtion aof the class on the same object is a compilation
          error.
        
        + C++ Disallows member-function calls for const objects unless the member functions themselves are also declared const... 
          This is true even for get memberfunctions that do not mofdify the object this is alsoa key reason that weve declared as const
          all member functions that do not modify the objects on which their called. like getDate... 
        + Involind a non constant mmember function on a const object is a compilation error

        + Constructors and Deconstructors have a Interesting problem here.. each of these typically modify an object so the object can 
          be initalized. A deconstructor must be able to preform its termination house keeping before an object's memory is reclemd 
          by the system... Attempting to declare a construucor or deconstructor const is a compialtion error. The "costness" of a const object
          is enforced from the time the constructor completes the initialization of the object until that objects deconstructor is called.

        #include "Time.h"

        int main() {
            Time wakeUp{6,45,0};        // Non-Constant Object
            const Time noon{12,0,0};    // Constant Object  
                                        // Object           Member Function
            wakeUp.setHour(18);         // Non Const        Const
            noon.setHour(12)            // Const            Non-Const
            wakeUp.getHour()            // Non Const        Const
            noon.getMinute()            // Const            Const   
            noon.toUniversalString()    // Const            Const
            noon.toStandardString()     // Const            Non-Const

        }    

        A constructor must be a non const member function, but can still be uused to initalize a const object 


        -- Composition: Objects as Members of Classes
        + An alarm clock object would need to know thein its supposed to sound its alarm.... So why not include
          a time object as a member of th AlarmClock class?
        + Such software reusability is called composition(or aggregation) and is sometimesrefered to as 
          + has-a-relationship, a class can have objects of other classes a members.
            + Classes my also be derived from other classes that privide attributes and behaviors that the new classes can use
              this is called inheritence...

        + You've actually used compostition since Chatpter 3. In that chapter's examples, 'class Account' contained a
          string object as a data member
        + Previouslly we saw ho to pass arguments into the constructor of an object we created in main. Now we show how
          a class constructor can pass arguments to member-object constructors via member initalizers.




--- Next Program:

        
        Friend functions and friend classes... 
            + A friend function of a class is a non-member functin that has the right to access the public and non public class
              members... Stand alone functions, entire classes or member functins of other classes may
              be declared to be friends of another class.

        Declaring a friend function...
            + To declare a non-member function as a friend of a class, place the function prototype in the class definition 
              and precede it with the keyword friend.
            
            + To Declare all members of ClassTwo of friends of ClassOne place a delcartion of the form...

            friend class ClassTwo

            + Inside the defintion of class ClassOne

        The Friend Declarations can appear anywhere in the class and are not addected by access specidiers piublic or private
         (or protected in which we discuss in Chapter 11)

         Friend ship is granteed not taken from class A... Class b cannot delcare it is a friend of class a and it be so.

         Class A must explixitly declrer that class B is its friend... Friendship is not symmetric... Class A declareing 
         B is a friend of it, does not mean that it Class A is a friend of Class B... Friuendship is not 
         transitive either. If class is is a friend of class b and class b is a friend of class c that does not meaan that class
         C is a friend of Class A...


        // See CH9Friends folder for a example of this behavior

        

--------------------------------------------------------------------------------------------------------------------


        Using the this pointer

There's only one coppy of each classes functionalitiy, but there can be many objects of a class... so how do member'
functions know which object of the class to manipulate?


Every object hass access to its own address through a pointer called a this pointer?

Pinter called this(C++ Keyword )   "this"

        
        The this pointer is not appart of the object itself-- i.e the memory occupied by the this pointer is not
        reflected int the result of a "sizeof(opperation on the object)"

        Rather the this pointer is passed by the compiler as as an implicit argumernt to each of the objects 
        non-static membter funtions... (the next section explains why the this pointer is not implicitly passed
        to static member functions)
        

        Member funtions use the this pointer implicitly(as weve done so fat) or explcityl to referenace an
        object's data members...and other member functions... A common explicit use of the this pointer is
        to avoid naming coonflicts between a classes data members and member functiion parameters(to other 
        local variables.) If a member function contains a local variables and data member of the same name,
        as in the set hour function...

        void Time::setHour(int hour){
            if (hour >= 0 && hour < 24) {
                this-> hour = hour; /// using the this pointer to access a data member 
            }
            else {
                throwinvalid_argument("Hour must be 0-23");
            }
        }

        the local variable is said to hide or shadow the data member using just the variable name in the 
        member functions body refers to the local variable rather then the data member.

        However, you can acess the data member hour by qualifying its name with this-> So the the followig 
        statesment assigns the hours parameters;s value to the data member hour this->hour = hour;


        Type of the this pointer...


        The type of the this pinter depends on the type of the object and wheter the member function in which
        this is used is declared const...

        Implicitly and explicityl use the this pointer to acces an Objeccts Data Member....


        The next example we make demonstrates the implicit and xplicit use of the this pointer as we 
        enable the member function of the class Test to print the private data x of a test object.

        We also show some subtantial and subtle ways of using this in this example and in Chapter 10...
        Apparently...



        See CH9ThisPointer Folder for the example from Dantels book... 

        In the example we call the private data member like (*this).x 
        and we use the this pointer a non static member and the . operator to retireve the value at x

        I we were not to use the perenthesis we would inclorrectly be doing *this.x  which gorps liek this


        * (this.x) and we dont have a this object of the class with a data member x  so there is a 
        quite a difference and we actually dont end up using the "this pointer" (*this) or this->x or just x
        at all...


        Next we learn about.....





        Using the this pointer to Enable cascaded function calls... 

        
        Cascaded member-function calls is the action of envoking mutiple functions sequentially within the same statrtememtnt
        as we do in the next Example that we have to make..

        In the example were going to make arround line 10 we will end up using a this pointer to call cascaded member
        functions. We modify the time's set functions setTime, setHour, setMinute and setSecond such that  each 
        returns a referance to the time object on whiich its called, enabling the cascaded member function calls...



        Notice that in one of the figures of CH9Cascading the last stament of the body inb each of these member 
        functions returns *this into a return type of Time&. (a time object reference vaiable...)


        Note that at the end of or changed member functions we call the toStandardString() member function... this
        is member function being called does not return a this pointer and there for can not be used with any other 
        member functions after the call... however we can call string member functions after this call becasue we 
        return a string in the toStandardString Member functions...

        In the next chapter we will se many more differnet ways to use cascaded member functions ... one way including 
        mutiple << operators....

        


    Static Class Members.... 

        The rule stating that all objects of a class have their own copy of all the data members within the class
        has one exception... a static data member...

        A static data member is used to inialize a variable that should be SHARED BY ALL OBEJECTS OF A CLASS
        and some other use cases.

        Such a varirbale represents "class wide information"... 
        i.e. Data that is shared by all instances, and is not specific to any one object of the class.

        Recall in chapter 7 that the gradebook classes use static datamembers to store constants rerpresenting 
        the numeber of grades that all gradebook objects can hold..


    Motivating Classwide Data...

        Lets further motivate the need for static class wide data with a example...

        If we have a game that involves Martians and other space creatures... and the martians are cowardly 
        in attacking other space creatures when there is less then 5 of them....

        Well this means each martian needs to know the MartianCount... 
        
        We can endow each Martian object of the class Martian with a MartianCount Data member... But if we do
        then each martian will have a SEPRATE copy of the data member... Every time we create a new martian 
        we will have to update the martian count for all martians... see the issue... this is in efficent...
        (each martian would have to have a handle to all the other martians in the game... what a waist of space!)


        So what we do is...
        Declare MarianCount to be static, making it classwide data... 

        Now every martian will have acces to the MartianCount as if it were its own data member... 
        and we can increment the martian count up and down with the Constructor and Deconstuctor Alike!


    Scope of Classwide Data...
        A classes static data members have class scope. A static data mebmber must be initalized exactly once...
        Fuincdimential-type static data members are initalize by default to 0... prior to C++11, a static const 
        datamember of type int or enum could be initalize in its declaration in the class edefincition- all other 
        static const data memebrbs had to be deined and insitalized at global namespace scope (i.e outside of the 
        body of the class definition...)

        Ass of C++ l1 sll static const data members can have in class initalizers... This means that the 
        static data member need not be initalized becasuse the defauldt class constructor is called..


    Accessing static Data Members...
        A classes private and protected(chapter 11) static members are normally accessed through the class's
        public member function or friends...

        A CLASSES STATIC MEMBERS EXITS EVEN WHEN NO OBJECTS OF THAT CLASS EXIST

        If you want to access a classes static data members before any objects of the class exist you simply
        canb use the scope resolution operator (::) followed by the datya member you wish to access of the class
        example: Martian::MartianCount to get acces to the MartianCount Static data member of the class (before 
        any objects of the class even exist..) (ofcourse using public data to store these members is discouraged)

        To access private or protected static data members of a class when there are no objects of the class add 
        a static member function in to the class that returns the static data members and call the function by 
        prefixing it sname with the class name and scope resolution operaror... the static member fuction is a servant
        of the class not of a specific object of the class.

    Demonstrating static Data Members...
        The next programs demonstrates a private static data member called count. and a public static member function
        called getCount. 

        See CH9Static Folder for the example...
    

    Chapter 9 Wrap Up...

        This chapter deepened our coverage of classes using a Time Class case study to introduce several new features...
        We showed how to engineer a class to seperate its interface from implementation... We used a include guard to 
        prevent the code in the header file (.h) form being included mutiple times ion t he same source code (.cpp) file.

        We created formatted strings using ostringstream objects. we learned how to use the arrow opperator to access the 
        an object's members via a pointer of the object's class type.

        We learned that member functions have class scope-the member functions name is known only to the class's other 
        members unless feferred to by a client of trhe class via an object name, a referance to a object of the class,
        a pointer ro an object of the class or the scope resolution operator. We also discussed access functions(commonly
        used to retrieve trhe calues of data members or to test the truth or falsitry of conditions), and utility functions
        (private member functions that support the operation of the class's prubleic member functins)

        We also learned that a consturctor can specidfy default arguments that enable it to be called in a variety of ways,
        We also learned that any constructor can be called with no arguments is a default constructor and that there can
        be at most one default constructor per class.

        We discussed deconstructors for preformaing terminatiopn house kkeeping on an object of a class before that object
        is destroyed, and demonstrated the orfdder in which an objects constructors and deconstructors are called.


        We demonstrated the problaems that can occur when a member fucntion returns a referance or a pointer to a 
        private data member, which breaks the encapsulation of the class. We aslo learned that objects of the same
        type can be assigned to one another usiing default member wise assignment (in chapter 10 well see how this 
        can cause errors when the objects contain pointer members)


        We learned how to specify const onjects and const data member functions to prevent modifications to objects
        thus enforcing the principal of least priveledge. You also learned that, through composition, a class can 
        have objects of other classes as members.We demonstrated how to declare and use friend functions. 

        We learned that this pointer is passed as an implicit argument to each of a class's non-static member functions
        allwing them to acces the correct object's data members and other non-static member fucntions. We used the this
        pointer explicitly to access the class members and to enable cascaded member function calls... We motivated the
        notion of static data members and member functions and demonstreated how to declare and use them.

        In chapter 10 We constinue the study of classes and objects by showing how to enable C++'s operattotrs to work 
        witch class-type objects -- a function called Operator Overloading. 

        For example you'll see how to overload the << operator so it can be used to output a complete array without 
        explicitly using an itteration statement. 




               
*/