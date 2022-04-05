class Solution {
public:
    bool isPalindrome(string str){
        int n = str.length();
        int left = 0, right = n-1;
        while(left<right){
            if(str[left]!=str[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    void partitionPalindromes(string& s, vector<vector<string>>& ans, vector<string> temp, int pos){
        if(pos == s.length()){
            ans.push_back(temp);
            return;
        }
        
        string str1 = "";
        for(int i=pos;i<s.length();i++){
            str1 += s[i];
            if(isPalindrome(str1)){
                temp.push_back(str1);
                partitionPalindromes(s,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        partitionPalindromes(s, ans, temp, 0);
        
        return ans;
    }
};