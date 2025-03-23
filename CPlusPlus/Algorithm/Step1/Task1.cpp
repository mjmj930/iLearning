#include<iostream>
#include<windows.h>

using namespace std;

int main() // 主函数入口
{
    SetConsoleOutputCP(CP_UTF8);
    double radius;
    std::cout << "请输入圆的半径：";
    cin >> radius;

    float pi = 3.14159;
    double perimeter = 2 * pi * radius;
    double area = pi * radius * radius; 
    
    cout << "周长为：" << perimeter << endl;
    cout << "面积为："<< area << endl;

}