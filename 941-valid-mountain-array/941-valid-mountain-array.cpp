class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int increasing = 0;
        if(arr.size()<3) return false;
        for(int i = 1;i<arr.size();i++){
            if(arr[i]==arr[i-1]) return false;
            else if(arr[i]>arr[i-1]){
                if(increasing==-1) return false;
                else increasing = 1;
            }
            else{
                if(increasing==0) return false;
                else increasing = -1;
            }
        }
        if(increasing==-1) return true;
        return false;
    }
};