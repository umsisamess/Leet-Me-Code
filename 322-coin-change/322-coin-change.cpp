class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        if(amount==0) return 0;
        for(int j=1;j<=amount;j++){
            for(int i=0;i<coins.size();i++){
                if(j<coins[i]) break;
                if(dp[j-coins[i]] != INT_MAX) dp[j] = min(dp[j],dp[j-coins[i]]+1);
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};