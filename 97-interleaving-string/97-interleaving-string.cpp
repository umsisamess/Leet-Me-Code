class Solution {
public:
    bool helper(string s1, string s2, string s3, int p1, int p2, int p3,vector<vector<int>>& dp){
        if(p1==s1.length() && p2==s2.length() && p3==s3.length()) return true;
        
        if(dp[p1][p2]) return dp[p1][p2]==1?true:false;
        
        if(p1<s1.length() && p3<s3.length() && s1[p1] == s3[p3]){
            if(helper(s1,s2,s3,p1+1,p2,p3+1,dp)){
                dp[p1][p2] = 1;
                return true;
            }
        }
        if(p2<s2.length() && p3<s3.length() && s2[p2] == s3[p3]){
            if(helper(s1,s2,s3,p1,p2+1,p3+1,dp)){
                dp[p1][p2] = 1;
                return true;
            }
        }
        
        dp[p1][p2] = 2;
        return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int p1=0,p2=0,p3=0;
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1));
        return helper(s1,s2,s3,p1,p2,p3,dp);
    }
};