// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool checkOddCycle(int node, int parentNode, vector<int> adj[], vector<int>& visited){
        if(visited[node]) return false;
        if(parentNode==-1) visited[node] = 1;
        else visited[node] = visited[parentNode]==1?2:1;
        
        for(int i:adj[node]){
            if(!visited[i]){
                if(checkOddCycle(i,node,adj,visited)){
                    return true;
                }
            }else{
                if(visited[i]==visited[node]){
                    return true;
                }
            }
        }
        
        return false;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> visited(V);
	    for(int i=0;i<V;i++){
	        if(checkOddCycle(i,-1,adj,visited)){
	            return false;
	        }
	    }
	    return true;
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
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends