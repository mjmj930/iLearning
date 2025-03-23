#include<iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    // 初始化构造函数
    Rectangle(double l, double w): length(l), width(w){}

    double getArea(){
        return length * width;
        
    };
};



int main(){
    Rectangle rect(12.25, 5.5);
    std::cout << rect.getArea() << std::endl;
    return 0;
}