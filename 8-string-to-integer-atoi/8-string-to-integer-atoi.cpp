class Solution {
public:
    int myAtoi(string s) {
        bool sign = true;
        int ans = 0,i=0,n = s.length();
        
        while(s[i]==' ' && i<n) i++;
        
        if(s[i]=='+'){
            sign = true;
            i++;
        }
        else if(s[i]=='-'){
            sign = false;
            i++;
        }
        
        while(s[i]>='0' && s[i]<='9'){
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && s[i]>'7')){
                return sign?INT_MAX:INT_MIN;
            }
            ans = ans*10+(s[i]-'0');
            i++;
        }
        return sign?ans:-ans;
    }
};