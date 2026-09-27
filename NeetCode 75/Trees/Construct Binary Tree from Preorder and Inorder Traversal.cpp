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
    TreeNode* bTree(vector<int>& preorder, int preLow, int preHigh, vector<int>& inorder, int inLow, int inHigh, unordered_map<int,int>& mp){
        if(preLow > preHigh || inLow > inHigh) return nullptr;
        TreeNode* root = new TreeNode(preorder[preLow]);
        int root_In_Inorder = mp[root->val];//where the root divides the inorder array
        int numLeft = root_In_Inorder - inLow;//Calculate the number of left subtree nodes
        root->left = bTree(preorder, preLow+1, preHigh,inorder, inLow, root_In_Inorder-1,mp);
        root->right = bTree(preorder, preLow+numLeft+1, preHigh, inorder, root_In_Inorder+1, inHigh,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]] =i;
        
        TreeNode* root = bTree(preorder, 0, preorder.size()-1, inorder,0,inorder.size()-1, mp);
        return root;
    }
};
