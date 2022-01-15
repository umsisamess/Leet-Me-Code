class Solution {
public:
    void findTheCombinations(vector<int>& candidates, int target,int pos, vector<vector<int>>& combinations,vector<int> temp){
        if(target<0) return;
        if(target==0){
            combinations.push_back(temp);
            return;
        }
        for(int i=pos;i<candidates.size();i++){
            if(i && candidates[i]==candidates[i-1] && i>pos) continue;
            temp.push_back(candidates[i]);
            findTheCombinations(candidates,target-candidates[i],i+1,combinations,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> combinations;
        vector<int> temp;
        findTheCombinations(candidates,target,0,combinations,temp);
        return combinations;
    }
};