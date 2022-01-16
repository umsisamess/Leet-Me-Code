class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<string> v2 = strs;
        for(auto str:strs){
            string temp = str;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(str);
        }
        vector<vector<string>> anagrams;
        for(auto i:mp){
            anagrams.push_back(i.second);
        }
        return anagrams;
    }
};