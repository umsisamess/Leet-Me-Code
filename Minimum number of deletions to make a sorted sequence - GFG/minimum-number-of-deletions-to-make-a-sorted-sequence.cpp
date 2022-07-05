// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	
	int longestIncreasingSubsequence(int arr[], int n){
	    vector<int> v;
	    v.push_back(arr[0]);
	    for(int i=1;i<n;i++){
	        if(arr[i]>v[v.size()-1]){
	            v.push_back(arr[i]);
	        }else{
	            int l = 0;
	            int r = v.size()-1;
	            while(l<=r){
	                int mid = (l + (r-l)/2);
	                if(v[mid]==arr[i]){
	                    v[mid] = arr[i];
	                    break;
	                }else if(v[mid]<arr[i]){
	                    if(v[mid+1]>arr[i]){
	                        v[mid+1] = arr[i];
	                        break;
	                    }else{
	                        l = mid + 1;
	                    }
	                }else if(v[mid]>arr[i]){
	                    if(mid==0){
	                        v[mid] = arr[i];
	                        break;
	                    }else{
	                        if(v[mid-1]<arr[i]){
	                            v[mid] = arr[i];
	                            break;
	                        }else{
	                            r = mid-1;
	                        }
	                    }
	                }
	            }
	            
	        }
	    }
	    return v.size();
	}
	
	int minDeletions(int arr[], int n){ 
	    int l = longestIncreasingSubsequence(arr,n);
	    return n-l;
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

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

	    

	    Solution ob;
	    cout << ob.minDeletions(arr, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends