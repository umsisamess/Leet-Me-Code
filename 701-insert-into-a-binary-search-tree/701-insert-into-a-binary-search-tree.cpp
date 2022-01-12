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
    void insertIt(TreeNode* root, int val){
        if(root->val>val){
            if(!root->left){
                TreeNode* neww = new TreeNode(val);
                root->left = neww;
                return;
            }
            else{
                insertIt(root->left,val);
            }
            
        }
        else{
            if(!root->right){
                TreeNode* neww = new TreeNode(val);
                root->right = neww;
                return;
            }
            else{
                insertIt(root->right,val);
            }
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* neww = new TreeNode(val);
            root = neww;
        }
        else{
           insertIt(root,val); 
        }
        
        return root;
    }
};