class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> mp;
        unordered_map<char,int> taken;
        string str = "";
        int a = 0;
        for(int i = 0;i < s.length();i++){
            if(s[i]==' '){
                if(mp[str]>='a' && mp[str]!=pattern[a]){
                    return false;
                }
                else if(mp[str]<'a' && taken[pattern[a]]){
                    return false;
                }
                mp[str] = pattern[a];
                taken[pattern[a]] = 1;
                a++;
                str = "";
            }
            else{
                str += s[i];
            }
        }
        cout<<mp[str]<<" ";
        if(mp[str]>='a' && mp[str]!=pattern[a]){
            return false;
        }
        else if(mp[str]<'a' && taken[pattern[a]]){
            return false;
        }
        mp[str] = pattern[a];
        if(a<pattern.length()-1){
            return false;
        }
        return true;
        
    }
};