class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int> mp;
        for(auto i:dictionary){
            mp[i]++;
        }
        string ans = "";
        string str = "";
        bool done = false;
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]==' ' ){
                if(!done) ans+=str;
                ans +=" ";
                str = "";
                done = false;
            }
            else{
                str += sentence[i];
                if(i==sentence.length()-1){
                    if(!done){
                        ans += str;
                        break;
                    }
                }
                if(!done && mp[str]){
                    ans += str;
                    done = true;
                }
            }
        }
        return ans;
    }
};