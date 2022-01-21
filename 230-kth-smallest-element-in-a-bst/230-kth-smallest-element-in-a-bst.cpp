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
    void InOrder(TreeNode* root, int& k, int& ans){
        if(root->left) InOrder(root->left,k,ans);
        k--;
        if(k==0) ans =  root->val;
        if(root->right) InOrder(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        InOrder(root,k,ans);
        return ans;
    }
};