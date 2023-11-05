#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1{"happy"};
    string s2{"Birthday"};
    string s3;

    cout << "s1 is \"" << s1 << "\"; s2 is \"" << s2 << "\"; s3 is \"" << s3 << '\"'
         << "\"; s3 is \"" << s3 << '\"'
         << "The results of comparing s2 and s1 " << boolalpha
        << "\ns2 == s1 yeilds " << (s2 == s1)
        << "\ns2 != s1 yeilds " << (s2 != s1)
        << "\ns2 > s1 yeilds " << (s2 > s1)
        << "\ns2 < s1 yeilds " << (s2 < s1)
        << "\ns2 <= s1 yeilds " << (s2 <= s1)
        << "\ns2 >= s1 yeilds " << (s2 >= s1);

    cout << "\n\nTesting s3.empty():\n";

    if(s3.empty()) {
        cout << "s3 is empty assinging s1 to s3;\n";
        s3 = s1; // assign s1 to s3
        cout << "s3 is \"" << s3 << "\"";        
    }        
    // Testing string concatenitation with a C String.
    cout << "\n\n s1 += \" to you \" yeilds ";
    s1 += "to you";
    cout << "s1 = " << s1;
      
    // Test overloaded string concatination opperator
    cout << "\n\ns1 += s2 yeilds s1 = ";
    s1 += s2; 
    cout << s1;

    // Teststring concatenation with the c++14 string object literal;
    cout << "\n\ns1 += \", have a great day!\" yeilds\n";
    s1 += ", have a great day!"s;   // Have to put the s for string object literal
    cout << "s1  = " << s1 << "\n\n";

    // test string member function substring
    cout << "The substring of s1 starting at the location 0 for \n"
    << "14 characters , s1.substring(0,14), is:\n" 
    << s1.substr(0,14) << "\n\n";
    
    //Test substring to end of string function...

    cout << "the substring of s1 starting at\n" << s1.substr(15) << "\n";

    // Test the copy constructor
    string s4{s1};
    cout << "\n s4 = " << s4 << "\n\n\"";

    //Test overloades copy assingment opperator with the (=) self assignment opperator
    cout << "assingning s1 to s4";
    s1 = s4;
    cout << "s4 = " << s4 << "\n\n";

    //Test using the overloladed subscriptoperator to create lvalue;
    s1[0]= 'H';
    s2[6]= 'B';
    cout << "\n\ns1 after s1[0] = H and s1[6] ='B' is :\n" << s1 << "\n\n";


    try {
        cout << "Attempt to assign 'd to s1.at(100) yeailds: \n";
        s1.at(100) = 'd';
    }
    catch (out_of_range& ex) {
        cout << "An exception coccured" << ex.what() << endl;
    }
}

// In the third last box 4 sentences
// 