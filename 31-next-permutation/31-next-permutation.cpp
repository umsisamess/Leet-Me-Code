class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int point = -1;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                point = i;
            }
        }
        
        if(point==-1) sort(nums.begin(),nums.end());
        else{
            int mini = -1;
            for(int i=point+1;i<n;i++){
                if(nums[i]>nums[point]){
                    mini = mini==-1?i:nums[i]<nums[mini]?i:mini;
                }
            }
            swap(nums[point],nums[mini]);
            sort(nums.begin()+point+1,nums.end());
        }
        
    }
};