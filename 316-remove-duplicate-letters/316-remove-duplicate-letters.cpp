class Solution {
public:
    
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> count;
        unordered_map<char,int> count1;
        int n = s.length();
        for(int i=0;i<n;i++){
            count[s[i]]++;
            // count1[s[i]]++;
        }
        
        stack<char> st;
        string ans = "";
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                count[s[i]]--;
                count1[s[i]] = 1;
            }
            else{
                if(count1[s[i]]==1){
                    count[s[i]]--;
                    continue;
                }
                while(!st.empty()){
                    cout<<s[i]<<" "<<st.top()<<"\n";
                    if(st.top()==s[i]){
                        count[s[i]]--;
                        break;
                    }
                    else if(st.top()<s[i]){
                        st.push(s[i]);
                        count[s[i]]--;
                        count1[s[i]] = 1;
                        break;
                    }
                    else{
                        if(count[st.top()]==0){
                            st.push(s[i]);
                            count[s[i]]--;
                            count1[s[i]] = 1;
                            break;
                        }
                        else{
                            count1[st.top()] = 0;
                            st.pop();
                            if(st.empty()){
                                st.push(s[i]);
                                count[s[i]]--;
                                count1[s[i]] = 1;
                                break;
                            }
                        }
                    }
                }
                
            }
        }

        while(!st.empty()){
            // cout<<st.top()<<" ";
            ans = st.top()+ans;
            st.pop();
        }
        cout<<"\n";
        return ans;
        
    }
};