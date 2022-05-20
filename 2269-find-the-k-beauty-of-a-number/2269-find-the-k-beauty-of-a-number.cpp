class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int m = num;
        long int x = pow(10,k);
        int count = 0;
        while(m>x){
            int rem = m%x;
            if(rem && num%rem==0) count++;
            m /= 10;
        }
        if(num%m == 0){
            count++;
        }
        return count;
    }
};