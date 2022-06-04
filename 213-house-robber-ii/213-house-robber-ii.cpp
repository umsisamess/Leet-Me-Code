class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        
        if(n==1) return nums[0];
        
        int ans;
        for(int i=0;i<n-1;i++){
            if(i-3>=0) dp[i] = max(dp[i-3],dp[i-2]) + nums[i];
            else if(i-2>=0) dp[i] = dp[i-2] + nums[i];
            else dp[i] = nums[i];
            ans = max(ans,dp[i]);
        }
        
        
        for(int i=1;i<n;i++){
            if(i-3>=1) dp[i] = max(dp[i-3],dp[i-2]) + nums[i];
            else if(i-2>=1) dp[i] = dp[i-2] + nums[i];
            else dp[i] = nums[i];
            ans = max(ans,dp[i]);
        }
        return ans;
        
    }
};