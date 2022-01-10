class Solution {
public:
    string addBinary(string a, string b) {
        int l1 = a.length();
        int l2 = b.length();
        if(l1>l2){
            for(int i=0;i<l1-l2;i++){
                b = '0'+b;
            }
            l2 = l1;
        }
        else{
            for(int i=0;i<l2-l1;i++){
                a = '0'+a;
            }
            l1 = l2;
        }
        
        int carry = 0;
        string res = "";
        for(int i=l1-1;i>=0;i--){
            int n1 = a[i]-'0';
            int n2 = b[i]-'0';
            int sum = carry ^ (n1 ^ n2);
            carry = (n1&n2)|(n2&carry)|(n1&carry);
            if(sum==1){
                res = '1'+res;
            }
            else{
                res = '0'+res;
            }
        }
        if(carry==1){
            res = '1'+res;
        }
        return res;
    }
};