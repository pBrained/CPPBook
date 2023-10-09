/* 
When solving a problem, you should have a thorough understanding of the
problem and have a carefully planned apporach to solving it.

When writing a Program, you should understand the available building blocks
and employ proven program construction techniques.
*/
// PseudoCode
// Any computing problem can be solved by executing a series of actions
// In a specific order. So all we need to do is find the Action and Timing

// C++ was built to be Sequential & Structured Programming 
 /*
 -----------------------------------------------------------
            Statements In C++ "How we code C++"
 -----------------------------------------------------------
    C++ Has 3 Control Statements: 
    "Selection Statements", "Itteration Statements", "Sequence Statement"
    
    C++ Has 3 Selections Statements:    
    "If", "Else", "Switch"

    C++ Has 4 Itteration Statments:    
    "While", "Do While",
    "For", "Range Based For"

    Sequence Statement:
    "Statements executed in order, one oafter the next."

    Single entry and single exit control statments make it easy to build 
    programs

    We can only stack or nest control statements
    Decision Simble "Diamond"     

------------------------------"Random Fact"-------------------------
If you dont put brackets after a while loop it will execute only one line
under it.
------------------------------------------------------------------------

---------------------Ternary Operator ----------------------------
            (Operand number 1 )   (Op2)      (Op3)
    cout << (student grade >= 60 ? "Passed" : "Failed")
                        one Opperand        
            if   Student Grade >= 60 return passed or failed


    While loops can be represented with a merge statement in UML
    Because they take a values and merge them while a loop happens and if the condition
    of the whole loop is true then when its not the merge moves on loop completes breaks ends etc.

    Merge joins two flows of activity into one, checking if then and modifying a value


    Deviding intergers reuts in "Iterger devision" where results re truncated, decimal points are lost.
    

    we sholud use range checking when taking input's



------------------Sentinel Values --------------------------
    A.K.A signal value, dummy value, or flag value. 

    In sentinal conrolled loops prompts should remind user of the sentinel


    "Used to indicate the end of a data entry."

    Sentinel-controlled itteration or indefinite itteration is when
    the ammount of itterations needed are not known beforehand.

    we can pass sentinel values into signify the end of a datastream so they can be of the
    data type but not of the logic.

    Example:
    Grades [100,90,89,97,100,-1]  the negitive one is a sentinel value 
    telling us this is the end of the data. 

----------------Programming Technique -----------------------------------    

            "Top Down, Stepwise Refinement"
                    ~Psuedocode~
----------------------------------------------------------------------------
                        "Top"

1"Determine the class Average for the quiz"....

---------------------------------------------------------------------------
                    "First Refinement"
1"Initialize variables"
2"Input, sum, and average the class grades"
3"Calculate and print out the class average"

---------------------------------------------------------------------------
                    "Second Refinement"
1 Initialize total to zeros
  Initialize the counter to zero

2 Prompot the user to enter tyhe fist grade
  Input the first grade(possible the sentinel)
  While the user has not yet entered the sentinel
    Add this grade to the running total
    Add one to the grade counter
    Proimpt the user to enter the next grse
    Input the next grade(Possibly the sentinel)
3 If the counter is not equal to zero
    Set the average to the total devided by the counter. 
    Print the average
  Else
    Print "No grades erer entered"


"Remeber when doing division "/" or remainder "%" calculations in which the 
right opperand is zero the result is undefined so make sure to test 
and handle this" (e.g., display an error message)

---------------------------------------------------------------------------


----------------------------------------------------------------------------
                            "Type Conversions"
                            

"Explicit Conversion"                  i      /    y     =  double
double average{static_cast<double>(intergeri) / intergery};
                                               /
"Implicit Conversion" - Promotion             / 
C++ promotes int operands to double vales... / 
"intergery" is copied by C++ and the copy is "promoted to a double" by C++
then C++ prefoms the division...



---------------------------------------------------------------------------
                              "Cast Operators"
Cast operators are available for use with every fundimantal type and with
class types aswell.
--------------------------------------------------------------------------
The operator is formed by the keyword "static_cast" with a type name 
in angle brackets "<>"

Its a unary operator that is it has only one operand

--------------------------------------------------------------------------
                            "SetPrecision()"
setprecision() is a Parameterized stream manipulation because it requires a
argument to complete a task. 

Programs that use these calls must includse a header <iomanip>

the manipulator "endl" is a nonparameterized stream manipulator, becasue it
does not require a paramter

cout <<setprecision(2) << fixed;
prints 88.00 instead of 88

This prints in "Floating point notation", specified by the fixed stream 
manipulator. When the stream manipulators fized and set precision are used
the printed value is rounded to the number of decimal positions indicated by
setprecisions argument "(2)". Allthough the value in memory remains unaltered.

It is also possible to force a decimal point to appear by using the stream 
manipulator showpoint().

If "showpoint()" is specified without fixed, then trailing zeros will NOT print. 
Like endl the showpoint() and fixed manipulator's need the header <iostream>

--------------------------------Incremend and Decrement---------------------
int c = 5;
cout << c << c<< endl; 5
cout << c << c++<< endl; 5 postfix
cout << c << c<< endl; 6  

c = 5;
cout << c << c<< endl; 5
cout << c << ++c<< endl; 6 prefix
cout << c << c<< endl; 6

--------------------------Operator Presidence and associtivity------------------
operator. Associtivy, Type

:: (), left to right, primary

++ --, left to right, postfix

++ -- static_cast<type>(), left to right

++ -- + -, right to left, unary(prefix)

* / %, left to right, mutiplicative

+ -, left to right, additive

<< >>,left to right, insertion/extraction

< <= > == >, left to right, relational

== !=, left to right, equality

?:, right to left, conditional

= += -= *= /= %=, right to left, assignment

-------------------------------------------------------------------------------------

                                        CHAPTER 5

-------------------------------------------------------------------------------------

Rember we can use for loops to itterate over a number pattern.
{0,2,4,6,8,10} == i += 2;
{99,88,77,66,55,44,33,22,11} = i -= 11;

Case study of doubles vs flots reveal that there is a representation error because 
computers can only have so much space to stoe an it ut because we can cast a double
double or so to store the int value we will do so to be more percise in our calculations 
however we must not forget thtat at swomepoint we will run into errors with tteh spare
values effecting the answer we can never be exactly precise. We can find alot of errors 
and security issuses here as numbers being devided into .3333333 infinte values will
allways need to be taken care of. " You've been warned!"

we also keep in mind that values when modified by the set precision methods dont change
they only appear rounded the value on memory still has its float point numbers.

double is also trouble. we just have to increase the size of the double to keep infinity
at bay>>??? this causes me to question the code that runs our financial systems.

---------------------------------------------------------------------------------


A person invests 1,000 in a savings account yeilding 5% interest. Assuming that all 
the interest is left on depost, calculate and print the amount of money in the
account at the end of each year for 10 years. Use the following formula to determine
the ammounts:

A = P(1+R)^N    // P is the original ammount invested
                // R is the anual interest rate(eq use 0.05 for 5%)
                // N is the number of years
                // A is the ammount on deposit at the end ot the nth year.
                // The one is to Properly recive the correct value of the pervent

    <exp>   //Parse Tree 
    / | \               -         
   A  = <exp>           -
        / | \           -
       P  * <exp>       -    
            / | \       -
       1 + R  * <exp>   -
                / | \   -
                1 + R   -
_____________________________________________________________________________________

int stores -2.14 Billion to +2.14 Billion
long long stores -92 Quadrillion to +92 Quadrillion

But this varies form platform to platform sometimes so 
C++ 11 made one that does not called 

int64_t stores -92 Quadrillion to +92 Quadrillion allways. 

new interger types at <cstdint>
 */









