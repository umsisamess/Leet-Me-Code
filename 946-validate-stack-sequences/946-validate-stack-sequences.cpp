class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> st;
        int a = 0;
        for(int i=0;i<n;i++){
            st.push(pushed[i]);
            while(!st.empty() && st.top()==popped[a]){
                st.pop();
                a++;
            }
        }
        return st.empty();
    }
};