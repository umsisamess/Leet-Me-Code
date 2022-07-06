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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxi = -1;
        int maxsum = INT_MIN;
        int lvl = 0;
        while(!q.empty()){
            lvl++;
            queue<TreeNode*> q1;
            int sum = 0;
            while(!q.empty()){
                TreeNode *x = q.front();
                q.pop();
                sum += x->val;
                if(x->left) q1.push(x->left);
                if(x->right) q1.push(x->right);
            }
            if(sum>maxsum){
                maxsum = sum;
                maxi = lvl;
            }
            q = q1;
        }
        return maxi;
    }
};