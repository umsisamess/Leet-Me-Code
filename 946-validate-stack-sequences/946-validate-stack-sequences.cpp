class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i=0,j=0;
        for(auto a:pushed){
            pushed[i++] = a;
            while(i>0 && pushed[i-1]==popped[j]){
                i--;
                j++;
            }
        }
        return i==0;
    }
};