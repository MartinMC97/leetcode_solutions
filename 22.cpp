// backtracking
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
    
    void backtrack(vector<string> &vec, string s, int open, int close, int max){
        if(s.size() == 2 * max){
            vec.push_back(s);
            return;
        }
        
        if(open < max){
            backtrack(vec, s + "(", open + 1, close, max);
        }
        
        if(close < open){
            backtrack(vec, s + ")", open, close + 1, max);
        }
    }
};