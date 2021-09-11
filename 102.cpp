/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> temp_queue;
        vector<vector<int>> res;
        
        if(root == NULL) return res;
        
        res.push_back(vector<int>(1, root -> val));
        if(root -> left) temp_queue.push(root -> left);
        if(root -> right) temp_queue.push(root -> right);
        
        while(!temp_queue.empty()){
            int queue_size = temp_queue.size();
            vector<int> res_item;
            for(int i = 0; i < queue_size; i++){
                if(temp_queue.front() -> left) temp_queue.push(temp_queue.front() -> left);
                if(temp_queue.front() -> right) temp_queue.push(temp_queue.front() -> right);
                res_item.push_back(temp_queue.front() -> val);
                temp_queue.pop();
            }
            res.push_back(res_item);
        }
        return res;
    }
};