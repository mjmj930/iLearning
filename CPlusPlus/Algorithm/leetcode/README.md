### https://github.com/doocs/leetcode/tree/main

### [239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/)

给你一个整数数组 `nums`，有一个大小为 `k` 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 `k` 个数字。滑动窗口每次只向右移动一位。

返回  *滑动窗口中的最大值 * 。

**示例 1：**

<pre><b>输入：</b>nums = [1,3,-1,-3,5,3,6,7], k = 3
<b>输出：</b>[3,3,5,5,6,7]
<b>解释：</b>
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       <strong>3</strong>
 1 [3  -1  -3] 5  3  6  7       <strong>3</strong>
 1  3 [-1  -3  5] 3  6  7      <strong> 5</strong>
 1  3  -1 [-3  5  3] 6  7       <strong>5</strong>
 1  3  -1  -3 [5  3  6] 7       <strong>6</strong>
 1  3  -1  -3  5 [3  6  7]      <strong>7</strong>
</pre>

**示例 2：**

<pre><b>输入：</b>nums = [1], k = 1
<b>输出：</b>[1]
</pre>

**提示：**

* `1 <= nums.length <= 10<sup>5</sup>`
* `-10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>`
* `1 <= k <= nums.length`

---

```cpp
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
```
