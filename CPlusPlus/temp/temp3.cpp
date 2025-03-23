#include <iostream>
#include <string>
#include <vector>
#include <climits>

int main() {
    std::string str = "Hello, World!";
    std::cout << "string length: " << str.length() << std::endl;
    std::cout << "string size: " << str.size() << std::endl;
    std::cout << "string : " << str[12] << std::endl;

    std::vector<int> vec = {1, 2, 3, 4, 5};
    // std::cout << "vector size: " << vec.size() << std::endl;
    // std::cout << "vector length: " << vec.length() << std::endl;
    // std::cout << "INT_MAX: " << INT_MAX << std::endl;
    return 0;
}