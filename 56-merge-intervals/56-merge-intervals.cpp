class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        
        sort(intervals.begin(),intervals.end());
        
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end1){
                end1 = max(end1,intervals[i][1]);
            }
            else{
                ans.push_back({start1,end1});
                start1 = intervals[i][0];
                end1 = intervals[i][1];
            }
        }
        ans.push_back({start1,end1});
        return ans;
    }
};