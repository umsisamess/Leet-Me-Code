class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = n;
        
        for(int i=0;i<n;i++){
            int j=i-1;
            int k=i+1;
            while(j>=0 && k<n && s[j--]==s[k++]){
                ans++;
            }
            
            j = i;
            k = i+1;
            while(j>=0 && k<n && s[j--]==s[k++]){
                ans++;
            }
        }
        
        return ans;
    }
};