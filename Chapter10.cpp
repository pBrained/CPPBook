/*
Chapter 10 Operator Overloading!!!!!!

        One example of a overloaded operator is the << 
    
        The << is used for stream insertion and also used for the bitwise left shift opperator 
        (which is discussed in chapter 22).

        Similarly the >> is overloaded becasue it not only is the stream extraction operator but,
        >> also is the bitwise-right-shift operator defined as part of the C++ language.

    
    We've been using Overloaded Operators since the beginning of the book actually...
        Various overloads are built into the base C++ language itself. For example....

            The addition operator (+) is overloaded 
            The subtraction operator (-) is overloaded
        
        + Meaning that they act differently depending on the context in interger, floating point, and pointer
        arithmatic on with the fundimental data types.

        You can overlaod most operators to be used with class objects 
        - the compiler generates the appropriate code based on the type of opperands.

        So by overloading the string opperand we can create phone numbers...

        and in a example we overloade the increment and decremend operatorswehn using them with the Date class to 
        allow a program to add or subtract the ammount of days specified on the right side of the operator.



    Now...
        We enter into a case study...

        An array class that uses overloaded opperators and other capabilities to solve various problems with pointer
        based arrays. This is one othe the most important case studies in the book...

        As part of this class well overload the stream insertion stream extraction, assignment, equality and ralational
        subscript opperators. Once you master this Array class youll indeed understand the essence of cursed energy (jjk)
        object technology-- crafing using and reusing valuable classes...

        See CH10Overloading Folder. 

        s1 is initlaized with the literal "happy"
        s2 is intialized with the literal" birthday and 
        s3 uses the default string onstructor to create a empty string. 



        In this program we use many different types of operations on the opperators that are oveloaded and
        one of the things that we use is the 
        copy constructor - which copys the contsnts of s21 into the the new object s4, 
        string object literal
        string memberfinction substr to return a string containing a protion of another string.
        Also we use the overloaded [] operator withing the string class to update
        the values of the strings at the indexes it is similar to using the at function which
        throws an excption if the argument is incalid subscript
        if the subscript is valid function returns the character at the speciufied location as a
        modifiable lvalue  or a non modifyable l value if its a const referance 
        If its called a non const string object ofthe function returns a modifyable l value
        which could be used on the left side of the  (=) assignemtn opperator to assign a new 
        value to the lcoation in the string

        If at is claled on a const string object , the function returns a non modigyable lvalue
        that can be used to obtain but not modify the value at that location of the string so i
        really works more in the way of a referance.

    Fundamentals of Operator Overloading
        You can ouse operators with your won user defined types now!

        Th e assignment operator (=) may be used with most classes to perform memberwise
        assignment of the data members 

        each data member assigned form the assingments "source" on the right to the 
        "target" object on the left. Memberwise assignment is dangerous for clases with
        pointer members, so we'll explicitly overload the assignment opperator for such classes. [Note:
        This is also true for the C++11 Move assignment oppertor which we discuss in chapter 24]

        The adress (&) operator returns a pointer to the obkect; this opperator also can be 
        overloaded.

        The comma opperator evalueates the expression to its left the the expression to its tight and returns the 
        latter xpression. this opperator also can be overloaded.

        Most fo C++'s operators can be overloaded. 

        the only opperators that cannot be overloaded are the
         
        . operator the :: operator and the .* (pointer to member operator) and the ternary opperator (:?)

        period opperator 
        scoper resolution operator
        the pointer to member operator 
        ternary operator are not interactable

        An operator's presedence cannot be changed by overloading. 

        An opperators associativity cannot be change by oveloading
        and operator s "arity" canno t be changed by overloading ...
        Overloaded uniary operators remain uniary opperators (+, -, &, *) have both uniary and binary versions
        Only existing opperators can be overloaded-- you cannot create new ones,
        related opperators like + and += must be overloaded seprately.
        When overloading (),[],-> or any of the assingment opperators the operator overloading function 
        must be declared as a class membeer For all other opperator overloading functions can be member functions
        or non member functions. 

        A binary operator can be overloaded as a nonstatic member function with one paramerter or as a non member
        untion with two parameters. (one of those parameters must be either a class object or a reference to a 
        class object)

        A non membter operator function oftern is declared as a friend of a class for preformance reasons.

        Consider using the < operator to comare two objects of the string class that you define. When overloading 
        the binary operator <  as a non-static member functionm if y and z are string class objects then y < z is 
        treated as the comuler as if y.operator<(z) is written 

        incling the operator < meamember function eith the one argmuent declared below:

        class String {
            public:
                bool operator<(const String&, const String&);
                ...
        }

        overloader operator functions for binay operators can be member function only when the left operand is a object 
        of the class in which the function is a member..


        A non member function binary oerato < must take two arguments - one of whih must be an object (or a refernace to
        an object) of the class that the overloaded opperator is associated with. If y and z are string class objects or 
        references to stinf class objects then y < z is trated as if the call operator<(y,z) had been written int he ptogram
        invoking the fucntion operator <,which is declared as follows bool opperator<(const String&, const String&)

        You can input and output the fudimental fundimantal-type data using the stream extraction operator >> and the stream 
        insertion opperator <<, respectivily. The C++ class libraries overload these binary operators for each functimental
        type, including pointers and charcter * strings (char* string's ).


        You can also overload these operators to preforme input and output on your onw types. 


~!!!! Although its possible to overload the &&, &, (,), and || operators one should avoid doing so to avlod subtle errors !!!1!
    SEE THE CERT GUIDELINE DCL10-CPP 




        See the CH10 StrOverload Folder for the example.

    
    We use the istream opperator to overload the insertion opperaror within our class and the 
    o stream operator to overload the excertion operator within out class and allow them to modify
    the class in a different way. 

    When we use the I stream operator in this context we also use its ignore function to ignore the ()- and anything else in t
    the phone numbers we take in and then format with the istream operator and output with the output operator 

    Overloading unary operators.

    A uniary operator for a class can be overloaded as a non-static member functiopn with no argmuents aor as 
    a non member function with one argumen that must be an object (or a referance to an object)


    operators must be non-static to acces the non-static data in each object of the class.

    Consider overloading the unary operator to test whether an objcet of your own sting cass is empty.
    
    Such a function would return a bool result. 

    When a unary operator such as ! is overloaded as a member function with no arguments and the compiler sees the 
    expression!s (in which s is an object of clas string), the compiler generated the function cal s.operator!()
    The operand s is the string object for thwhich the sting cass member function operartor! is being invoked
    such as follows

    class String{
        public:
            bool operator!() const;
    }
    
    bool operator!(const String&)       

    

    Overloading the incelment and Decrement operatrors


    To ovrload the prefix 


    Unary Operarator ass Non-MemberFunctions ]]
    
    To overload the prefix and post fix decremnt and incremnt operator the function must have 
    a unique signinture so the compiler knowsexactly which operation is intecndended.. which version of ++ is written inbookn


    Over loading the Prefix Operator...
        When the copiler sees the preincrementinf exrpession of ++d1, if the overloaded operator is defined as a member function, 
        the comopiler generates the member function call
        ++d1 turns into or is the same or is seen as d1.operator++()
        the prototype foth this operator would be Date&operator++();

        If the prefix increment operator is implemented as a non member funciton, then, ehrn the compiler sees the expression
    ++d1  the compiler gernerates the fnction call or sees this same as operator++(d1)
        the proto type for this non member function is Date& operator++(Date&);


        overloadin the PostFix Incrememnt operator

        d1.operator++(0)

        The 0 is a pparently strctly a dummy value that the enables the compuler to distinguish between postfi and prefix increment operator functions
        Date operatr ++(int)

        operator ++ (d1, 0)

    The prototype fot this function would be Date operato++(Date&, int);


        Date study class

    
    */