class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> digits{1,2,3,4,5,6,7,8,9};
        vector<int> ans;
        for(int i=0;i<digits.size();i++){
            if(digits[i]>=low && digits[i]<=high) ans.push_back(digits[i]);
            else if(digits[i]>high) break;
            if(digits[i]%10!=9) digits.push_back(digits[i]*10+((digits[i]%10)+1));
        }
        return ans;
    }
};