/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:

    int robRange(vector<int> &nums, int start, int end){
        int size = end - start + 1;
        if(size == 1) return nums[start];
        if(size == 2) return std::max(nums[start], nums[start + 1]);
        
        int dp_i_1 = std::max(nums[start], nums[start + 1]);
        int dp_i_2 = nums[start];
        
        int dp_i;
        for(int i = start + 2; i <= end; i++){
            dp_i = std::max( dp_i_1, dp_i_2 + nums[i] );
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        
        return dp_i;
    }
    
    
    int rob(vector<int>& nums) {
        int size = nums.size();
        
        if(size == 1) return nums[0];
        if(size == 2) return std::max(nums[0], nums[1]);
        
        return std::max(robRange(nums, 0, size - 2), robRange(nums, 1, size - 1));
    }
};
// @lc code=end

