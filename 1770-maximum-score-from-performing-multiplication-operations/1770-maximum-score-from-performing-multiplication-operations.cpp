class Solution {
public:
    int findMaxAns(vector<int>& nums, vector<int>& multipliers,int ans,int start, int end, int i,vector<vector<int>>& dp){
        if(i==multipliers.size()){
            return 0;
        }
        if(dp[start][i]!=-1){
            return dp[start][i];
        }
        int x = multipliers[i]*nums[end]+findMaxAns(nums,multipliers,ans,start,end-1,i+1,dp);
        int y = multipliers[i]*nums[start]+findMaxAns(nums,multipliers,ans,start+1,end,i+1,dp);
        dp[start][i] = max(x,y);
        return dp[start][i];
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        long ans = 0;
        vector<vector<int>> dp(multipliers.size(),vector<int>(multipliers.size(),-1));
        int p = nums.size()-1;
        return findMaxAns(nums,multipliers,ans,0,p,0,dp);
    }
};