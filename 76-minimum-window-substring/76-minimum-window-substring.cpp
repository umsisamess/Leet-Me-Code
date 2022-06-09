class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        // if(s==t) return s;
        unordered_map<char,int> count1;
        unordered_map<char,int> count2;
        unordered_map<char,int> count3;
        
        int totalCount = 0;
        for(int i=0;i<n;i++){
            totalCount++;
            count3[t[i]]++;
            count2[t[i]]++;
        }
        
        int pos = -1;
        string ans = "";
        for(int i=0;i<m;i++){
            ans += s[i];
            if(count2[s[i]]) count1[s[i]]++;
            if(count3[s[i]]){
                count3[s[i]]--;
                totalCount--;
            }
            if(totalCount==0){
                pos = i;
                break;
            }
        }
        if(pos==-1) return "";
        vector<int> res(2);
        res[0] = 0;
        res[1] = pos;
        int left = 0, right = pos;
        
        int prevleft = 0;
        while(right<m){
            if(res[1]-res[0]>right-left){
                res[0] = left;
                res[1] = right;
            }
            left += 1;
            if(count2[s[left-1]]){
                count1[s[left-1]]--;
                if(count1[s[left-1]]<count2[s[left-1]]){
                    int flag = 0;
                    for(int i=right+1;i<m;i++){
                        if(count2[s[i]]) count1[s[i]]++;
                        if(s[i]==s[left-1]){
                            flag = 1;
                            right = i;
                            break;
                        }
                    }
                    if(flag==0) break;
                }
            }
        }
        string result = "";
        cout<<res[0]<<" "<<res[1]<<" ";
        for(int i=res[0];i<=res[1];i++){
            result += s[i];
        }
        return result;
    }
};