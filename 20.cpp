class Solution {
public:
    
    bool get_matching(char left, char right){
        return (left == '[' && right ==']') || (left == '(' && right == ')') || (left == '{' && right == '}');
    }
    
    bool isValid(string s) {
        vector<char> stack;
        
        for(auto ch: s){
            if(ch == '(' || ch == '{' || ch == '['){
                stack.push_back(ch);
                continue;
            } else {
                if(stack.empty()) return false;
                else if(get_matching(stack.back(), ch)){
                        stack.pop_back();
                        continue;
                }else{
                    return false;
                }
            }
        }
        
        return stack.empty();
    }
};