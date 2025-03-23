#include<iostream>
#include<sstream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        stack<string> st;
        string component;

        while(getline(ss,component,'/')) {
            if(component.empty() || component == ".") {
                continue;
            } else if (component == "..") {
                if(!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(component);
            }
        };

        // 构建简化后的路径
        string simplifiedPath;
        vector<string> components;
        while (!st.empty()) {
            components.push_back(st.top());
            st.pop();
        }
        for (auto it = components.rbegin(); it != components.rend(); ++it) {
            simplifiedPath +=  "/" + *it;
    }
        return simplifiedPath.empty() ?  "/" : simplifiedPath;
    };

};