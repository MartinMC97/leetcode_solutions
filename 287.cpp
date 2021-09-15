class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> hash(100001, 0);
        for(int num: nums){
            hash[num]++;
        }
        
        for(int i = 0; i < hash.size(); i++){
            if(hash[i] > 1) return i;
        }
        
        return 0;
    }
};