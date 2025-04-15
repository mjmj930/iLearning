### [1. 两数之和](https://leetcode.cn/problems/two-sum/)

给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值 ***`target`*  的那 **两个** 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。

**示例 1：**

<pre><strong>输入：</strong>nums = [2,7,11,15], target = 9
<strong>输出：</strong>[0,1]
<strong>解释：</strong>因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
</pre>

**示例 2：**

<pre><strong>输入：</strong>nums = [3,2,4], target = 6
<strong>输出：</strong>[1,2]
</pre>

**示例 3：**

<pre><strong>输入：</strong>nums = [3,3], target = 6
<strong>输出：</strong>[0,1]
</pre>

**提示：**

* `2 <= nums.length <= 10<sup>4</sup>`
* `-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup>`
* `-10<sup>9</sup> <= target <= 10<sup>9</sup>`
* **只会存在一个有效答案**

```cpp
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<std::pair<int, int>> numsWithIndex;
        for (int i = 0; i < nums.size(); ++i) {
            numsWithIndex.push_back({nums[i], i});
        }

        // 按数值排序
        std::sort(numsWithIndex.begin(), numsWithIndex.end());

        int left = 0;
        int right = numsWithIndex.size() - 1;

        while (left < right) {
            int sum = numsWithIndex[left].first + numsWithIndex[right].first;
            if (sum == target) {
                return {numsWithIndex[left].second, numsWithIndex[right].second};
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }

        return {}; // 如果没有找到，返回空向量
    }
};
```


### [283. 移动零](https://leetcode.cn/problems/move-zeroes/)

给定一个数组 `nums`，编写一个函数将所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序。

**请注意** ，必须在不复制数组的情况下原地对数组进行操作。

**示例 1:**

<pre><strong>输入:</strong> nums = <code>[0,1,0,3,12]</code>
<strong>输出:</strong> <code>[1,3,12,0,0]</code>
</pre>

**示例 2:**

<pre><strong>输入:</strong> nums = <code>[0]</code>
<strong>输出:</strong> <code>[0]</code></pre>

 **提示** :

* `1 <= nums.length <= 10<sup>4</sup>`
* `-2<sup>31</sup> <= nums[i] <= 2<sup>31</sup> - 1`

 **进阶：** 你能尽量减少完成的操作次数吗？

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i=0; i < nums.size(); ++i ) {
            if( nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }
        fill(nums.begin() + j, nums.end(), 0);
    }
};
```


[11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/)

给定一个长度为 `n` 的整数数组 `height` 。有 `n` 条垂线，第 `i` 条线的两个端点是 `(i, 0)` 和 `(i, height[i])` 。

找出其中的两条线，使得它们与 `x` 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

 **说明：** 你不能倾斜容器。

**示例 1：**

![](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg)

<pre><strong>输入：</strong>[1,8,6,2,5,4,8,3,7]
<strong>输出：</strong>49 
<strong>解释：</strong>图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。</pre>

**示例 2：**

<pre><strong>输入：</strong>height = [1,1]
<strong>输出：</strong>1
</pre>

**提示：**

* `n == height.length`
* `2 <= n <= 10<sup>5</sup>`
* `0 <= height[i] <= 10<sup>4</sup>`

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left < right) {
            int currWater = (right - left) * min(height[left],height[right] );
            maxWater = max(maxWater, currWater);
            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};
```



### [3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)

提示

给定一个字符串 `s` ，请你找出其中不含有重复字符的 **最长 子串** 的长度。

**示例 1:**

<pre><strong>输入: </strong>s = "abcabcbb"
<strong>输出: </strong>3 
<strong>解释:</strong> 因为无重复字符的最长子串是 <code>"abc"</code>，所以其长度为 3。
</pre>

**示例 2:**

<pre><strong>输入: </strong>s = "bbbbb"
<strong>输出: </strong>1
<strong>解释: </strong>因为无重复字符的最长子串是 <code>"b"</code>，所以其长度为 1。
</pre>

**示例 3:**

<pre><strong>输入: </strong>s = "pwwkew"
<strong>输出: </strong>3
<strong>解释: </strong>因为无重复字符的最长子串是 <code>"wke"</code>，所以其长度为 3。
     请注意，你的答案必须是 <strong>子串 </strong>的长度，<code>"pwke"</code> 是一个<em>子序列，</em>不是子串。
</pre>

**提示：**

* `0 <= s.length <= 5 * 10<sup>4</sup>`
* `s` 由英文字母、数字、符号和空格组成

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_pos(256, -1);  // 记录字符最后出现的位置，初始为-1
        int max_len = 0;
        int left = 0;  // 滑动窗口的左边界
      
        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            // 如果字符c已经出现过，并且其位置在当前的窗口范围内，则移动左边界
            if (last_pos[c] != -1 && last_pos[c] >= left) {
                left = last_pos[c] + 1;
            }
            last_pos[c] = right;  // 更新字符c的最后出现位置
            max_len = max(max_len, right - left + 1);  // 计算当前窗口长度
        }
      
        return max_len;
    }
};
```
