class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = nums[0];
        for(int i=0;i<nums.size();i++){
            if(i>maxi) return false;
            if(maxi<i+nums[i]){
                maxi = i+nums[i];
            }
            if(maxi>=nums.size()-1) return true;
        }
        return false;
    }
};