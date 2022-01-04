class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        int sum = 0;
        int s = 0;
        while(n){
            int count = !(n&1);
            sum += count*pow(2,s);
            s++;
            n >>= 1;
        }
        return sum;
    }
};