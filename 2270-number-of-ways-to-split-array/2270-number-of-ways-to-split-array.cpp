class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        //prefix and postfix sum
        int n = nums.size();
        vector<long int> presum(n);
        vector<long int> postsum(n);
        for(int i=0;i<n;i++){
            if(i==0) presum[i] = nums[i];
            else presum[i] = presum[i-1]+nums[i];
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1) postsum[i] = 0;
            else postsum[i] = postsum[i+1] + nums[i+1];
        }
        
        int count = 0;
        for(int i=0;i<n-1;i++){
            if(presum[i]>=postsum[i]){
                count++;
            }
        }
        return count;
    }
};