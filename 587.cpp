class Solution {
public:
    int calculateRotation(vector<int> A, vector<int> B, vector<int> C){
        // (x2-x1)(y3-y1) - (y2-y1)(x3-x1) 
        // https://blog.csdn.net/qq_42778110/article/details/81567954 判断向量转向
        // negative: ac left ab, positive ac right ab
        return ((B[0] - A[0]) * (C[1] - A[1])) - ((B[1] - A[1]) * (C[0] - A[0]));
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size() <= 3) return trees;
        
        //Sort the array based on the x-axis values (lexicographical).
        std::sort(trees.begin(), trees.end());
        
        /* Create upper HULL */
        
        // create a upper_list
        vector<vector<int>> upper_list;
        // insert first two sorted elements
        upper_list.push_back(trees[0]);
        upper_list.push_back(trees[1]);
        for(int i = 2; i < trees.size(); i++){
                //upper_list.pop_back();
                int upper_size = upper_list.size();
                while(upper_list.size() >= 2 && calculateRotation(upper_list[upper_size - 2], upper_list[upper_size - 1], trees[i]) > 0){
                    upper_list.pop_back();
                    upper_size--;
                }
                upper_list.push_back(trees[i]);
        }
        
        /* Create lower HULL */
        vector<vector<int>> lower_list;
        lower_list.push_back(trees[trees.size() - 1]);
        lower_list.push_back(trees[trees.size() - 2]);
        
        for(int i = trees.size() - 3; i >= 0; i--){
            int lower_size = lower_list.size();
            while(lower_size >= 2 && (calculateRotation(lower_list[lower_size - 2], lower_list[lower_size - 1], trees[i]) > 0)){
                lower_list.pop_back();
                lower_size--;
            }
            lower_list.push_back(trees[i]);
        }
        
        for(vector<int> pair: upper_list){
            lower_list.push_back(pair);
        }
        
        sort(lower_list.begin(), lower_list.end());

        auto last = std::unique(lower_list.begin(), lower_list.end());
        lower_list.erase(last, lower_list.end());
        
        return lower_list;
    }
};