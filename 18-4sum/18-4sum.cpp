class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        unordered_map<int,set<vector<int>>> mp;
        set<vector<int>> ans;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(i>1 && nums[i]==nums[i-2]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+2 && nums[j]==nums[j-2]) continue;
                int target1 = target-nums[i]-nums[j];
                for(auto k:mp[target1]){
                    if(i==k[0] || i==k[1] || j==k[0] || j == k[1]) continue;
                    vector<int> temp = {nums[k[0]],nums[k[1]],nums[i],nums[j]};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }
                mp[nums[i]+nums[j]].insert({i,j});
            }
        }
        
        vector<vector<int>> res(ans.size());
        copy(ans.begin(),ans.end(),res.begin());
        
        return res;
    }
};