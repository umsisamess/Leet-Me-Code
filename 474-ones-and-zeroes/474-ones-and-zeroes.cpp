class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(auto s:strs){
            int ones = count(s.begin(),s.end(),'1');
            int zeros = s.length()-ones;
            for(int i=m;i>=zeros;i--){
                for(int j=n;j>=ones;j--){
                    if(dp[i-zeros][j-ones]==INT_MIN) continue;
                    dp[i][j] = max(dp[i-zeros][j-ones]+1,dp[i][j]);
                }
            }
        }
        
        return dp[m][n];
        
    }
};