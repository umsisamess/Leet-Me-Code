class Solution {
public:
    bool isValid(vector<vector<char>> board, int row, int col, char val){
        for(int i = 0; i<9; i++) if(board[row][i]==val) return false;
        for(int i = 0; i<9; i++) if(board[i][col]==val) return false;
        row = (row/3)*3, col = (col/3)*3;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(board[i][j]==val){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solveIt(vector<vector<char>>& board,int i, int j){
        if(i==9) return true;
        if(j==9) return solveIt(board,i+1,0);
        if(board[i][j]!='.') return solveIt(board,i,j+1);
        
        for(char c = '1'; c<='9'; c++){
            if(isValid(board,i,j,c)){
                board[i][j] = c;
                if (solveIt(board,i,j+1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solveIt(board,0,0);
    }
};