#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            int n = nums.size();
            if( n < 3) {
                return result;
            }
            sort(nums.begin(), nums.end());
            for(int i=0; i < n-2; ++i) {
                if(nums[i] > 0) {
                    break;
                }
                if (i > 0 && nums[i] == nums[i-1]) {
                    continue;
                }
                int left = i + 1;
                int right = n - 1;
                while(left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    if(sum < 0) {
                        ++left;
                    } else if (sum > 0) {
                        --right;
                    } else {
                        result.push_back({nums[i], nums[left], nums[right]});
                        // 去除重复的三元组
                        while(left < right && nums[left] == nums[left + 1])
                        {
                            ++left;
                        }
                        while(left < right && nums[right] == nums[right - 1])
                        {
                            --right;
                        }
                        ++left;
                        --right;
                    }
                }
            }
            return result;
        }
    };


int main() {
    Solution sol;
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result = sol.threeSum(nums);
    for (const auto& triplet : result) {
        for (int num : triplet) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}