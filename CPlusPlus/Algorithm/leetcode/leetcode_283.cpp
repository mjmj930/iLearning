#include <vector>
#include <algorithm>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int j = 0;
        // 把所有非零元素移动到数组前面
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }
        // 把剩余的位置置为零
        std::fill(nums.begin() + j, nums.end(), 0);
    }
};