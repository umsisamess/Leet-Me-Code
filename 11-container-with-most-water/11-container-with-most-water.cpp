class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int leftpos = 0;
        int rightpos = n-1;
        
        int ans = 0;
        
        while(leftpos<rightpos){
            ans = max(ans,min(height[leftpos],height[rightpos])*(rightpos-leftpos));
            if(height[leftpos]<height[rightpos]){
                leftpos++;
            }
            else if(height[rightpos]<height[leftpos]){
                rightpos--;
            }
            else{
                leftpos++;
                rightpos--;
            }
        }
        
        return ans;
    }
};