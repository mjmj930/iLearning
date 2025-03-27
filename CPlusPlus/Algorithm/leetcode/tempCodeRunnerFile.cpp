#include <iostream>
#include <vector>
#include <stack>

int main() {

    std::stack<char> st;
    st.push('a');
    st.push('b');
    st.push('c'); 
    std::cout << st.top() << std::endl;
    st.pop();
    std::cout << st.top() << std::endl;
    
    std::cout << st.empty() << std::endl;
    st.pop();
    st.pop();
    std::cout << st.empty() << std::endl;
    return 0;
}