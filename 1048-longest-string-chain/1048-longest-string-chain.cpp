class Solution {
public:
    static bool comp(string a, string b){
        return a.length()<b.length();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        sort(words.begin(),words.end(),comp);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            int res = 1;
            string temp = "";
            int m = words[i].length();
            for(int j=0;j<m;j++){
                temp = words[i].substr(0,j)+words[i].substr(j+1,m-j);
                res = max(res,mp[temp]+1);
            }
            mp[words[i]] = res;
            ans = max(ans,res);
        }
        return ans;
        
    }
};