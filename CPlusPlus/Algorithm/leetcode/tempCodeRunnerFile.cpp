#include <iostream>
#include <vector>

int main() {
    // 创建一个空的 vector
    std::vector<int> vec;

    // 向 vector 中添加元素
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // 访问 vector 中的元素
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 修改 vector 中的元素
    vec[1] = 10;

    // 再次输出 vector 中的元素
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}