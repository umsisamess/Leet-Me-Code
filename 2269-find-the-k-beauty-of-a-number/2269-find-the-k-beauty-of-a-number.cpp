class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s1 = to_string(num);
        int count = 0;
        for(int i=0;i<s1.length()-k+1;i++){
            string s2 = s1.substr(i,k);
            int x = stoi(s2);
            if(x && num%x==0) count++;
        }
        return count;
    }
};