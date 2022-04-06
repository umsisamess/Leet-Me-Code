class Solution {
public:
    int fact(int n){
        int ans = 1;
        while(n){
            ans *= n;
            n--;
        }
        return ans;
    }
    
    void getAllPermutations(string s, string& ans, unordered_map<char,bool>& visited, string str, int k, int& flag){
        if(flag==1){
            return;
        }
        if(s.length()==0){
            flag = 1;
            ans = str;
            return;
        }
        int n = s.length();
        int branches = fact(n-1);
        int pos = k/branches;
        int rem = k%branches;
        pos = rem>0?pos:pos-1;
        rem = rem!=0?rem:branches;
        if(pos<0){
            pos = 0;
        }
        string str1 = "";
        char ch;
        for(int i=0;i<s.length();i++){
            if(pos==i){
                ch = s[i];
                continue;
            }
            str1 += s[i];
        }
        getAllPermutations(str1,ans,visited,str+ch,rem,flag);
            
        
    }
    
    
    string getPermutation(int n, int k) {
        string ans;
        unordered_map<char,bool> visited;
        
        string s = "";
        for(int i=1;i<=n;i++){
            s += (i+'0');
        }
        
        int flag = 0;
        getAllPermutations(s,ans,visited,"",k,flag);
        
        return ans;
    }
};