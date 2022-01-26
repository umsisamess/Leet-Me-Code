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
    void inOrder(TreeNode* root,vector<int>& v){
        if(!root) return;
        inOrder(root->left,v);
        v.push_back(root->val);
        inOrder(root->right,v);
    }

    void merge(vector<int>& v1, vector<int>&v2, vector<int>&v3){
        int l1 = v1.size(),l2 = v2.size();
        int i = 0,j=0;
        while(i<l1 && j<l2){
            if(v1[i]<v2[j]) v3.push_back(v1[i++]);
            else v3.push_back(v2[j++]);
        }
        while(i<l1) v3.push_back(v1[i++]);
        while(j<l2) v3.push_back(v2[j++]);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        inOrder(root1,v1);
        vector<int> v2;
        inOrder(root2,v2);
        vector<int> v3;
        merge(v1,v2,v3);
        return v3;
    }
};