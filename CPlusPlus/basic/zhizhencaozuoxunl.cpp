#include <iostream>



int main() {
    int a = 5, b = 10;
    int* p = &a;
    std::cout << "  p: " << p <<std::endl;
    std::cout << " *p: " << *p <<std::endl;
    int* q = &b;
    std::cout << "  q: " << q <<std::endl;
    std::cout << " *q: " << *q <<std::endl;
    *p = *q + 3;
    std::cout << " *p: " << *p <<std::endl;
    p = q;
    std::cout << "  p: " << p <<std::endl;
    std::cout << " *p: " << *p <<std::endl;
    int& ref = *p;

    std::cout << "int& ref = *p -> ref: " << ref <<std::endl;

    ref = 200;
    std::cout << "ref = 200 -> ref: " << ref <<std::endl;
    std::cout << "  q: " << q <<std::endl;
    std::cout << " *q: " << *q <<std::endl;
    std::cout << "  p: " << p <<std::endl;
    std::cout << " *p: " << *p <<std::endl;
}


