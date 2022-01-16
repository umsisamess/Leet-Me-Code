class Solution {
public:
    bool checkPalindrome(string str){
        for(int i=0;i<str.length()/2;i++) if(str[i]!=str[str.length()-i-1]) return false;
        return true;
    }
    
    bool isPalindrome(string s) {
        string str = "";
        for(auto i:s) if((i>='a' && i<='z')||(i>='A' && i<='Z') || (i>='0' && i<='9')) str += tolower(i);
        cout<<str;
        return checkPalindrome(str);
    }
};