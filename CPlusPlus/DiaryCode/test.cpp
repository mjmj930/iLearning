#include <iostream>
#include <string>

// 定义一个简单的类
class MyClass {
public:
    int num;  // 成员变量
    std::string str;
    void printNum() {  // 成员函数
        std::cout << "The number is: " << num << std::endl;
    }
};

int main() {
    MyClass obj;
    obj.num = 10;  // 给对象的成员变量赋值
    obj.str = "str";

    MyClass* ptr = &obj;  // 定义一个指向 obj 的指针

    // 不使用 -> 运算符，通过解引用和 . 运算符访问成员变量
    std::cout << (*ptr).num << std::endl;
    std::cout << (*ptr).str << std::endl;

    // 不使用 -> 运算符，通过解引用和 . 运算符调用成员函数
    (*ptr).printNum();

    std::cout << ptr->num << std::endl;
    std::cout << ptr->str << std::endl;

    return 0;
}