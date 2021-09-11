class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        vector<int> res(nums.size(), 0);
        
        int res_pos = nums.size() - 1;
        while(low < high){
            int low_square = pow(abs(nums[low]), 2);
            int high_square = pow(abs(nums[high]), 2);
            
            if(low_square >= high_square){
                res[res_pos] = low_square;
                low++;
                res_pos--;
            }else{
                res[res_pos] = high_square;
                high--;
                res_pos--;
            }
        }
        
        res[0] = pow(abs(nums[low]), 2);
        return res;
        
    }
};