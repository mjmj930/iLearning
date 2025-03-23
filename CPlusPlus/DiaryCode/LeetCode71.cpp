#include<iostream>
#include<sstream>
#include<stack>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string component;

        // 按 / 分割路径 遇到 / 时跳过
        while (getline(ss, component, '/' )) {
            if (component.empty() || component == "." ) {
                continue;
            } else if ( component == ".." ) {
                if(!st.empty()){
                    st.pop();
                }
            } else {
                st.push(component);
            }
        }

        // 构建简化后的路径
        string simplifiedPath;
        vector<string> components;
        while(!st.empty()) {
            // 将栈中的字符一次取出
            components.push_back(st.top());
            st.pop();
        }
        // 逆序将最短路径生成
        for (auto it = components.rbegin(); it != components.rend(); ++it) {
            simplifiedPath += "/" + *it;
        }
        // 最后判断是否为空 空返回根路径，不是则返回最短路径
        return simplifiedPath.empty() ? "/" : simplifiedPath;
    };
};