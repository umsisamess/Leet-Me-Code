class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.length()<26) return false;
        unordered_map<char,int> count;
        for(auto i:sentence){
            count[i]++;
        }
        string alpha="abcdefghijklmnopqrstuvwxyz";
        for(auto i:alpha){
            if(!count[i]){
                return false;
            }
        }
        return true;
    }
};