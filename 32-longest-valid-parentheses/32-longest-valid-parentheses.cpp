class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        
        stack<int> st;
        
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                if(!st.empty()){
                    if(s[st.top()]=='(') st.pop();
                    else st.push(i);
                }else{
                    st.push(i);
                }
            }
        }
        
        int top = n;
        int ans = 0;
        while(top!=-1){
            if(st.empty()){
                ans = max(ans,top);
                break;
            }
            int x = st.top();
            ans = max(ans,top-x-1);
            st.pop();
            top = x;
        }

        return ans;
    }
};