class Solution {
public:
    int helper(string word1, string word2, int start1, int start2,vector<vector<int>>& dp){
        if(start1==word1.length()){
            return (int)word2.length()-start2;
        }else if(start2==word2.length()){
            return (int)word1.length()-start1;
        }
        
        if(dp[start1][start2]) return dp[start1][start2];
        
        if(word1[start1]==word2[start2]){
            return dp[start1][start2] =  helper(word1,word2,start1+1,start2+1,dp);
        }else{
            return dp[start1][start2] =  1 + min({
                helper(word1,word2,start1,start2+1,dp),
                helper(word1,word2,start1+1,start2,dp),
                helper(word1,word2,start1+1,start2+1,dp)
            });
        }
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length()));
        return helper(word1,word2,0,0,dp);
    }
};