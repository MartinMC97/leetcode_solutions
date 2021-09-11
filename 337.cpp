/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 */

// @lc code=start
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
#include <bits/stdc++.h>

class Solution {
public:

    std::unordered_map<TreeNode*, int> note;
    int rob(TreeNode* root) {
        if(root == NULL) return 0;

        if( note[root] != NULL ) return note[root];

        int val_robbed = root->val
                        + (root -> left == NULL ? 0 : rob(root->left->left) + rob(root -> left -> right))
                        + (root -> right == NULL ? 0 : rob(root -> right -> left) + rob(root -> right -> right));

        int val_not_robbed = rob(root -> left) + rob(root -> right);
        int res = std::max(val_robbed, val_not_robbed);
        note[root] = res;
        return res;                
    }
};

// @lc code=end

