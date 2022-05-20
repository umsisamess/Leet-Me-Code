class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res = 0;
        int n = candidates.size();
        int maxipos = max_element(candidates.begin(),candidates.end())-candidates.begin();
        while(candidates[maxipos]){
            int count = 0;
            for(int i=0;i<n;i++){
                int a = candidates[i]&1;
                if(a==1) count++;
                candidates[i] = candidates[i]>>1;
            }
            res = max(count,res);
        }
        return res;
    }
};