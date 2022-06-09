class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++) mp[words[i]] = i+1;
        
        unordered_map<int,int> mp2;
        for(int i=0;i<words.size();i++){
            mp2[mp[words[i]]]++;
        }
        
        int k = words[0].length();
        vector<int> v(s.length()-k+1);
        
        for(int i=0;i<s.length()-k+1;i++){
            string s1 = s.substr(i,k);
            v[i] = mp[s1];
        }
        
        vector<int> ans;
        
        for(int i=0;i<s.length()-words.size()*k+1;i++){
            unordered_map<int,int> mp1;
            for(int j=i;j<i+words.size()*k;j=j+k){
                if(v[j]==0) break;
                mp1[v[j]]++;
            }
            int flag = 0;
            for(int j=0;j<=words.size();j++){
                if(mp1[j]!=mp2[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag==0) ans.push_back(i);
            else continue;
        }
        
        return ans;
    }
};