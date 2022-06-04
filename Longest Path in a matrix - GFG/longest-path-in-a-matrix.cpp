// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    int helper(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int x, int y, vector<vector<int>>& dp){
        if(visited[x][y]) return dp[x][y];
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        
        int ans = 1;
        
        
        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x>=0 && new_x<matrix.size() && new_y>=0 && new_y<matrix[0].size() && matrix[new_x][new_y]>matrix[x][y]){
                ans = max(ans, 1 + helper(matrix,visited,new_x,new_y,dp));
            }
        }
        
        dp[x][y] = ans;
        visited[x][y] = 1;
        return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size()));
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size()));
        
        int ans = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans = max(ans,helper(matrix, visited, i, j, dp));
            }
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends