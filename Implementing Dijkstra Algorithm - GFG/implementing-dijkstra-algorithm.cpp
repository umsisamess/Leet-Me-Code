// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> minDist(V,INT_MAX);
        
        minDist[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty()){
            pair<int,int> x = pq.top();
            pq.pop();
            int dist_x = x.first;
            int node_x = x.second;
            
            for(int i=0;i<adj[node_x].size();i++){
                vector<int> y = adj[node_x][i];
                int dist_y = y[1];
                int node_y = y[0];
                
                if(dist_y + dist_x < minDist[node_y]){
                    pq.push({dist_y+dist_x, node_y});
                    minDist[node_y] = dist_y + dist_x;
                }
            }
        }
        return minDist;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends