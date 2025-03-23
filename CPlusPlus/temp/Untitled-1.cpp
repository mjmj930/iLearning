#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;  // 单调队列，存储元素的下标

        for (int i = 0; i < nums.size(); ++i) {
            // 移除队列中不在当前窗口内的元素
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // 移除队列中比当前元素小的元素
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // 将当前元素的下标加入队列
            dq.push_back(i);

            // 当窗口形成后，记录最大值
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

// 测试代码
int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = sol.maxSlidingWindow(nums, k);

    // 输出结果
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
