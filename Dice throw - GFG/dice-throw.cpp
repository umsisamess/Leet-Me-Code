// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long helper(int M, int N, int X, vector<vector<long long>>& dp){
        if(N==0){
            if(X==0) return 1;
            else return 0;
        }
        
        
        if(dp[X][N]!=-1) return dp[X][N];
        
        long long int ans = 0;
        for(int i=1;i<=M;i++){
            if(X-i>=0) ans += helper(M,N-1,X-i,dp);
        }
        
        return dp[X][N] = ans;
    }
  
    long long noOfWays(int M , int N , int X) {
        vector<vector<long long>> dp(X+1,vector<long long>(N+1,-1));
        return helper(M,N,X,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}  // } Driver Code Ends