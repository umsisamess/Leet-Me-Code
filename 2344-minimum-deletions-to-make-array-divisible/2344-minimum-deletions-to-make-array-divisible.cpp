class Solution {
public:
    void factors(vector<int>& facts, int hcf){
        for(int i=1;i<=hcf;i++){
            if(hcf%i==0) facts.push_back(i);
        }
    }
    
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int hcf = numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            if(hcf==1) break;
            hcf = __gcd(hcf,numsDivide[i]);
        }
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i==1 && nums[i]==nums[i-1]) continue;
            if(hcf%nums[i]==0) return i;
        }
        return -1;
        
    }
};