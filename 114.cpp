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
    
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode new_root;
        vector<int> tree_array;
        preOrderTraversal(root, tree_array);
        
        TreeNode* tmp = &new_root;
        for(int num: tree_array){
            tmp -> right = new TreeNode(num);
            tmp = tmp -> right;
        }
        *root = *new_root.right;
    }
    
    
    void preOrderTraversal(TreeNode *root,vector<int> &new_root){
        if(root == NULL)
            return;
        
        new_root.push_back(root -> val);
        
        preOrderTraversal(root -> left, new_root);
        preOrderTraversal(root -> right, new_root);
        
    }
    
};