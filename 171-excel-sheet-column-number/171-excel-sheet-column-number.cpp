class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length()-1;
        int sum = 0;
        for(auto i: columnTitle){
            sum += ((i-'A')+1)*pow(26,n);
            n--;
        }
        return sum;
    }
};