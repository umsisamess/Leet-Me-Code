class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> mpLeft;
        unordered_map<char,int> mpRight;
        int n = s.length();
        int countLeft = 0, countRight = 0, goodSplitCount;
        if(n==1){
            return 0;
        }
        for(int i = 0; i<n; i++){
            if(mpRight[s[i]]==0){
                countRight += 1;
            }
            mpRight[s[i]]++;
        }
        for(int i=0;i<n-1;i++){
            if(mpLeft[s[i]]==0){
                countLeft += 1;
            }
            mpLeft[s[i]]++;
            mpRight[s[i]]--;
            if(mpRight[s[i]]==0){
                countRight -= 1;
            }
            if(countLeft==countRight){
                goodSplitCount += 1;
            }
        }
        
        return goodSplitCount;
        
    }
};