class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return 0;
        }
        int prev_diff = nums[1]-nums[0];
        int count = 1;
        int totalSlices = 0;
        for(int i=2;i<n;i++){
            int diff = nums[i]-nums[i-1];
            if(diff==prev_diff){
                count += 1;
            }
            else{
                if(count>=2){
                    for(int k=1;k<=count-1;k++){
                        totalSlices += k;
                    }
                }
                prev_diff = diff;
                count = 1;
            }    
        }
        if(count>=2){
            for(int k=1;k<=count-1;k++){
                totalSlices += k;
            }
        }
        return totalSlices;
    }
};