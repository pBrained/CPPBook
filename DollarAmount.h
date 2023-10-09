//DollarAmmount Class stores dollar ammounts as a whole number of pennies
#include <string>
#include <cmath>

class DollarAmount{
    public:
        //Constrict an object with input amount of value. 
        explicit DollarAmount(int64_t value) : amount{value}{ }


        //add rights amount to is objects amount.
        void add(DollarAmount right){
            amount+= right.amount;
        }

        //subtract rights amount from this amount.
        void subtract(DollarAmount right){
            amount -= right.amount;
        }

        //use interger arithmatic to calculate interest amount
        void addInterest(int rate, int divisor){
            DollarAmount interest{
                (amount * rate + divisor / 2) / divisor 
            };


        add(interest); // Add interest to this objects amount
        }

        // Print out the values with our own to string method.
        std::string toString() const{
            std::string dollars{std::to_string(amount / 100)}; //10099 penies / 100 == 100 Dollars
            std::string cents{std::to_string(amount % 100)};   //10099 penies % 100 == 99
            return dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
        }
    private:
        int64_t amount{0};//Dollar Ammount in pennies

};