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

        






*/