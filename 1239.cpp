class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        
        // the minimum number of the result is zero (there is always duplicate characters), not INT_MIN.
        int res = 0;
        
        for(string str: arr){
            bitset<26> char_count;
            //count the unique char in str
            for(char ch: str){
                char_count.set(ch - 'a');
            }
            
            //if the number of 1 is less than the size of str
            //then str contain duplicate characters.
            if(char_count.count() < str.size()) {
                continue;
            }
            
            for(int i = dp.size() - 1; i >=0 ; i--){
                bitset<26> c = dp[i];
                
                if((char_count & c).any()){
                    // duplicate char exists. Skip this set.
                    continue;
                }
                // merge two strings into one.
                dp.push_back(c | char_count);
                
                res = std::max(res,(int)(c | char_count).count());
            }
            
        }
        return res;
    }
};