class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        
        while(low <= high){
            int median = low + (high - low) / 2;;
            if(target < nums[median]){
                high = median - 1;
            }
            else if(target > nums[median]){
                low = median + 1;
            }
            else{
                return median;
            }
        }
        
        if(target != nums[low]) 
            return -1;
        else
            return low;
    }
};