/*
#include <iostream>
#include <iomanip>
#include <string>
#include "DollarAmount.h"
using namespace std;

int main() {
    DollarAmount d1{12345}; // $300.99
    DollarAmount d2{1576}; // $700.99

    cout << "After adding d2("<< d2.toString() << ") to d1 (" << d1.toString() << ").\n d1 = ";
    d1.add(d2);
    cout << d1.toString() << "\n";
    

    cout << "After subtracting d2 (" << d2.toString() << ") from d1 (" <<d1.toString() << ").\nd1 =";
    d1.subtract(d2);
    cout << d1.toString() << "\n";

    cout << "After subtracting d1 (" << d1.toString() << ") from d2" << d2.toString() << ").\n d2 = ";
    d2.subtract(d1);
    cout << d2.toString() << "\n\n";

    cout << "Enter interger interest rate and divisor. For example:\n"
      << "for  2.%, enter: 2 100\n"
      << "for 2.3%, enter: 23 1000\n"
      << "for 2.37, enter: 237 10000\n"
      << "for 2.375, enter: 2375 100000\n> ";
    int rate;
    int divisor;
    cin >> rate >> divisor; 

    DollarAmount balance{2850000}; // Initial prinicipal amount in pennies. 
    cout << "\n Initial balance: " << balance.toString() << endl;
    
    // Display Headers
    cout  << "\n Year:" << setw(20) << "Ammount on deposit" << endl;

      // Calculate the amount on deposit for each of 10 years
      for(unsigned int year{1}; year <= 10; year++) {
        balance.addInterest(rate,divisor);
        cout << setw(4) << year << setw(20) << balance.toString() << endl; 
      }
}
*/


