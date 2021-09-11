class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(vector<int>(), candidates, target, 0);
        return res;
    }
    
    int get_sum_of_vector(const vector<int> &vec){
        int sum = 0;
        for(int num: vec)
            sum += num;
        return sum;
    }
    
    void backtracking(vector<int> temp, const vector<int> &candidates, int target, int begin){
        int sum = get_sum_of_vector(temp);
        if(sum == target){
            res.push_back(temp);
            return;
        }
        int remain = target - sum;
        for(int i = begin; i < candidates.size(); i++){
            if(candidates[i] <= remain){
                temp.push_back(candidates[i]);
                backtracking(temp, candidates, target, i);
                temp.pop_back();
            }
            else{
                continue;
            }
        }
    }
};