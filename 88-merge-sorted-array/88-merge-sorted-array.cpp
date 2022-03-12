class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n;
        while(m>0 && n>0){
            if(nums1[m-1]>nums2[n-1]){
                nums1[pos-1] = nums1[m-1];
                m--;
                pos--;
            }
            else{
                nums1[pos-1] = nums2[n-1];
                n--;
                pos--;
            }
        }
        
        while(m){
            nums1[pos-1] = nums1[m-1];
            pos--;
            m--;
        }
        while(n){
            nums1[pos-1] = nums2[n-1];
            pos--;
            n--;
        }
        
    }
};