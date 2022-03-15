class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int popable = 0;
        stack<int> st;
        unordered_map<int,int> remove;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
                popable++;
            }
            else if(s[i]==')'){
                if(popable){
                    st.pop();
                    popable--;
                }
                else{
                    remove[i] = 1;
                }
            }
        }
        while(!st.empty()){
            remove[st.top()] = 1;
            st.pop();
        }
        
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(remove[i]) continue;
            ans += s[i];
        }
        
        return ans;
    }
};