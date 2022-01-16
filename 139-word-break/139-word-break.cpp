class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> canbreak(s.size()+1);
        canbreak[0] = true;
        for(int i=1;i<=s.length();i++){
            for(int j=0;j<i;j++){
                if(canbreak[j] && find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()){
                    canbreak[i] = true;
                    break;
                }
            }
        }
        
        return canbreak[s.size()];
    }
};