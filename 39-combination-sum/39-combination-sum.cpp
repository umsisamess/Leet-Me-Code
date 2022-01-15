class Solution {
public:
    void findTheCombinations(vector<int>& candidates, int target,int pos, vector<vector<int>>& combinations,vector<int> temp){
        if(target<0) return;
        if(target==0){
            combinations.push_back(temp);
            return;
        }
        for(int i=pos;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            findTheCombinations(candidates,target-candidates[i],i,combinations,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> combinations;
        vector<int> temp;
        findTheCombinations(candidates,target,0,combinations,temp);
        return combinations;
    }
};