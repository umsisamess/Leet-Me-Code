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
    int helper(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        if(!root) return 0;
        if(dp[root]) return dp[root];
        if(root->left && root->right){
            dp[root] = max(
                helper(root->left,dp) + helper(root->right,dp),
                helper(root->left->left,dp)+helper(root->left->right,dp)+
                helper(root->right->left,dp)+helper(root->right->right,dp)+
                root->val
            );   
        }else if(root->left){
            dp[root] = max(
                helper(root->left,dp) + helper(root->right,dp),
                helper(root->left->left,dp)+helper(root->left->right,dp)+
                root->val
            );
        }else if(root->right){
            dp[root] = max(
                helper(root->left,dp) + helper(root->right,dp),
                helper(root->right->left,dp)+helper(root->right->right,dp)+
                root->val
            ); 
        }else{
            dp[root] = root->val;
        }
        
        return dp[root];
        
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return helper(root,dp);
    }
};