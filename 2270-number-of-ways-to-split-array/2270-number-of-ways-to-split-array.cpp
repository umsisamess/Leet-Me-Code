class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        //prefix and postfix sum
        int n = nums.size();
        long int backsum = 0, frontsum = 0;
        for(int i=0;i<n;i++){
            backsum += nums[i];
        }
        int count = 0;
        for(int i=0;i<n-1;i++){
            frontsum += nums[i];
            backsum -= nums[i];
            if(frontsum>=backsum) count++;
        }
        return count;
    }
};