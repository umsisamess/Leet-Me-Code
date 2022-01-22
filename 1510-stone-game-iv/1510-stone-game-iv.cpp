class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<n+1;i++){
            for(int j=1;j*j<=i;j++){
                dp[i] = 1+dp[i-j*j];
                if(dp[i]%2==1) break;
            }
        }
        return dp[n]%2==1?true:false;
    }
};