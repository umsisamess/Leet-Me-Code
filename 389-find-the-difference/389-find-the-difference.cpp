class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = 0;
        for(int i:s){
            n ^= i;
        }
        
        for(int i:t){
            n ^= i;
        }
        
        return (char)n;
    }
};