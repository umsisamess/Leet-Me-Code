// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    bool checkHamiltonian(vector<vector<int>>& graph, int node, int count, vector<bool>& visited, int N){
        if(count == N) return true;
        
        visited[node] = true;
        
        for(int el: graph[node]){
            if(!visited[el]){
                if(checkHamiltonian(graph, el, count+1, visited, N)){
                    return true;
                }
            }
        }
        visited[node] = false;
        return false;
    }
    
    bool check(int N,int M,vector<vector<int>> Edges){
        vector<bool> visited(N+1);
        vector<vector<int>> graph(N+1,vector<int>());
        for(auto e: Edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        for(int i=0;i<N;i++){
            if(checkHamiltonian(graph, i+1, 1, visited, N)){
                return true;
            }
        }
        return false;
    }
};
 

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}  // } Driver Code Ends