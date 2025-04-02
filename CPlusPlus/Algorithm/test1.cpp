#include<iostream>
#include<vector>
#include<algorithm>

void generatePermutations(int n) {
    std::vector<int> numbers;
    for(int i=1; i <= n; ++i) {
        numbers.push_back(i);
    }
    do {
        for (int element : numbers) {
            std::cout << element;
        }
        std::cout << std::endl;
    } while (std::next_permutation(numbers.begin(), numbers.end()));
}

int main() {
    int n;
    std::cout << "Input Integer n:";
    std::cin >> n;
    generatePermutations(n);

    return 0;
}