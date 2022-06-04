// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long helper(int arr[], int n, int start, int end, bool myTurn, vector<vector<long long>>& dp){
        if(start>end) return 0;
        if(dp[start][end]) return dp[start][end];
        
        
        if(myTurn){
            long long leftside = arr[start] + helper(arr,n,start+1,end,!myTurn,dp);
            long long rightside = arr[end] + helper(arr,n,start,end-1,!myTurn,dp);
            dp[start][end] =  max(leftside,rightside);
        }else{
            long long leftside = helper(arr,n,start+1,end,!myTurn,dp);
            long long rightside = helper(arr,n,start,end-1,!myTurn,dp);
            dp[start][end] =  min(leftside,rightside);
        }
        
        return dp[start][end];
    }
    
    long long maximumAmount(int arr[], int n){
        vector<vector<long long>> dp(n,vector<long long>(n));
        return helper(arr,n,0,n-1,true,dp);
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends