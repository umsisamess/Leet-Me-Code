// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	int bfs(int node, vector<int> adj[], vector<int>& visited, int X){
	    int lvl = 0;
	    
	    queue<int> q;
	    visited[node] = 1;
	    q.push(node);
	    while(!q.empty()){
	        int y = q.front();
	        q.pop();
	        if(y==X) return visited[y]-1;
	        for(int e:adj[y]){
	            if(!visited[e]){
	                q.push(e);
	                visited[e] = visited[y]+1;
	            }
	        }
	    }
	    
	    return -1;
	    
	}
	
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    if(X>=V) return -1;
	    vector<int> level(V);
	    return bfs(0,adj,level,X);
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends