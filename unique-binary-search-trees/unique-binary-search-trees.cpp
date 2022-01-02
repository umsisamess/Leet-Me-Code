class Solution {
public:
    int numTrees(int n) {
        vector<int> uniques(n+1,0);
        uniques[0] = 1;
        uniques[1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                uniques[i] += uniques[j-1]*uniques[i-j];
            }
        }
        return uniques[n];
    }
};