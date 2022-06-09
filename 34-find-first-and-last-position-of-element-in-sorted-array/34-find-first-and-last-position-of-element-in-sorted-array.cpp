class Solution {
public:
    int startSearch(vector<int>& nums, int target, int l, int r, int flag){
        while(l<=r){
            if(l==r) return l;
            int mid;
            if(flag) mid = ceil(l+ceil(1.0*(r-l)/2));
            else mid = l + (r-l)/2;
            if(nums[mid]==target){
                if(flag==0) return startSearch(nums,target,l,mid,0);
                else return startSearch(nums,target,mid,r,1);
            }
            else if(nums[mid]<target) l = mid+1;
            else r = mid - 1;
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target)
                return {startSearch(nums,target,left,mid,0),startSearch(nums,target,mid,right,1)};
            else if(nums[mid]<target) left = mid + 1;
            else right = mid-1;
        }
        
        return {-1,-1};
    }
};