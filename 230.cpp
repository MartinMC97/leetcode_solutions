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

// CAUTION: NOT OPTIMAL
 
class Solution {
public:
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        inOrderTraverse(root, res);
        return res[k - 1];
    }
    
    void inOrderTraverse(TreeNode* root, vector<int> &res){
        if(!root) return;
        if(root -> left) inOrderTraverse(root -> left, res);
        res.push_back(root -> val);
        if(root -> right) inOrderTraverse(root -> right, res);
    }
};