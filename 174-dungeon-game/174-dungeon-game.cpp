class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n));
        dp[m-1][n-1] = 1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) dp[i][j] = dungeon[i][j]>=0?1:1-dungeon[i][j];
                else if(i==m-1) dp[i][j] = dp[i][j+1]-dungeon[i][j]>0?dp[i][j+1]-dungeon[i][j]:1;
                else if(j==n-1) dp[i][j] = dp[i+1][j]-dungeon[i][j]>0?dp[i+1][j]-dungeon[i][j]:1;
                else dp[i][j] = min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]>0?min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]:1;
            }
        }
        return dp[0][0];
    }
};