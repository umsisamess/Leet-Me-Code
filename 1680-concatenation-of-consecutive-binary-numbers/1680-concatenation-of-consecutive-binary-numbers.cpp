class Solution {
public:
    int concatenatedBinary(int n) {
        int a = 1;
        long long int ans = 0;
        for(int i=1;i<=n;i++){
            if(i==pow(2,a)){
                a = a + 1;
            }
            ans = (ans*pow(2,a) + i);
            ans %= 1000000007;
        }
        return ans;
    }
};