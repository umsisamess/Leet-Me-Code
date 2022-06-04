class Solution {
public:
    bool isValid(int n, vector<string>& board, int x, int y){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='Q' && (x!=i || y!=j)){
                    if(x==i) return false;
                    if(y==j) return false;
                    if(abs(x-i)==abs(y-j)) return false;
                }
            }
        }
        
        return true;
        
    }
    
    void helper(int n, vector<vector<string>>& ans, int x, int y, vector<string>& board){
        board[x][y] = 'Q';
        
        if(x+1<n){
            for(int j=0;j<n;j++){
                if(isValid(n,board,x+1,j)){
                    helper(n,ans,x+1,j,board);
                }
            }
        }
        
        if(x==n-1) ans.push_back(board);
        board[x][y] = '.';
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string bd = "";
        for(int i=0;i<n;i++) bd +=".";
        vector<string> board(n,bd);
        for(int j=0;j<n;j++){
            helper(n,ans,0,j,board);
        }
        return ans;
    }
};