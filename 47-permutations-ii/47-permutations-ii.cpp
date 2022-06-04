class Solution {
public:
    void helper(vector<int>& nums, unordered_map<int,bool>& visited, vector<vector<int>>& ans, vector<int>& temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
        }

        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                if(i>0 && !visited[i-1] && nums[i]==nums[i-1]) continue;
                visited[i] = true;
                temp.push_back(nums[i]);
                helper(nums,visited,ans,temp);
                visited[i] = false;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,bool> visited;
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums,visited,ans,temp);
        return ans;
    }
};