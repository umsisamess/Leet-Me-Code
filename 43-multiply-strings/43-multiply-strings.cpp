class Solution {
public:
    string product(int a, string nums,int zeros){
        string s = "";
        int prod,carry = 0;
        for(int j = nums.length()-1;j>=0;j--){
            int b = nums[j]-'0';
            prod = a*b;
            prod += carry;
            carry = prod/10;
            int rem = prod % 10;
            char r = '0'+rem;
            s = r+s;
        }
        if(carry>0){
            char c = '0'+carry;
            s = c+s;
        }
        for(int j=0;j<zeros;j++){
            s = s + '0';
        }
        return s;
    }
    
    string sum(string s1, string s2){
        if(s1==""){
            return s2;
        }
        int l1 = s1.length();
        int l2 = s2.length();
        if(l2>l1){
            for(int i=0;i<l2-l1;i++){
                s1 = "0"+s1;
            }
            l1 = l2;
        }
        else{
            for(int i=0;i<l1-l2;i++){
                s2 = "0"+s2;
            }
            l2 = l1;
        }
        
        int sum,carry = 0;
        string s = "";
        for(int i=l1-1;i>=0;i--){
            int a = s1[i]-'0';
            int b = s2[i]-'0';
            sum = a + b + carry;
            carry = sum/10;
            int rem = sum % 10;
            char r = '0'+rem;
            s = r+s;
        }
        if(carry>0){
            char c = '0'+carry;
            s = c+s;
        }
        
        return s;
    }
    
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        int l1 = num1.length();
        int a,b;
        int zeros = 0;
        string s1="",s2="";
        for(int i=l1-1;i>=0;i--){
            a = num1[i]-'0';
            cout<<a<<" ";
            s2 = product(a,num2,zeros);
            s1 = sum(s1,s2);
            zeros++;
        }
        
        return s1;
    }
};