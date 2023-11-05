#include    <iostream>

#ifdef DEBUG

int main(){
    std::cout << "Debug is defined";
    return 0;

}

#else

int main(){
    std::cout << "Debug is not defined";
    return 0;
}   

#endif
