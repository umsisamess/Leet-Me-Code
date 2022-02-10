class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i;
        
        unordered_map<int,int> mp;
        int sum = 0;
        int count = 0;
        for(i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum==k){
                count+=1;
            }
            count += mp[sum-k];
            mp[sum]++;
        }
        
        return count;
    }
};