#include <iostream>

void ptrInit() {

    int num = 10;
    int* ptr = &num;  // 声明并初始化指针，ptr 指向 num 的地址

    std::cout << "num value: " << num << std::endl;
    std::cout << "num address: " << &num << std::endl;
    std::cout << "ptr Storage address: " << ptr << std::endl;
    std::cout << "ptr Points to the value: " << *ptr << std::endl;  // 使用解引用运算符 * 获取指针指向的值
    std::cout << " Initialization Pointer \n\n"  << std::endl;
};

void ptrArithmetic() {
    int arr[5] = {1,2,3,4,5};
    int *ptr = arr;
    std::cout << "ptr Points value: " << ptr ;
    std::cout << "ptr Points to the value: " << *ptr << std::endl;
    ptr = ptr + 2;  // 指针向后移动 2 个整数的位置
    std::cout << "moved 2, ptr Points value: " << ptr << std::endl;
    std::cout << "moved 2, ptr Points to the value: " << *ptr << std::endl;
    std::cout << " Arithmetic Pointer \n\n"  << std::endl;
};

int main() {
    ptrInit();
    ptrArithmetic();
    return 0;
}