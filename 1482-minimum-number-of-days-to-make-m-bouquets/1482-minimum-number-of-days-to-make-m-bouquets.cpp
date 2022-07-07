class Solution {
public:
    bool checkValid(vector<int>& bloomDay, int x, int m, int k){
        int count = 0;
        int count1 = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=x) count++;
            else count = 0;
            if(count == k){
                count1++;
                count = 0;
            }
        }
        if(count1>=m) return true;
        else return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        vector<int> bloom = bloomDay;
        if(n<m*k) return -1;
        sort(bloomDay.begin(),bloomDay.end());
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l +(r-l)/2;
            if(checkValid(bloom,bloomDay[mid],m,k)){
                if(checkValid(bloom,bloomDay[mid]-1,m,k)){
                    r = mid - 1;
                }else{
                    return bloomDay[mid];
                }
            }else{
                l = mid + 1;
            }
        }
        
        return -1;
    }
};