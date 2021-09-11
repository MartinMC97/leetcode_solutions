/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];
        if(size == 2) return std::max(nums[0], nums[1]);
        
        int dp_i_1 = std::max(nums[0], nums[1]);
        int dp_i_2 = nums[0];
        
        int dp_i;
        for(int i = 2; i < size; i++){
            dp_i = std::max( dp_i_1, dp_i_2 + nums[i] );
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        
        return dp_i;
    }
};
// @lc code=end

