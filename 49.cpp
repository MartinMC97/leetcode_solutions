class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, vector<std::string>> dict;
        for(string str: strs){
            string ordered_string = str;
            std::sort(ordered_string.begin(), ordered_string.end());
            //strSort(ordered_string); // <- slower than std::sort()
            dict[ordered_string].push_back(str);
        }
        
        vector<vector<string>> res;
        for(pair<string, vector<string>> vec: dict){
            res.push_back(vec.second);
        }
        return res;
    }
private:
    void strSort(string &str){
        int hash[26] = { 0 };
        for(char ch: str){
            hash[ch - 'a']++;
        }
        string new_string;
        for(int i = 0; i < 26; i++){
            if(hash[i] == 0){
                continue;
            }else{
                while(hash[i] != 0){
                    new_string.push_back('a' + i);
                    hash[i]--;
                }
            }
        }
        str = new_string;
    }
};