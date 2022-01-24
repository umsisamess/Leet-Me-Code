class Solution {
public:
    bool detectCapitalUse(string word) {
        string str1 = word;
        int capital;
        if(word[0]>='A' && word[0]<='Z') capital = 1;
        else capital = 0;
        for(int i=1;i<word.size();i++){
            if(word[i]>='A' && word[i]<='Z'){
                if(capital>0) capital++;
                else return false;
            }
            else{
                if(capital==1) capital = 0;
                else if(capital>0) return false;
                else continue;
            }
        }
        return true;
    }
};