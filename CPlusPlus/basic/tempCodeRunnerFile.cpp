#include<iostream>
#include<vector>



int main() {
    std::vector<int> vec = {2,4,6,8};

    std::cout << "Vectotr Element: ";
    for (auto it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    vec.insert(vec.begin() + 2,5);

    std::cout << "Vectotr Element: ";
    for (auto it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    vec.pop_back();

    std::cout << "Vectotr Element: ";
    for (auto it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}