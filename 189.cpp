class Solution { public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res;
        int real_step = k % nums.size();
        
        for(int i = nums.size() - real_step; i < nums.size(); i++){
            res.push_back(nums[i]);
        }
        
        for(int j = 0; j < nums.size() - real_step; j++){
            res.push_back(nums[j]);
        }
        
        nums = res;
    }
};
