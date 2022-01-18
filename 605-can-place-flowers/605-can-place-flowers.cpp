class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0;
        int count = 0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
                if(i==1 && count==1){
                    ans += 1;
                    count--;
                }
                count++;
            }
            else{
                count = 0;
            }
            if(count==3){
                ans += 1;
                count = 1;
            }
        }
        if(count==2 || (count==1 && flowerbed.size()==1)){
            ans += 1;
        }
        
        return ans>=n?true:false;
        
    }
};