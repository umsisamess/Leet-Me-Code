class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum = 0,ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) sum--;
            else if(nums[i]==1) sum++;
            if(sum==0) ans = max(ans,i+1);
            else if(mp[sum]>0) ans = max(ans,i+1-mp[sum]);
            else mp[sum] = i+1;
        }
        return ans;
    }
};