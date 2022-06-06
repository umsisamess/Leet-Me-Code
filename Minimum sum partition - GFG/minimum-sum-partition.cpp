// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int helper(int arr[], int n, vector<int>& dp, int sum, int leftsum, vector<bool>& visited){
        if(leftsum == sum) return sum;
        if(dp[leftsum]!=-1) return dp[leftsum];
        
        int ans = sum;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i] = true;
                ans = min(ans, helper(arr,n,dp,sum,leftsum+arr[i],visited));
                visited[i] = false;
            }
        }
        ans = min(abs(leftsum-(sum-leftsum)),ans);
        return dp[leftsum]= ans;
    }
  
	int minDifference(int arr[], int n)  {
	    int sum = 0;
	    for(int i=0;i<n;i++){
	        sum += arr[i];
	    }
	    
	    vector<int> dp(sum+1,-1);
	    vector<bool> visited(n);
	    
	    return helper(arr, n, dp, sum, 0, visited);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends