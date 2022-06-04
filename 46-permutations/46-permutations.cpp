class Solution {
public:
    void helper(vector<int>& nums, unordered_map<int,bool>& visited, vector<int>& temp, vector<vector<int>>& ans, int pos){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[nums[i]]){
                visited[nums[i]] = true;
                temp.push_back(nums[i]);
                helper(nums,visited,temp,ans,pos);
                visited[nums[i]] = false;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,bool> visited;
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums,visited,temp,ans,0);
        return ans;
    }
};