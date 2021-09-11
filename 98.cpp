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
    vector<int> inorder_array;
    
    bool isValidBST(TreeNode* root) {
        inOrderTraverse(root, inorder_array);
        
        
        return judgeAscendingOrder(inorder_array);
    }
    
    void inOrderTraverse(TreeNode* root, vector<int> &inorder_array){
        if(root == NULL) return;
        
        if(root -> left) inOrderTraverse(root-> left, inorder_array);
        inorder_array.push_back(root -> val);
        if(root -> right) inOrderTraverse(root -> right, inorder_array);
    }
    
    bool judgeAscendingOrder(const vector<int> &inorder_array){
        for (int i = 0; i < inorder_array.size() - 1; i++) {
        if (inorder_array[i] >= inorder_array[i+1]) {
            return false;
            }
        }
        return true;
    }
};