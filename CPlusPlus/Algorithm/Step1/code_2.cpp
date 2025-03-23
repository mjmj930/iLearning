#include<iostream>

void countCalls(){
    static int count = 0;
    count++;
    std::cout << "This Functuon has been called:"<<count<<" times"<<std::endl;
}


int main(){
    for (int i=0 ; i<10; i++){
        countCalls();
    }
    return 0;
}