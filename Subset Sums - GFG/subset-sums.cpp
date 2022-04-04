// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void findSubsetSums(vector<int>& arr, int& N, int sum, unordered_map<int,bool> visited, vector<int>& ans,int pos){
        if(pos == N){
            ans.push_back(sum);
            return;
        }
        ans.push_back(sum);
        
        for(int i=pos;i<N;i++){
            if(!visited[i]){
                visited[i] = true;
                findSubsetSums(arr, N, sum+arr[i], visited, ans, i+1);
                visited[i] = false;
            }
        }
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        unordered_map<int,bool> visited;
        int sum = 0;
        vector<int> ans;
        findSubsetSums(arr, N, sum, visited, ans,0);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends