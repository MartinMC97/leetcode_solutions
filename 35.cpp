class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target <= nums[0]) return 0;
        if(target == nums.back()) return nums.size() - 1;
        if(target > nums.back()) return nums.size();
        
        int low = 0, high = nums.size() - 1;
        
        while(low != high - 1){
            int median = low + (high - low) / 2;
            if(target < nums[median]){
                high = median;
            }else if(target > nums[median]){
                low = median;
            }else{
                return median;
            }
        }
                     
        return low + 1;
    }
};