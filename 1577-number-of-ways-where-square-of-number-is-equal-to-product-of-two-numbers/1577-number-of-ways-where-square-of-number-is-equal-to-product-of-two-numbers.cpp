class Solution {
public:
    void converttoset(vector<int>& nums, set<int>& s, unordered_map<int,int>& count){
        for(auto i:nums){
            s.insert(i);
            count[i]++;
        }
    }
    
    void converttovector(vector<int>& nums, set<int>&s){
        for(auto i:s){
            nums.push_back(i);
        }
    }
    
    void findSum(vector<int>& nums1, vector<int>& nums2, unordered_map<int,int>& count1, unordered_map<int,int>& count2, long int& sum){
        for(int i=0;i<nums1.size();i++){
            long int a = pow(nums1[i],2);
            int start = 0,end = nums2.size()-1;
            while(start<=end){
                long int b = nums2[start];
                b *= nums2[end];
                if(b==a){
                    if(start==end){
                        sum += count1[nums1[i]]*((count2[nums2[start]]*(count2[nums2[start]]-1)))/2;
                    }
                    else{
                        sum += count1[nums1[i]]*count2[nums2[start]]*count2[nums2[end]];
                    }
                    start++;
                    end--;
                }
                else if(b>a){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
    }
    
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;
        unordered_map<int,int> count1;
        unordered_map<int,int> count2;
        
        converttoset(nums1,s1,count1);
        converttoset(nums2,s2,count2);
        nums1.clear();
        nums2.clear();
        converttovector(nums1,s1);
        converttovector(nums2,s2);
        s1.clear();
        s2.clear();
        
        long int sum = 0;
        findSum(nums1,nums2,count1,count2,sum);
        findSum(nums2,nums1,count2,count1,sum);
        
        return sum;
        
    }
};