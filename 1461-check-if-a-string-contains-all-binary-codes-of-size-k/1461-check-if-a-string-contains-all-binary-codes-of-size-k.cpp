class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int num = 0;
        set<int> st;
        if(k>s.length()) return false;
        for(int i=0;i<k;i++){
            num = num*2+(s[i]-'0');
        }
        st.insert(num);

        int n = s.length();
        for(int i=k;i<n;i++){
            num = (num-(pow(2,k-1)*(s[i-k]-'0')))*2+(s[i]-'0');
            st.insert(num);
        }
        
        if(st.size()==pow(2,k)){
            return true;
        }
        return false;
    }
};