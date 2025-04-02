#include<iostream>
#include<string>
#include<stack>

class Solution {
    public:
        bool isValid(std::string s) {
            std::stack<char> st;
            for(char c : s) {
                if(c == '(' || c == '{' || c == '[') {
                    st.push(c);
                } else {
                    if(st.empty()) {
                        return  false;
                    }
                    char top = st.top();
                    // std::cout << st.top() <<std::endl;
                    st.pop();
                    if((c == ')' && top != '(') ||
                       (c == '}' && top != '{') ||
                       (c == ']' && top != '[')) {
                        return false;
                    }
                }
            }
            return st.empty();
        }
    };

int CheckValid(bool b) {
    if (b) {
        std::cout << "The string contains valid parentheses." << std::endl;
    } else {
        std::cout << "The string does not contain valid parentheses." << std::endl;
    }
    return 0;
}

int main() {
        Solution sol;
        std::string test = "{[()]}";
        CheckValid(sol.isValid(test));
        return 0;
}    