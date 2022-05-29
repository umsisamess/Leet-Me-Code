// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    void dfs(vector<vector<char>>& grid, int x, int y, int n, int m){
        grid[x][y] = 0;
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        for(int i=0;i<4;i++){
            int new_x = x+dx[i];
            int new_y = y+dy[i];
            if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && grid[new_x][new_y]=='X'){
                dfs(grid,new_x,new_y,n,m);
            }
        }
    }
    
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        // vector<vector<int>> visited;
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    dfs(grid,i,j,n,m);
                    count++;
                }
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends