class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        
        long int count = 0;
        for(int i=0;i<arr.size();i++){
            // if(i>0 && arr[i]==arr[i-1]) continue;
            int tgt = target - arr[i];
            int left = i+1;
            int right = arr.size()-1;
            
            while(left<right){
                int sum = arr[left] + arr[right];
                if(sum == tgt){
                    int count1 = 1, count2 = 1;
                    int leftVal = arr[left++];
                    int left1 = left;
                    while(left<arr.size() && arr[left] == leftVal && left<=right){
                        left++;
                        count1++;
                    }
                    int rightVal = arr[right--];
                    while(right>=0 && arr[right] == rightVal && right>=left1){
                        right--;
                        count2++;    
                    }
                    
                    if(rightVal==leftVal){
                        count += ((count1*(count1-1))/2);
                    }
                    else{
                       count += count1*count2; 
                    }
                    count %= 1000000007;
                }
                else if(sum > tgt){
                    right--;
                }
                else{
                    left++;
                }
            }
            
        }
        
        return (int)count;
    }
};