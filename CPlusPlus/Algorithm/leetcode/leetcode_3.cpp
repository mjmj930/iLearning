#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int lengthOfLongestSubstring(std::string s) {
    std::vector<int> last_pos(128,-1);
    int max_len = 0;
    int left = 0;

    for (int right=0; right < s.size(); ++right) {
        char c = s[right];
        if(last_pos[c] != -1 && last_pos[c] >= left) {
            left = last_pos[c] + 1;
        }

        last_pos[c] = right;
        max_len = std::max(max_len, right - left + 1);
    }
    return max_len;
}


// 测试函数
void testLengthOfLongestSubstring(const std::string& s, int expected) {
    int result = lengthOfLongestSubstring(s);
    if (result == expected) {
        std::cout << "test success: input stirng \"" << s << "\", \n expect reslut: " << expected << ", \n actual resl: " << result << std::endl;
    } else {
        std::cout << "test fail: input stirng \"" << s << "\", \n expect reslut: " << expected << ", \n actual resl: " << result << std::endl;
    }
}

int main() {
    // 正常情况
    testLengthOfLongestSubstring("abcabcbb", 3);
    // testLengthOfLongestSubstring("bbbbb", 1);
    // testLengthOfLongestSubstring("pwwkew", 3);

    // // 边界情况
    // testLengthOfLongestSubstring("", 0);
    // testLengthOfLongestSubstring("a", 1);

    // // 特殊情况
    // testLengthOfLongestSubstring("abcdefg", 7);
    // testLengthOfLongestSubstring("abba", 2);

    return 0;
}