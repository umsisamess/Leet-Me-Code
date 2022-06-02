// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool helper(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& ans){
        ans[x][y] = 1;
        int n = matrix.size();
        int m = matrix[0].size();
        if(x==n-1 && y == m-1){
            return true;;
        }
        
        for(int i=1;i<=matrix[x][y];i++){
            if(y+i<m && helper(matrix,x,y+i,ans)) return true;
            if(x+i<n && helper(matrix,x+i,y,ans)) return true;
        }
        
        ans[x][y] = 0;
        return false;
        
        
    }

	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	    vector<vector<int>> ans(matrix.size(),vector<int>(matrix[0].size()));
	    bool res = helper(matrix,0,0,ans);
	    if(res) return ans;
	    return {{-1}};
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends