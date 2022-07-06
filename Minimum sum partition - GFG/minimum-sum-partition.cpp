// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0;i<n;i++){
	        sum += arr[i];
	    }
	    sort(arr,arr+n);
	    
	    vector<vector<int>> dp(sum+1,vector<int>(2));
	    dp[sum] = {1,1};
	    
	    int mini = sum;
	    for(int j=n-1;j>=0;j--){
    	    for(int i=0;i<=sum;i++){
    	        if(dp[i][0]==0) continue;
    	        
    	        if(dp[i][1]==1){
    	            int diff = abs(2*arr[j]-i);
    	            int dir;
    	            if(i>=2*arr[j]) dir = 1;
    	            else dir = 2;
    	            dp[diff][0] = 1;
    	            dp[diff][1] = dp[diff][1]==1?1:dir;
    	            mini = min(mini,diff);
    	        }
    	    }
	    }
	    
	    return mini;
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