class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long int sum, ans = INT_MAX;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        sum = nums[0];
        vector<long long int> pre(n);
        for(int i=1;i<n;i++){
            sum += nums[i];
            pre[i] = pre[i-1] + nums[i-1];
        }
        
        cout<<pre[0]<<" "<<sum<<" ";
        for(long int i=0;i<n;i++){
            ans = min(ans,(nums[i]*i-pre[i])+(sum-pre[i]-(nums[i]*(n-i))));
        }
        
        return (int)ans;
    }
};