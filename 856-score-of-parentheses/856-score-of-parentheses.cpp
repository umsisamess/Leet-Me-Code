class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int n = s.length();
        int level = 0;
        int prevpoppedlevel = -1;
        vector<int> prevpoppedans(n+1,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(++level);
            }
            else{
                if(prevpoppedlevel==-1){
                    ans += 1;
                    prevpoppedans[level] = ans;
                }
                else{
                    cout<<prevpoppedlevel<<" "<<level<<"\n";
                    if(prevpoppedlevel==level){
                        ans += 1;
                        prevpoppedans[level] += 1;
                    }
                    else if(prevpoppedlevel>level){
                        ans += prevpoppedans[prevpoppedlevel];
                        prevpoppedans[level] += 2*prevpoppedans[prevpoppedlevel];
                        prevpoppedans[prevpoppedlevel] = 0;
                    }
                    else{
                        ans += 1;
                        prevpoppedans[level] = 1;
                    }
                }
                prevpoppedlevel = level;
                --level;
            }
        }
        cout<<"\n";
        return ans;
    }
};