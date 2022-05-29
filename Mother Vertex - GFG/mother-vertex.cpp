// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    int dfs(int node, vector<int> adj[], vector<int>& visited,vector<int>& done){
        // cout<<node<<" ";
        if(done[node]) return done[node];
        
        visited[node] = 1;
        int ans = 1;
        
        for(int e: adj[node]){
            if(!visited[e]){
                ans += dfs(e,adj,visited,done);
                visited[e] = 2;
            }
            else{
                if(done[e] && visited[e]==1){
                    visited[e] = 2;
                    ans += done[e];
                }
            }
        }
        
        done[node] = ans;
        
        return ans;
    }
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int> visited(V);
	    vector<int> done(V);
	    for(int i=0;i<V;i++){
	        if(dfs(i,adj,visited,done)==V) return i;
	    }
	    return -1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends