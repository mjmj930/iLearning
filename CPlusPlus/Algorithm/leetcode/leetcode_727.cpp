#include<iostream>
#include<string>
#include <cstring>

std::string minWindow(std::string S, std::string T) {
    int s_len = S.length();
    int t_len = T.length();
    int minLen = INT_MAX;
    int start = 0;

    for (int i=0; i<s_len; ++i) {
        int j = 0;
        // 尝试找到一个匹配的子序列
        while(i < s_len && j < t_len) {
            // i匹配j，如果相等，j++，继续匹配到T中的下一个字符 i匹配++j，
            // 不相等跳出，++i 匹配j知道找到匹配的j位字符
            if(S[i] == T[j]) {
                ++j;
            }
            ++i;
        }
        // 如果没有找到完整子序列，跳过后后序收缩步骤
        if(j < t_len) {
            break;
        }
        int end = s_len - 1;
        j = t_len - 1;
        while(j >= 0) {
            if(S[end] == T[j]) {
                j--;
            }
            end--;
        }
        ++end;
        if(s_len - end < minLen) {
            minLen = s_len - end;
            start = end;
        }
        i = end;
    }
    return minLen == INT_MAX ? "" : S.substr(start, minLen);
}


// 动态规划
class Solution {
    public:
        std::string minWindow(std::string s1, std::string s2) {
            int m = s1.size(), n = s2.size();
            int f[m + 1][n + 1];
            memset(f, 0, sizeof(f));
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (s1[i - 1] == s2[j - 1]) {
                        f[i][j] = j == 1 ? i : f[i - 1][j - 1];
                    } else {
                        f[i][j] = f[i - 1][j];
                    }
                }
            }
            int p = 0, k = m + 1;
            for (int i = 1; i <= m; ++i) {
                if (s1[i - 1] == s2[n - 1] && f[i][n]) {
                    int j = f[i][n] - 1;
                    if (i - j < k) {
                        k = i - j;
                        p = j;
                    }
                }
            }
            return k > m ? "" : s1.substr(p, k);
        }
};


int main() {
    // std::string S = "abcdebdde";
    // std::string T = "bde";
    std::string S = "aabcabscabcaabfswc";
    std::string T = "abc";
    std::cout << minWindow(S, T) << std::endl;

    Solution solu;
    std::cout << solu.minWindow(S, T) << std::endl;
    return 0;
}

// https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0727.Minimum%20Window%20Subsequence/README.md