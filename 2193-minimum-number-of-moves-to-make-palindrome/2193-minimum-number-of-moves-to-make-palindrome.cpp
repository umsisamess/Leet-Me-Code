class Solution {
public:
    void swapp(string& s, int j, int x, int& ans, char c){
        for(int i=j+1;i<=x;i++){
            s[i-1] = s[i];
        }
        s[x] = c;
        ans += x-j;
    }
    
    int minMovesToMakePalindrome(string s) {
        int ans = 0;
        int n = s.length();
        int single = -1;
        int pos;
        for(int i=0; i<n/2; i++){
            char c = s[i];
            int flag = 0;
            if(single==-1) pos = n-i-1;
            else pos = n - i;
            for(int j=pos;j>i;j--){
                if(s[j]==c){
                    flag = 1;
                    swapp(s,j,pos,ans,c);
                    break;
                }
            }
            if(flag==0){
                single = i;
            }
        }
        if(single!=-1){
            swapp(s,min(single,(n+1)/2-1),max(single,(n+1)/2-1),ans,s[single]);
        }
        
        return ans;
    }
};