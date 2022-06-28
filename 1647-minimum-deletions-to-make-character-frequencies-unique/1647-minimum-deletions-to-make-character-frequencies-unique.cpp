class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        for(auto a:s){
            mp[a]++;
        }
        unordered_map<int,int> count;
        for(int i=0;i<26;i++){
            count[mp['a'+i]]++;
        }
        
        int ans = 0;
        for(int i=s.length();i>0;i--){
            if(count[i]==0 || count[i]==1){
                continue;
            }else{
                ans += count[i]-1;
                count[i-1] += count[i]-1;
            }
        }
        return ans;
    }
};