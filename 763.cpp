class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_pos_hash(26, 0);
        vector<int> res;
        
        for(int i = 0; i < s.size(); i++){
            last_pos_hash[s[i] - 'a'] = i;
        }
        
        
        int last = INT_MIN, start = 0;
        for(int i = 0; i < s.size(); i++){
            last = std::max(last, last_pos_hash[s[i] - 'a']);
             if(i == last){ // reached the last pos of the specific character
                 res.push_back(last - start + 1);
                 start = last + 1;
             }
        }
        
        return res;
    }
};