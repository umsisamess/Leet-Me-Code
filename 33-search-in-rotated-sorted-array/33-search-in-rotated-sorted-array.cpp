class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            int x = nums[mid];
            if(x == target){
                return mid;
            }
            else{
                if(x>=nums[left]){
                    if(target>=nums[left] && target<x) right = mid - 1;
                    else if(target>=nums[left] && target>x) left = mid + 1;
                    else if(target<nums[left]) left = mid + 1;
                }else{
                    if(target<x) right = mid - 1;
                    else if(target>x && target>=nums[left]) right = mid - 1;
                    else if(target>x && target<nums[left]) left = mid + 1;
                }
            }
        }

        return -1;
    }
};