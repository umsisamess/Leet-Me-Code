class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string ans = "";
        int firstdiff = 2*(numRows-1),seconddiff = 0;
        for(int i=0;i<numRows;i++){
            if (i<s.length()) ans += s[i];
            else break;
            int j = i;
            while(j<s.length()){
                if(firstdiff && j+firstdiff<s.length()){
                    ans += s[j+firstdiff];
                }
                j += firstdiff;
                if(seconddiff && j+seconddiff<s.length()){
                    ans += s[j+seconddiff];
                }
                j += seconddiff;
            }
            firstdiff -= 2;
            seconddiff +=2;
        }
        
        return ans;
    }
};