class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int front = 0, back = 1;
        
        while(front < nums.size() && back < nums.size()){
            while(front < nums.size() && nums[front] % 2 == 0) front += 2;
            while(back < nums.size() && nums[back] % 2 == 1) back += 2;
            if(front < nums.size() && back < nums.size()){
                swap(nums[front], nums[back]);
            }
            front += 2;
            back += 2;
        }
        return nums;
    }
};