// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool detectCycle(vector<vector<int>>& graph, int node, vector<bool>& visited, vector<int>& cycle){
        if(visited[node]){
            if(cycle[node]==1) return true;
            else if(cycle[node]==2) return false;
            else{
                cycle[node] = 1;
                return true;
            }
        }
        
        visited[node] = true;
        for(int g: graph[node]){
            if(detectCycle(graph,g,visited,cycle)) return true;
        }
        
        cycle[node]=2;
        return false;
    }

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>> graph(N,vector<int>());
	    for(auto pre: prerequisites){
	        graph[pre.second].push_back(pre.first);
	    }
	    vector<bool> visited(N);
	    vector<int> cycle(N);
	    for(int i=0;i<N;i++){
	        if(detectCycle(graph,i,visited, cycle)) return false;
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends