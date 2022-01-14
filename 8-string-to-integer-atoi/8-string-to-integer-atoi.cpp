class Solution {
public:
    int myAtoi(string s) {
        bool sign = true;
        long ans = 0;
        bool characterRead = false;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9'){
                ans = ans*10+(s[i]-'0');
                if(sign==false && ans>=pow(2,31)){
                    return INT_MIN;
                }
                else if(sign==true && ans>INT_MAX){
                    return INT_MAX;
                }
            }
            else if(s[i]==' '){
                if(characterRead) break;
            }
            else if(s[i]=='+'){
                if(characterRead) break;
                sign = true;
            }
            else if(s[i]=='-'){
                if(characterRead) break;
                sign = false;
            }
            else{
                break;
            }
            
            if(s[i]!=' ') characterRead = true;
        }
        return sign?ans:-ans;
    }
};