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
    bool solve(TreeNode* root, int maxElement, int minElement){
        if(!root) return true;
        if((root->val >= maxElement) || root->val  <= minElement) return false;
        return solve(root->left, root->val, minElement)&& solve(root->right,maxElement, root->val);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        return solve(root, INT_MAX, INT_MIN);
    }
};
