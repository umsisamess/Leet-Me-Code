// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    bool checkCycle(vector<vector<int>>& graph, int node, vector<int>& visited, vector<int>& order){
        if(visited[node] == 2){
            return false;
        }
        
        visited[node] = 1;
        
        vector<int> ans;
        for(auto e:graph[node]){
            if(visited[e]==1) return true;
            if(visited[e]==2) continue;
            if(checkCycle(graph,e,visited,order)) return true;
        }
        
        order.push_back(node);
        visited[node] = 2;
        return false;
    }
  
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<vector<int>> graph(n,vector<int>());
       for(auto pre: prerequisites){
           graph[pre[0]].push_back(pre[1]);
       }
       
       vector<int> visited(n);
       vector<int> order;
       
       vector<int> ans;
       for(int i=0;i<n;i++){
           if(checkCycle(graph, i, visited, order)) return {};

       }
       
      return order;
       
    }
};

// { Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends