#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    vector<string> vec = {"1-","2","3","4","5"};
    for(auto i : vec){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}