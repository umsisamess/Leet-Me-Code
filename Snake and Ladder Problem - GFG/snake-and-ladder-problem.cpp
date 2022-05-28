// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dfs(int node, vector<vector<int>>& graph, vector<int>& visited){
        if(node==30) return 0;
        
        visited[node] = -2;
        int ans = INT_MAX;
        
        for(int e:graph[node]){
            if(!visited[e]){
                int ans1 = dfs(e,graph,visited);
                if(ans1!=-1) ans = min(ans,1+ans1);
            }else{
                if(visited[e]!=-2){
                    if(visited[e]!=-1) ans = min(ans,1+visited[e]);
                }
            }
        }
        
        visited[node] = ans==INT_MAX?-1:ans;
        return visited[node];
        
    }

    int minThrow(int N, int arr[]){
        vector<vector<int>> graph(31,vector<int>());
        
        for(int i=0;i<2*N;i=i+2){
            graph[arr[i]] = {arr[i+1]};
        }
        
        for(int i=1;i<30;i++){
            if(graph[i].size()>0) continue;
            for(int j=1;j<=6;j++){
                if(i+j<=30){
                    if(graph[i+j].size()>0){
                        graph[i].push_back(graph[i+j][0]);
                    }else{
                        graph[i].push_back(i+j);
                    }
                } 
            }
        }
        
        
        vector<int> visited(31);
        return dfs(1,graph,visited);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends