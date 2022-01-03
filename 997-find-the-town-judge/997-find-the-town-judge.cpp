class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> liked;
        unordered_map<int,int> liker;
        
        int m = trust.size();
        for(int i=0;i<m;i++){
            liked[trust[i][1]]++;
            liker[trust[i][0]]++;
        }
        
        int judge = -1;
        for(int i=1;i<n+1;i++){
            if(liked[i]==n-1 && liker[i]==0){
                judge = i;
            }
        }
        return judge;
    }
};