#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> reslt;
            if(n < 3) {
                return reslt;
            }
            sort(nums.begin(), nums.end());
            for(int i=0; i < n - 2; ++i){
                if(nums[i] > 0) {
                    break;
                }
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i + 1;
            int right = n - 1;
            
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum > 0) {
                    right--;
                } else if(sum < 0) {
                    left++;
                } else {
                    reslt.push_back({nums[i],nums[left],nums[right]});
                    while(left < right && nums[left] == nums[left+1]) {
                        left++;
                    }
                    while(left < right && nums[right] == nums[right-1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
            }
            return reslt;
        }
    };