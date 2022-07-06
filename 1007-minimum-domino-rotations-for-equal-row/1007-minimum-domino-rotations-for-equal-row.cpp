class Solution {
public:
    bool count(vector<int>& tops, vector<int>& bottoms, int x){
        for(int i=0;i<tops.size();i++){
            if(x!=tops[i] && x!= bottoms[i]) return false;
        }
        return true;
    }
    
    int sidecount(vector<int>& v, int x){
        int count = 0;
        for(int i=0;i<v.size();i++){
            if(x==v[i]) count++;
        }
        return count;
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int a = tops[0];
        int b = bottoms[0];
        int n = tops.size();
        int mini = n+1;
        if(count(tops,bottoms,a)){
            mini = min(mini,n-sidecount(tops,a));
            mini = min(mini,n-sidecount(bottoms,a));
        }
        if(count(tops,bottoms,b)){
            mini = min(mini,n-sidecount(tops,b));
            mini = min(mini,n-sidecount(bottoms,b));
        }
        return mini==n+1?-1:mini;
    }
};