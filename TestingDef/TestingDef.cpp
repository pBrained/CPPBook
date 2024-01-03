#include    <iostream>

#ifdef DEBUG

int main(){
    std::cout << "Debug is defined";
    return 0;

}

#else

int main(){
    std::cout << "Debug is not defined";
    int x = 5;
    x = ++x + ++x;
    std::cout << x;
    return 0;
}   

#endif
