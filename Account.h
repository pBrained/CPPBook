#include <string>

class Account{
public:
    // public is a Access Specifier 
    // Defining an Constuctor, Normally constructios are Public
    // Initializeing the constructor when called / constructed.
    //
    //
    //     v(State Parameters that must be passed int to initialize)
    Account(std::string accountName, int initialBalance) 
        : name{accountName}{ // < this is members initializer list used to give values to initializer / constructor. 


         // Construction Code
        if(initialBalance > 0){
            balance = initialBalance;
        }
    }
    /* Default Constructor
    If we dont declare Constructor ex "Account myAccount;"
    create an aboject without placing braces to the right of the object 
    vaitables name we will call classes default constructor ans it does 
    not initiaalize the classes fundimeatal typpe but does call the 
    default constructor for each data member thats an object of another 
    class. 

    So the default constructor assigns garbage values using the 
    default constructors from datamembers types. 
    
    */   
    void deposit(int depositAmmount){
        if(depositAmmount > 0){
            balance = balance + depositAmmount;
        }
    }
    
    int getBalance() const {
        return balance; 
    }
    
    void setname(std::string accountName){
        name = accountName;
    }
    
    std::string getName() const{ //indicates the string should be returned by value, const std::string& getName const{} indicates return by reference constant that cant be modified
        return name;
    }

    std::string getAlias() const{
        return alias;
    }
    
    private:
    // private is also an acess specifier these are valuabe and accesed with get and set function. 
    std::string name;
    std::string alias = "Musa";
    int balance{0};
    
};                           