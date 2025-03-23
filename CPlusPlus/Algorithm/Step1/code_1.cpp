#include<iostream>

using namespace std;

void swapByValue(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void swapByRefs(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


void swapByPointers(int *a, int *b){
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a, b;
    cout << "input a: ";
    cin >> a;
    cout << "input b: ";
    cin >> b;

    std::cout << "Before swap by value: a = " << a << ", b = " << b << std::endl;
    swapByValue(a,b);
    cout << "After swap by value: a: " << a << ", b: " << b <<endl;

    std::cout << "Before swap by reference: a = " << a << ", b = " << b << std::endl;
    swapByRefs(a,b);
    cout << "After swap by reference: a: " << a << ", b: " << b <<endl;

    std::cout << "Before swap by Pointers: a = " << a << ", b = " << b << std::endl;
    swapByRefs(a,b);
    cout << "After swap by Pointers: a: " << a << ", b: " << b <<endl;
}