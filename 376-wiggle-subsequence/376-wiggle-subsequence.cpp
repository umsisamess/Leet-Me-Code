class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 0;
        int flag = 0;
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) continue;
            if(flag==0){
                if(nums[i]>nums[i-1]) flag = 1;
                else flag = 2;
                count += 1;
            }else if(flag==1){
                if(nums[i]<nums[i-1]){
                    count += 1;
                    flag = 2;
                } 
            }else if(flag==2){
                if(nums[i]>nums[i-1]) {
                    count += 1;
                    flag = 1;
                }
            }
        }
        return count;
    }
};