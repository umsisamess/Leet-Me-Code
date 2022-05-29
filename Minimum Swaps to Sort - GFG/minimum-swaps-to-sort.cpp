// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:

    int find(vector<int>& nums1, int x, int l ,int r){
        if(l>r) return -1;
        int m = l+(r-l)/2;
        if(nums1[m]==x) return m;
        else if(nums1[m]<x) return find(nums1,x,m+1,r);
        else return find(nums1,x,l,m-1);
    }
    
    void dfs(vector<int>& nums, vector<int>& nums1, int pos, vector<int>& visited, int& numNodes){
        visited[pos] = true;
        
        int new_pos = find(nums1, nums[pos], 0, nums.size()-1);
        
        if(!visited[new_pos]){
            dfs(nums,nums1,new_pos,visited,numNodes);
            numNodes++;
        }
        
        swap(nums[pos],nums[new_pos]);
    }
    
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int> nums1 = nums;
	    sort(nums1.begin(),nums1.end());
	    vector<int> visited(nums.size());
	    
	    int count = 0;
	    for(int i=0;i<nums.size();i++){
	        if(!visited[i]){
	            int numNodes= 0;
	            dfs(nums,nums1,i,visited,numNodes);
	            count += numNodes;
	        }
	    }
	    
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends