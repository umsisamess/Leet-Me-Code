class Trie{
    bool isEnd;
    Trie *children[2];
    public:
    Trie(){
        this->isEnd = false;
        for(int i=0;i<2;i++){
            this->children[i] = nullptr;
        }
    }

    void insert(int num){
        Trie *curr = this;
        string str = "";
        
        while(str.length()!=32){
            if(num%2==0){
                str += "0";
            }else{
                str += "1";
            }
            num = num>>1;
        }
        reverse(str.begin(),str.end());

        for(int i=0;i<str.length();i++){
            int ch = str[i]-'0';
            if(curr->children[ch]==nullptr){
                curr->children[ch] = new Trie();
            }
            curr = curr->children[ch];
        }
        curr->isEnd = true;
    }

    int operate(int num){
        Trie *curr = this;
        // if(curr==nullptr){
        //     return -1;
        // }
        string str = "";
        
        while(str.length()!=32){
            if(num%2==0){
                str += "0";
            }else{
                str += "1";
            }
            num = num>>1;
        }
        reverse(str.begin(),str.end());
        string ans = "";
        for(int i=0;i<str.length();i++){
            int ch = str[i]-'0';
            ch = ch==0?1:0;
           if(curr->children[ch]!=nullptr){
                curr = curr->children[ch];
                ans += "1";
           }else{
               ch = ch==0?1:0;
               ans += "0";
               curr = curr->children[ch];
           }
        }
        int a = 31;
        int ans1 = 0;
        for(int i=0;i<ans.length();i++){
            if(ans[i]=='1'){
                ans1 += pow(2,a);
            }
            a--;
        }
        return ans1;
    }
};

class Solution {
public:
    bool static comp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),comp);
        Trie* obj = new Trie();
        int pos = 0;
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            while(pos<nums.size() && nums[pos]<=queries[i][1]){
                obj->insert(nums[pos++]);
            }
            if(pos==0) ans[queries[i][2]] = -1;
            else ans[queries[i][2]]= obj->operate(queries[i][0]);
        }
        return ans;
    }
};