#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  int total{0};
  unsigned int  gradeCounter{0};  
  unsigned int  aCount{0};    
  unsigned int  bCount{0};
  unsigned int  cCount{0};
  unsigned int  dCount{0};
  unsigned int  fCount{0};

  cout << "Enter the interger grades in the range 0-100.\n"
    <<"Type the end of file indicator to terminate the input"
    <<"   On Unix/Linux/MacOS X type <Ctrl> d then press Enter\n"
    <<"   On Windows type <Ctrl> z then press Enter \n";
  int grade;

  while(cin >> grade){
    total += grade;
    ++gradeCounter;

    switch (grade / 10){
      case 9:   // 9 or ten statement execute.
      case 10: // Grade was between 90 and 100 inclusive
      ++aCount;
      break;
      break;
      case 8:
      ++bCount;
      break;
      case 7: // Each Case must contain a constant intergral expression/
      ++cCount;
      break;
      case 6:
      ++dCount;
      break;
      default:
        ++fCount;
        break;
    } // End of the Switch
  } // End of the while Loop
    cout << fixed << setprecision(2); 
    
    cout << "\n Grade Report: \n";

    if (gradeCounter != 0){
      double average = static_cast<double>(total) / gradeCounter;

      // Output Summary of results
      cout << "The total of the " << gradeCounter << "grades enterd is "
          << total << "\n Class average is " << average
          << "Number of students who recieved each grade:"
          << "\n A:" << aCount << "\n B:" << bCount << "\n C:" << cCount
          << "\n D:" << dCount << "\n F:" << fCount << endl;
    }
    else{ // No grades were enterd
    cout << "No grades were entered." << endl;
    }
}



//--------------------------------------------------------------------------------------

                          //Switch Statemenents

//--------------------------------------------------------------------------------------

//The switch statements compares expression calue with each case label and 
//The expresion must have a signed or unsigned data type. 

/*
             "C++ control statements are Single-Entry/ Single-Exit"

Only 3 statements are needed to create any algorithm

Sequence 
Selection
Itteratipm

Sequence is trivial just list statements to execute in order.

Selection:
if single selection
if else double selection
switch mutiple selsection


Itteration
While
do...while
for 
(for range)
"Everything that can be done in the for and do while can be done in the while loop, Although 
not neccesarilty as conviently though." - "C++ Tenth Edition"


So to simplify any form of controll ever needed in a C++ program can be expressed in the terms
of 

Sequence, if statement, while loops.    | Stacking and Nesting 
          (Selection) ,  (Itteration).  | are the only two ways
                                        | to combine these. 

-----------------------------------------------------------------------------------------------
                    Do While 

In a do while loop the body executes atleast once then the satement is evaluated 
to determine wheteher the do code block should be executed again. 



*/ 