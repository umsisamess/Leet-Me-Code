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
    void reverseInorder(TreeNode* root, int& x){
        if(!root) return;
        reverseInorder(root->right,x);
        root->val += x;
        x = root->val;
        reverseInorder(root->left,x);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int x = 0;
        reverseInorder(root, x);
        return root;
    }
};