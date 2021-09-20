class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        
        while(low < high){
            int mid = (low + high) / 2;
            if(nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        
        int rotate_index = low;
        
        int left_res = bi_search(0, rotate_index, nums, target);
        int right_res = bi_search(rotate_index, nums.size() - 1, nums, target);
        
        return max(left_res, right_res);
    }
private:
    int bi_search(int low, int high, const vector<int> &nums, int target){        
        while(low < high){
            int median = (low + high) / 2;
            if(nums[median] < target){
                low = median + 1;
            }else{
                high = median;
            }
        }
        
        if(nums[low] == target){
            return low;
        }else{
            return -1;
        }
    }
};