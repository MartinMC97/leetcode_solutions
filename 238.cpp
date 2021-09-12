class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total_product_except_zero = 1;
        int zero_count = 0;
        for(int num: nums){
            if(num == 0){
                zero_count++;
                continue;
            }else{
                total_product_except_zero *= num;
            }
        }
        vector<int> res;
        for(int i =0; i < nums.size(); i++){
            if(zero_count == 0){
                res.push_back(total_product_except_zero / nums[i]);
            }else{
                if(nums[i] != 0){
                    res.push_back(0);
                }else{
                    if(zero_count > 1){
                        res.push_back(0);
                    }else{
                    res.push_back(total_product_except_zero);
                    }
            }
            }
        }
        
        return res;
    }
};