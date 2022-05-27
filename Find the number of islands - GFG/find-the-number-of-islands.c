// { Driver Code Starts
// Initial Template for C

// Program to count islands in boolean 2D matrix
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define COL 501


 // } Driver Code Ends
// User function Template for C

void visitLand(int M[][COL], int n, int m, int x, int y){
    M[x][y] = 0;
    int dx[] = {0,0,1,1,1,-1,-1,-1};
    int dy[] = {1,-1,0,1,-1,0,1,-1};
    for(int i=0;i<8;i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && M[new_x][new_y]==1){
            visitLand(M, n, m, new_x, new_y);
        }
    }
}

int countIslands(int M[][COL], int n, int m) {
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]==1){
                visitLand(M, n, m, i, j);
                count++;
            }
        }
    }
    return count;
}


// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {

        int n, m;
        scanf("%d %d", &n, &m);

        int M[n][COL];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &M[i][j]);
            }
        }

        int ans = countIslands(M, n, m);
        printf("%d\n", ans);
    }

    return 0;
}
  // } Driver Code Ends