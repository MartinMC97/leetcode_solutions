class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            for(int m = i, n = i; m >= 0 && n < s.size() && s[m] == s[n]; m--, n++){
                res++;
            }
            for(int m = i, n = i + 1; m >= 0 && n < s.size() && s[m] == s[n]; m--, n++){
                res++;
            }
        }
        return res;
    }
};