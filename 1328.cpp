class Solution {
public:
    string breakPalindrome(string palindrome) {
        // How to detect if there is impossible to perform the replacement? Only when the length = 1.
        if(palindrome.size() == 1) return string();
        int i = 0;
        string str(palindrome);
        for(; i < str.size() / 2; i++){
            // Change the first non 'a' character to 'a'.
            if(str[i] != 'a'){
                str[i] = 'a';
                return str;
            }
        }
        // What if the string has only 'a'?
        //Change the last character to 'b'.
        str[str.size() - 1] = 'b';
        return str;
    }
};