class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l=-1,r=-1;
        int start = 0,end=0;
        for(int i=1;i<nums.size();i++){
            if(start){
                if(nums[i]<nums[start]) start = i;
            }
            else{ 
                if(nums[i]<nums[i-1]) start = i;
            }
        }
        
        if(start==0) return 0;
        
        for(int i=nums.size()-2;i>=0;i--){
            if(end){
                if(nums[i]>nums[end]) end = i;
            }
            else{
                if(nums[i]>nums[i+1]) end = i;
            }
        }
        cout<<start<<" "<<end<<" ";
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[start]){
                l = i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<nums[end]){
                r = i;
                break;
            }
        }
        return r-l+1;
        
    }
};