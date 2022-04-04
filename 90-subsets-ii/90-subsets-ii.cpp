class Solution {
public:
    void findSubsets(vector<int>& nums, map<vector<int>,bool> visited, vector<int> temp, vector<vector<int>>& ans, int pos){
        if(pos == nums.size()){
            ans.push_back(temp);
            return;
        }
        ans.push_back(temp);
        
        for(int i=pos;i<nums.size();i++){
            if(!visited[{pos,nums[i]}]){
                visited[{pos,nums[i]}] = true;
                temp.push_back(nums[i]);
                findSubsets(nums, visited, temp, ans, i+1);
                temp.pop_back();
                // visited[{pos,nums[i]}] = false;
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<vector<int>,bool> visited;
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        findSubsets(nums, visited, temp, ans, 0);
        return ans;
    }
};