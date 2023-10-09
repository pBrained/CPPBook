#include <iostream>  // Enables program to output data to the screen
#include <string>    // Added in Chapter 3
#include "Account.h" // Also added in CH 3

    using namespace std;

int main(){
    Account account1{"Preston C", 200};
    Account account2{"Mary M", 40};

    cout << "\n Account name is: " << account1.getName() << "\n Account Balance is: $" << account1.getBalance();
    cout << "\n Account name is: " << account2.getName() << "\n Account Balance is: $" << account2.getBalance();

    // Deposit into Account 1
    cout << "\n Enter the Deposit into Acnt 1\n";
    int depositAmmount{0};
    cin >> depositAmmount;
    cout << " Adding $" << depositAmmount << "...";
    account1.deposit(depositAmmount);
    // Display Ammount in Acount 1 
    cout << "\n" << account1.getName() << " now has $" << account1.getBalance();

    // Deposit into Account 2
    cout << "\n Enter the Deposit into Acnt 2\n";
    cin >> depositAmmount;
    cout << " Adding $" << depositAmmount << "...";
    account2.deposit(depositAmmount);
    // Display Ammount in Acount 2
    cout << "\n" << account2.getName() << " now has $" << account2.getBalance();
    cout << "\n Good job " << account1.getAlias();
}

//------------------------------Summary Notes---------------------------
// Each Class you create becomes a new type you can use to declare variables
// and create objects
// C++ is extensable because you can create class types as needed
// Typically you cannot call member function of a class untile objects of class is created
// Types you create are known as "User-defined types".
// New classes when packaged properly can be used by other programmers.
// In an #include directive user defined headers are placed in ""'s
// To call a member function you uses whats known as the "dot" operrator ".".
// MemberFunctions can take arguments.
// The default value for string is empty string.
// Class must be declared with class, and must be terminated with a semicollon
// Each object of a class has its own copy of the Data Members
// Data members are declared in thecalss definition but outside its member function
// Keyword Public and private are acces sppecifiers.
// Return Types are displayed right nest tot eh functiuons name
// Paramerters are declasred in the paramter list and they specify
// aditionsal information needed for functiontrs to complete task/
// Multipile parameters in a function are seperated by a comma.
// Variables declared in a particular functions body are local variables 
// A memeber function theat does not and should no modify the object 
// on which its called are declared with const
// Declarig data memberspirvate are known as datahiding. 
// UML are Unified Modeling Language Diagrams
// When a function reaches it's curly braces it returns to it's caller.
// You can initialize fundamental-type data members in their declarations.
// A constructor can preform validation of valdity checking before modifying a Data Memeber.
// Set Functions can be programmed to validate their arguments and reject any attempts to set the data to bad values. 
// A Client of a class is any other code that calls the class members functions.
// Client code can see public Data Members and do whatever with them. 
// A get function can present data to a client data in a diferent form.

// << Stream insertion and extration operator




/* 
---------------------------------Chapter's 1 - 2----------------------------

int main(){
    int number1{0}
    int number2{0};
    std::cout << "First number to compare\n";
    std::cin >> number1;

    std::cout << "Second Number to compare\n";
    std::cin >> number2;

    if(number1 == number2){
        std::cout << number1 << "==" << number2 << std::endl;
    }
    if(number1 >= number2){
        std::cout << number1 << ">=" << number2 << std::endl;
    }
    if(number1 <= number2){
        std::cout << number1 << "<=" << number2 << std::endl;
    }
    if(number1 < number2){
        std::cout << number1 << "<" << number2 << std::endl;
    }
    if(number1 > number2){
        std::cout << number1 << ">" << number2 << std::endl;
    }
    if(number1 != number2){
        std::cout << number1 << "!=" << number2 << std::endl;
    } 
    return 0;
}
*/