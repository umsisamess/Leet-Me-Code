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
    void findTheSum(TreeNode* root, int temp, int& sum){
        if(!root->left && !root->right){
            sum += temp + root->val;
            return;
        }
        if(root->left){
            findTheSum(root->left, (temp+root->val)*2,sum);
        }
        if(root->right){
            findTheSum(root->right,(temp+root->val)*2,sum);
        }
        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        findTheSum(root,0,sum);
        return sum;
    }
};