class Solution {
public:
    int longestSubsequence(string s, int k) {
        vector<int> onepos;
        long int ans = 0;
        int count = 0;
        int maxcount = 0;
        int p = 0;
        for(int i=0;i<s.length();i++){
            ans = ans*2 + (s[i]-'0');
            int m = onepos.size();
            if(s[i]=='1') onepos.push_back(i-m);
            if(ans<=k) count++;
            else{
                ans -= pow(2,(count-onepos[p++]));
            }
            maxcount = max(maxcount,count);
        }
        return maxcount;
    }
};