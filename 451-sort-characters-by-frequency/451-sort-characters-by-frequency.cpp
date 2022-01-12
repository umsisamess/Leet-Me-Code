class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        vector<string> v(s.size(),"");
        for(auto& i:mp){
            v[i.second-1].append(i.second,i.first);
        }
        string ans = "";
        for(int i=s.size()-1;i>=0;i--){
            ans += v[i];
        }
        return ans;
    }
};