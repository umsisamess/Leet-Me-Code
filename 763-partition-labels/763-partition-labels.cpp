class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> lastpos;
        for(int i=0;i<s.length();i++){
            lastpos[s[i]] = i; 
        }
        
        int ultlastpos = -1;
        int count = 0;
        vector<int> ans;
        for(int i=0;i<s.length();i++){
            count++;
            ultlastpos = max(ultlastpos,lastpos[s[i]]);
            if(ultlastpos==i){
                ans.push_back(count);
                count = 0;
                ultlastpos = -1;
            }
        }
        return ans;
    }
};