// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){
	    queue<vector<int>> q;
	    
	    int steps = 0;
	    vector<vector<bool>> visited(N,vector<bool>(N));
	    q.push(KnightPos);
	    visited[KnightPos[0]-1][KnightPos[1]-1] = true;
	    while(!q.empty()){
	        int sz = q.size();
	        while(sz--){
	            vector<int> top = q.front();	           
	            
	            q.pop();
	            if(top[0]==TargetPos[0] && top[1]==TargetPos[1]){
	                return steps;
	            }
	            vector<int> dx = {1,1,-1,-1,2,2,-2,-2};
	            vector<int> dy = {2,-2,2,-2,1,-1,1,-1};
	            for(int i=0;i<8;i++){
	                int new_x = top[0] + dx[i];
	                int new_y = top[1] + dy[i];
	                if(new_x>0 && new_x<=N && new_y>0 && new_y<=N && !visited[new_x-1][new_y-1]){
	                    visited[new_x-1][new_y-1] = true;
	                    q.push({new_x,new_y});
	                }
	            }
	        }
	        steps++;
	        
	    }
	    
	    return -1;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends