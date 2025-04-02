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